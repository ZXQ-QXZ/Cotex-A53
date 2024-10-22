#include "openfb0.h"
#include "draw.h"
// 获取板子属性是否成功
bool LCD_Init(struct lcd *p_lcd)
{
    //打开LCD设备文件
    p_lcd->fd =open(LCD_DEVICE,O_RDWR);
    if(p_lcd->fd == -1)
    {
        perror("打开设备失败");
        goto FD_ERROR;
    }
    // 获取可变属性和固定属性
    struct fb_fix_screeninfo fixinfo;//固定属性
    struct fb_var_screeninfo varinfo;//可变属性
    // 检测固定属性是否可以成功获取
    if(ioctl(p_lcd->fd,FBIOGET_FSCREENINFO,&fixinfo)!=0)
    {
        perror("获取LCD设备固定属性失败");
        goto FIXINFO_ERROR;
    }
    //检测可变属性是否可以成功获取
    if(ioctl(p_lcd->fd,FBIOGET_VSCREENINFO,&varinfo)!=0)
    {
        perror("获取LCD设备可变属性失败");
        goto VARINFO_ERROR;
    }
    // 获取板子宽和高
    p_lcd->x=varinfo.xres;
    p_lcd->y=varinfo.yres;
    // 获取板子的颜色位数
    p_lcd->lcd_length=varinfo.xres*varinfo.yres*((varinfo.bits_per_pixel/8));
    // 开启板子映射
    p_lcd->map_ptr=mmap(NULL,p_lcd->lcd_length,PROT_WRITE,MAP_SHARED,p_lcd->fd,0);
    if(p_lcd->map_ptr==MAP_FAILED)
    {
        perror("创建LCD虚拟内存失败");
        goto MMAP_ERROR;
    }
    return true;
FIXINFO_ERROR:
VARINFO_ERROR:
MMAP_ERROR:
    close(p_lcd->fd);
FD_ERROR:
    return false;
}
// 关闭板子资源
void LCD_Destory(struct lcd lcd)
{
    munmap(lcd.map_ptr,lcd.lcd_length);
    close(lcd.fd);
}