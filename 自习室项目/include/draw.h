#ifndef __DRAW_H__
#define __DRAW_H__
#include "openfb0.h"
/*
    
*/
extern  void Draw_point(struct lcd lcd, unsigned int color,unsigned int x, unsigned int y);
extern void Draw_whole(struct lcd lcd, unsigned int color);
extern void Draw_circle(struct lcd lcd, unsigned int color, unsigned int x, unsigned int y, unsigned int radius);

#endif
// extern void Draw_rect(struct lcd lcd, unsigned int fore_color,unsigned int x_start, unsigned int y_start, unsigned int width, unsigned int height);
// extern void Draw_circle(struct lcd lcd, unsigned int fore_color,unsigned int background_color,unsigned int x_center, unsigned int y_center, unsigned int radius);
// extern void Move_ball(struct lcd lcd, unsigned int fore_color,unsigned int background_color,unsigned int x_center, unsigned int y_center, unsigned int radius);

