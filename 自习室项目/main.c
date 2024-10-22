#include "./include/function.h"

int main(int argc, char const *argv[])
{
    struct lcd mylcd;
    struct input myinput;
    // 打开屏幕
    bool lcd_bool = LCD_Init(&mylcd);
    bool input_bool = TS_Init(&myinput, mylcd);
    int size = 0;
LOGIN:
    login_pd(myinput, mylcd);
    while (1)
    {
        get_abs_value(&myinput, &size);
        if ((myinput.x_release > 340 && myinput.y_release > 350) && (myinput.x_release < 445 && myinput.y_release < 375))
        {
            if (bool_pwd != 1)
            {
                home1();
                Ordinary_user(myinput, mylcd);
                // printf("%s:退出成功\n", username);
                goto LOGIN;
            }
            else
            {
                show();
                Mdin_user(myinput, mylcd);
                bool_pwd = 0;
                printf("管理员账户退出成功\n");
                goto LOGIN;
            }
        }
        if ((myinput.x_release > 0 && myinput.y_release > 0) && (myinput.x_release < 80 && myinput.y_release < 80))
        {
            printf("系统关闭\n");
            class_draw("./src/deffue.bmp");
            break;
        }
        
    }
    LCD_Destory(mylcd);
    TS_Release(myinput);
    return 0;
}
