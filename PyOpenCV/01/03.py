#!/usr/bin/python 

from PIL import Image
from pylab import *

im = array(Image.open('empire.jpg').convert('L'))

figure()
hist(im.flatten(), 256)

gray()

contour(im, origin='image')
axis('equal')
axis('off')

show()

