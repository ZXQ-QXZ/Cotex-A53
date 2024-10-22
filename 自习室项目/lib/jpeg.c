#include "jpeg.h"
#include "openfb0.h"
#include "draw.h"

void Jpeg_file(const char *filename, struct jpeg_data *jpegdata)
{
    struct jpeg_decompress_struct cinfo;    // JPEG解压缩结构体
    struct jpeg_error_mgr jerr;             // JPEG出错结构体
    cinfo.err = jpeg_std_error(&jerr);      // 初始化出错对象
    jpeg_create_decompress(&cinfo);         // 初始化解压对象

    FILE *infile;
    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "can't open %s: %s\n", filename, strerror(errno));
        exit(1);
    }
    jpeg_stdio_src(&cinfo, infile);   // 加载JPEG数据源

    if (jpeg_read_header(&cinfo, TRUE) != JPEG_HEADER_OK) { // 获取JPEG图像信息
        fprintf(stderr, "read jpeg header fail\n");
        fclose(infile);
        jpeg_destroy_decompress(&cinfo);
        exit(1);
    }

    jpeg_start_decompress(&cinfo);    // 开始解压

    jpegdata->width = cinfo.output_width;
    jpegdata->height = cinfo.output_height;
    jpegdata->line = cinfo.output_width * cinfo.output_components;
    jpegdata->color_type = cinfo.output_components;
    jpegdata->scanline = cinfo.output_scanline;

    // 申请数据缓冲区
    int buf_size = jpegdata->width * jpegdata->height * jpegdata->color_type;
    jpegdata->file = (unsigned char *)calloc(1, buf_size);
    if (jpegdata->file == NULL) {
        fprintf(stderr, "can't allocate memory\n");
        fclose(infile);
        jpeg_destroy_decompress(&cinfo);
        exit(1);
    }

    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer_array[1];
        buffer_array[0] = jpegdata->file + cinfo.output_scanline * jpegdata->line;
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
    }

    jpeg_finish_decompress(&cinfo);   // 完成解压缩
    jpeg_destroy_decompress(&cinfo);  // 销毁解码对象
    fclose(infile);                   // 关闭文件
}

void Jpeg_draw(struct jpeg_data jpegdata)
{
    struct lcd lcd;
    if (LCD_Init(&lcd)) {
        // 显示
        int color = 0;
        // 画图像
        for (int i = 0; i < jpegdata.height; i++) {
            for (int j = 0; j < jpegdata.width; j++) {
                color = jpegdata.file[(i * jpegdata.width + j) * 3] << 16 |    // r
                        jpegdata.file[(i * jpegdata.width + j) * 3 + 1] << 8 | // g
                        jpegdata.file[(i * jpegdata.width + j) * 3 + 2];       // b
                Draw_point(lcd, color, j, i);
            }
        }
    }
}
