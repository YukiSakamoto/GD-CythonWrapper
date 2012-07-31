#include <gd.h>

typedef struct {
	gdImagePtr im;
	int white;
	int black;
	int red;
	int current;
} gd_wrapper, *pgd_wrapper;
gd_wrapper *gw_init(int width, int height);
void gw_plot(gd_wrapper *p, int x, int y);
void gw_gif_out(char *fpath, gd_wrapper *p);
void gw_delete(gd_wrapper *p);
void gw_color_rgb(gd_wrapper *p, int r, int g, int b);
int gw_color_get(gd_wrapper *p);
void gw_color_set(gd_wrapper *p, int color);
void gw_line(gd_wrapper *p, int x1, int y1, int x2, int y2);
