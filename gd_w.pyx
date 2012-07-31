
cdef extern from "./gd_wrapper.h":
    ctypedef struct gd_wrapper:
        pass
    
    gd_wrapper* gw_init(int,int)
    void gw_plot(gd_wrapper*,int,int)
    void gw_gif_out(char *,gd_wrapper *)
    void gw_delete(gd_wrapper *)
    void gw_color_rgb(gd_wrapper *,int,int,int)
    int  gw_color_get(gd_wrapper *)
    void gw_color_set(gd_wrapper *,int)
    void gw_line(gd_wrapper *, int, int, int, int)

cdef class GD_Obj:
    cdef gd_wrapper *ptr
    def __cinit__(self,width, height):
        self.ptr = gw_init(width, height)

    def __del__(self):
        gw_delete(self.ptr)

    def plot(self,x,y):
        gw_plot(self.ptr, x, y)

    def write_gif(self,path):
        gw_gif_out(path, self.ptr)

    def color_get(self):
        return gw_color_get(self.ptr)
    
    def color_set(self,c):
        gw_color_set(self.ptr,c)

    def color_rgb(self,int r,int g,int b):
        gw_color_rgb(self.ptr,r,g,b)

    def line(self,int x1, int y1, int x2, int y2):
        gw_line(self.ptr, x1, y1, x2, y2)
