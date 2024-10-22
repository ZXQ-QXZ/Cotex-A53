#include "input.h"
#include "font.h"
#include "bmp.h"

bool TS_Init(struct input *p, struct lcd lcd)
{
    // 打开触摸屏设备
    p->fd = open(TOUCH_SCREEN_DEVICE, O_RDONLY);
    if (p->fd == -1)
    {
        perror("open touch screen fail");
        return false;
    }

    // 获取硬件属性信息
    struct input_absinfo absinfo;
    ioctl(p->fd, EVIOCGABS(ABS_X), &absinfo);

    p->x_ratio = (double)(1.0 * lcd.x) / absinfo.maximum;
    ioctl(p->fd, EVIOCGABS(ABS_Y), &absinfo);
    p->y_ratio = (double)(1.0 * lcd.y) / absinfo.maximum;

    return true;
}
void TS_Release(struct input ts)
{
    close(ts.fd);
}

void get_abs_value(struct input *p, int *size)
{
    // 读取输入数据
    struct input_event ts_event;
    bool flag = false;
    unsigned short count = 0;
    while (1)
    {
        read(p->fd, &ts_event, sizeof ts_event);
        if (ts_event.type == EV_ABS)
        {
            if (ts_event.code == ABS_X)
            {
                p->x = ts_event.value * p->x_ratio;
            }
            if (ts_event.code == ABS_Y)
            {
                p->y = ts_event.value * p->y_ratio;
            }
        }

        if (ts_event.type == EV_KEY && ts_event.code == BTN_TOUCH && ts_event.value == 1)
        {
            if (!flag)
            {
                p->x_press = p->x;
                p->y_press = p->y;
                flag != flag;
            }
        }

        if (ts_event.type == EV_KEY && ts_event.code == BTN_TOUCH && ts_event.value == 0)
        {
            p->x_release = p->x;
            p->y_release = p->y;
            // 计算水平位移差
            *size = p->x_release - p->x_press;
            break;
        }
    }
}

void get_time_value(struct input *p)
{
    // 读取输入数据
    struct input_event ts_event;
    bool flag = false;
    unsigned short count = 0;
    int i = 2;
    while (i--)
    {
        read(p->fd, &ts_event, sizeof ts_event);
        if (ts_event.type == EV_ABS)
        {
            if (ts_event.code == ABS_X)
            {
                p->x = ts_event.value * p->x_ratio;
            }
            if (ts_event.code == ABS_Y)
            {
                p->y = ts_event.value * p->y_ratio;
            }
        }

        if (ts_event.type == EV_KEY && ts_event.code == BTN_TOUCH && ts_event.value == 1)
        {
            if (!flag)
            {
                p->x_press = p->x;
                p->y_press = p->y;
                flag != flag;
            }
        }
        if (ts_event.type == EV_KEY && ts_event.code == BTN_TOUCH && ts_event.value == 0)
        {
            p->x_release = p->x;
            p->y_release = p->y;
            // 计算水平位移差
        }
    }
}

void perfect1()
{
    FILE *fileperfect = fopen("./src/perfect.bmp", "r");
    File_draw(fileperfect, 134, 278);
}

void user_password(struct input myinput, struct lcd lcd, int a, char *username, char *password)
{
    int m, n = 0, x = 0, y = 0;
    if (a == 1)
    {
        y += 35;
    }

    while (1)
    {
        get_abs_value(&myinput, &m);
        if ((myinput.x_release > 244 && myinput.y_release > 278) && (myinput.x_release < 319 && myinput.y_release < 338))
        {

            x = n * 18;
            if (y == 0)
            {
                username[n] = '1';
                Font_write(&lcd, "1", x, y);
            }
            else
            {
                password[n] = '1';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 319 && myinput.y_release > 278) && (myinput.x_release < 394 && myinput.y_release < 338))
        {
            x = n * 18;
            if (y == 0)
            {
                username[n] = '2';
                Font_write(&lcd, "2", x, y);
            }
            else
            {
                password[n] = '2';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 394 && myinput.y_release > 278) && (myinput.x_release < 469 && myinput.y_release < 338))
        {
            x = n * 18;
            if (y == 0)
            {
                username[n] = '3';
                Font_write(&lcd, "3", x, y);
            }
            else
            {
                password[n] = '3';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 469 && myinput.y_release > 278) && (myinput.x_release < 554 && myinput.y_release < 338))
        {
            n--;
            if (n <= 0)
            {
                n = 0;
            }
            x = n * 18;
            Font_write(&lcd, " ", x, y);
            n--;
        }
        else if ((myinput.x_release > 224 && myinput.y_release > 338) && (myinput.x_release < 319 && myinput.y_release < 398))
        {

            x = n * 18;
            if (y == 0)
            {
                username[n] = '4';
                Font_write(&lcd, "4", x, y);
            }
            else
            {
                password[n] = '4';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 319 && myinput.y_release > 338) && (myinput.x_release < 394 && myinput.y_release < 398))
        {

            x = n * 18;
            if (y == 0)
            {
                username[n] = '5';
                Font_write(&lcd, "5", x, y);
            }
            else
            {
                password[n] = '5';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 394 && myinput.y_release > 338) && (myinput.x_release < 469 && myinput.y_release < 398))
        {

            x = n * 18;
            if (y == 0)
            {
                username[n] = '6';
                Font_write(&lcd, " 6", x, y);
            }
            else
            {
                password[n] = '6';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 469 && myinput.y_release > 338) && (myinput.x_release < 554 && myinput.y_release < 398))
        {
            x = n * 18;
            if (y == 0)
            {
                username[n] = '0';
                Font_write(&lcd, "0", x, y);
            }
            else
            {
                password[n] = '0';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 224 && myinput.y_release > 398) && (myinput.x_release < 319 && myinput.y_release < 458))
        {

            x = n * 18;
            if (y == 0)
            {
                username[n] = '7';
                Font_write(&lcd, "7", x, y);
            }
            else
            {
                password[n] = '7';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 319 && myinput.y_release > 398) && (myinput.x_release < 394 && myinput.y_release < 458))
        {
            x = n * 18;
            if (y == 0)
            {
                username[n] = '8';
                Font_write(&lcd, "8", x, y);
            }
            else
            {
                password[n] = '8';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 394 && myinput.y_release > 398) && (myinput.x_release < 469 && myinput.y_release < 458))
        {
            x = n * 18;
            if (y == 0)
            {
                username[n] = '9';
                Font_write(&lcd, "9", x, y);
            }
            else
            {
                password[n] = '9';
                Font_write(&lcd, "*", x, y);
            }
        }
        else if ((myinput.x_release > 469 && myinput.y_release > 398) && (myinput.x_release < 554 && myinput.y_release < 458))
        {
            perfect1();
            break;
        }
        n++;
    }
}
