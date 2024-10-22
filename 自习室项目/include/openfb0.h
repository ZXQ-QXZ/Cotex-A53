#ifndef __OPENFB0_H__
#define __OPENFB0_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
// 显示屏名称
#define LCD_DEVICE  "/dev/fb0"
// 定义结构体
struct lcd
{
    int fd;//打开显示屏返回值
    unsigned int x;//显示屏幕的宽度
    unsigned int y;//显示屏幕的高度
    unsigned int lcd_length;//显示屏幕的总大小宽*高*色度
    int *map_ptr;//开启的映射指针
};
extern bool LCD_Init(struct lcd *p_lcd);//检测是否可以成功使用该屏幕
extern void LCD_Destory(struct lcd lcd);//关闭映射并释放资源




#endif