#include "font.h"

void Font_write(struct lcd *lcd,char *str,int x,int y)
{
				
	//打开字体	
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置
	fontSetSize(f,36);
	
	//创建一个画板（点阵图）
	bitmap *bm = createBitmapWithInit(18,28,4,getColor(0,20,18,10)); 
	//将字体写到点阵图上
	fontPrint(f,bm,0,0,str,getColor(0,255,255,255),0);
	//把字体框输出到LCD屏幕上
	show_font_to_lcd(lcd->map_ptr,260+x,130+y,bm);
	//关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);
}
void Font_exit(struct lcd *lcd,char *str)
{
				
	//打开字体	
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置
	fontSetSize(f,36);
	
	//创建一个画板（点阵图）
	bitmap *bm = createBitmapWithInit(100,40,4,getColor(0,20,18,10)); 
	//将字体写到点阵图上
	fontPrint(f,bm,20,0,str,getColor(0,255,255,255),0);
	//把字体框输出到LCD屏幕上
	show_font_to_lcd(lcd->map_ptr,600,400,bm);
	//关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);
}
void Font_pay(struct lcd *lcd,char *str)
{
	//打开字体	
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置
	fontSetSize(f,36);
	
	//创建一个画板（点阵图）
	bitmap *bm = createBitmapWithInit(100,50,4,getColor(0,20,18,10)); 
	//将字体写到点阵图上
	fontPrint(f,bm,20,7,str,getColor(0,255,255,255),0);
	//把字体框输出到LCD屏幕上
	show_font_to_lcd(lcd->map_ptr,220,50,bm);
	//关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);
}
void Font_num(struct lcd *lcd,char *str)
{
	//打开字体	
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置
	fontSetSize(f,40);
	
	//创建一个画板（点阵图）
	bitmap *bm = createBitmapWithInit(100,40,4,getColor(0,20,18,10)); 
	//将字体写到点阵图上
	fontPrint(f,bm,20,0,str,getColor(0,255,255,255),0);
	//把字体框输出到LCD屏幕上
	show_font_to_lcd(lcd->map_ptr,350,220,bm);
	//关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);
}
void Font_limit(struct lcd *lcd,char *str,int x,int y)
{
	//打开字体	
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置
	fontSetSize(f,40);
	//创建一个画板（点阵图）
	bitmap *bm = createBitmapWithInit(120,40,4,getColor(0,28,28,28)); 
	//将字体写到点阵图上
	fontPrint(f,bm,0,0,str,getColor(0,255,255,255),0);
	//把字体框输出到LCD屏幕上
	show_font_to_lcd(lcd->map_ptr,x,y,bm);
	//关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);
}


void Font_zt(struct lcd *lcd,char *str,int x)
{
	//打开字体	
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置
	fontSetSize(f,40);
	//创建一个画板（点阵图）
	bitmap *bm = createBitmapWithInit(800,40,4,getColor(0,28,28,28)); 
	//将字体写到点阵图上
	fontPrint(f,bm,0,0,str,getColor(0,255,255,255),0);
	//把字体框输出到LCD屏幕上
	show_font_to_lcd(lcd->map_ptr,0,x,bm);
	//关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);
}
void Font_log(struct lcd *lcd,char *str)
{
	//打开字体	
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置
	fontSetSize(f,25);
	//创建一个画板（点阵图）
	bitmap *bm = createBitmapWithInit(800,480,4,getColor(0,28,28,28)); 
	//将字体写到点阵图上
	fontPrint(f,bm,0,0,str,getColor(0,255,255,255),0);
	//把字体框输出到LCD屏幕上
	show_font_to_lcd(lcd->map_ptr,0,0,bm);
	//关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);
}