#ifndef __JPEG_H__
#define __JPEG_H__

#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <errno.h>
#include <string.h>

struct jpeg_data {
    int width;          // 宽度
    int height;         // 高度
    int line;           // 每行数据长度
    int color_type;     // 色彩类型
    int scanline;       // 当前扫描行
    unsigned char *file; // 数据
};

extern void Jpeg_file(const char *filename, struct jpeg_data *jpegdata); // 获取JPEG文件信息
extern void Jpeg_draw(struct jpeg_data jpegdata); // 绘制JPEG图像

#endif
