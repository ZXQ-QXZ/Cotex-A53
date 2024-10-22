#include "bmp.h"
#include "openfb0.h"
#include "draw.h"
#include "font.h"


char *File_data(FILE *file, int *a, int *b)
{
    struct bitmap_header file_header; // 文件头
    struct bitmap_info info_header;   // 信息头
    fread(&file_header, sizeof file_header, 1, file);
    fread(&info_header, sizeof info_header, 1, file);
    // printf("bmp文件大小:%d\n", file_header.size);
    // printf("bmp图像宽度:%d\n", info_header.width);
    // printf("bmp图像高度:%d\n", info_header.height);
    // printf("bmp图像色深:%d\n", info_header.bit_count);
    // printf("bmp图像数据大小:%d\n", info_header.size_img);
    // 判断宽高是否正确如果不正确将宽高修改正确后将宽和高传回
    Width_height(a, b, info_header.width, info_header.height);
    char *file_data = calloc(1, info_header.size_img);
    fread(file_data, info_header.size_img, 1, file);
    fclose(file);
    return file_data;
}

void File_draw(FILE *file, int x, int y)
{
    if (file)
    {
        // 文件数据获取
        int width, height;                                  // 文件的宽高
        char *file_data = File_data(file, &width, &height); // 文件的数据内容
        // lcd屏幕初始化
        struct lcd mylcd;
        if (LCD_Init(&mylcd))
        {
            int color;
            // 数据写入
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    color = file_data[((height - j - 1) * width + i) * 3] |
                            file_data[((height - j - 1) * width + i) * 3 + 1] << 8 |
                            file_data[((height - j - 1) * width + i) * 3 + 2] << 16 |
                            0x00 << 24;
                    Draw_point(mylcd, color, i + x, j + y);
                }
            }
            // 关闭数据
            LCD_Destory(mylcd);
        }
    }
}

// 判断宽高是否为4的倍数
void Width_height(int *a, int *b, int width, int height)
{
    if (width % 4 == 0 && height % 4 == 0)
    {
        *a = width;
        *b = height;
    }
    else if (width % 4 != 0)
    {
        *a = width + (4 - (width % 4));
        *b = height;
    }
    else if (height % 4 != 0)
    {
        *a = width;
        *b = height + (4 - (height % 4));
    }
    else
    {
        *a = width + (4 - (width % 4));
        *b = height + (4 - (height % 4));
    }
}

