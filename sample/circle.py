import numpy as np
import sys
sys.path.insert(0, '..')
import GDWrapper

width = 500
height= 500
r = 100

g = GDWrapper.GD_Obj(width, height)
centre_x = width / 2
centre_y = height / 2

def xx(x):
    return x * x

white = g.color_get()
g.color_rgb(0,128,128)

for i in range(width):
    if centre_y < i :
        g.color_rgb(128, 0, 0)

    for j in range(height):
        l2 = xx(abs(i - centre_x) ) + xx( abs(j - centre_y) )
        if l2 < xx(r) :
            g.plot(i, j)

g.color_rgb(0,0,0)
g.line(centre_x, 0, centre_x, centre_y)

g.write_gif("circle2.gif")



