#include <stdio.h>
#include <stdlib.h>
#include <gd.h>
#include "./gd_wrapper.h"
	
static void *my_malloc(size_t s)
{
	return malloc(s);
}

static void my_free(void*p)
{
	free(p);
}

gd_wrapper *gw_init(int width, int height)
{
	gdImagePtr im = gdImageCreate(width, height);
	gd_wrapper *w = my_malloc(sizeof(gd_wrapper));
	w->im = im;
	w->white = gdImageColorAllocate(im, 255, 255, 255);
	w->black = gdImageColorAllocate(im, 0, 0, 0);
	w->red  = gdImageColorAllocate(im, 255, 0, 0);
	w->current = w->white;
	return w;
}

void gw_color_rgb(gd_wrapper *p, int r, int g, int b)
{
	if (p != NULL) {
		p->current = gdImageColorAllocate(p->im, r, g, b);
	}
}

void gw_color_set(gd_wrapper *p, int color)
{
	if (p != NULL) {
		p->current = color;
	}
}

int gw_color_get(gd_wrapper *p)
{
	return p == NULL ? -1 : p->current;
}

void gw_delete(gd_wrapper *p)
{
	my_free(p);
}

void gw_line(gd_wrapper *p, int x1, int y1, int x2, int y2)
{
	gdImageLine(p->im, x1, y1, x2, y2, p->current);
}

void gw_plot(gd_wrapper *p, int x, int y)
{
	if (p != NULL) {
		gdImageSetPixel(p->im, x, y, p->current);
	}
}

void gw_gif_out(char *fpath, gd_wrapper *p)
{
	FILE *fp;
	if (fpath == NULL || p == NULL)
		return ;

	fp = fopen(fpath, "w");
	if (fp != NULL) {
		gdImageGif(p->im, fp);
		fclose(fp);
	}
	return;
}

#if 0
int main(void)
{
	gd_wrapper *p = gw_init(100, 100);
	gw_plot(p, 3, 5);
	gw_plot(p, 2, 24);
	gw_gif_out("asdf.gif", p);
	return 0;
}
#endif
