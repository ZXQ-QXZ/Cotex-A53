#include "openfb0.h"
#include "draw.h"

/***************************
**函数功能:在LCD上画点       
**主要参数：                
**    lcd@LCD设备结构体
**    color@点的颜色
**    x@屏幕的位置x轴坐标
**    y@屏幕的位置y轴坐标
***************************/
void Draw_point(struct lcd lcd, unsigned int color,unsigned int x, unsigned int y)
{
    lcd.map_ptr[y*lcd.x+x] = color; 
}

// 画全屏
void Draw_whole(struct lcd lcd, unsigned int color)
{
    for(int i = 0; i < lcd.x; i++)
    {
        for(int j = 0; j < lcd.y; j++)
        {
            lcd.map_ptr[j*lcd.x+i] = color; 
        }
    }
}
// 画圆圈
void Draw_circle(struct lcd lcd, unsigned int color, unsigned int x, unsigned int y, unsigned int radius)
{
    for(int i = x-radius; i <= x+radius; i++)
    {
        for(int j = y-radius; j <= y+radius; j++)
        {
            if((radius*radius) >= (i-x)*(i-x) + (j-y)*(j-y))
            {
                Draw_point(lcd,color,i,j);
            }
        }
    }
}


