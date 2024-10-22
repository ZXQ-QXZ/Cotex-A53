#ifndef __TOUCH_SCREEN_H__
#define __TOUCH_SCREEN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <linux/input.h>
#include "openfb0.h"
#include <time.h>

#define TOUCH_SCREEN_DEVICE  "/dev/input/event0"

struct input
{
    int32_t fd;
    double x_ratio;//比例因子
    double y_ratio;//比例因子
    uint32_t x;
    uint32_t y;
    uint32_t x_press;
    uint32_t y_press;
    uint32_t x_release;
    uint32_t y_release;
};

extern bool TS_Init(struct input *p, struct lcd lcd);
extern void TS_Release(struct input ts);
extern void get_abs_value(struct input *p,int *size);
extern void user_password(struct input myinput,struct lcd lcd,int a,char *username,char *password);
// extern void insert_password(struct input myinput, struct lcd lcd, int a,char *username,char *password);
extern void get_time_value(struct input *p);
#endif