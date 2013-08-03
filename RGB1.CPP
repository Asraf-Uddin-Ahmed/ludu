#include<stdio.h>
#include<conio.h>
#include<graphics.h>


void RGB(int color_num, int red, int green, int blue)
{
	struct palettetype pal;
	getpalette(&pal);	// grab a copy of the palette
	setrgbpalette(pal.colors[color_num], red, green, blue);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,color_num);

}


