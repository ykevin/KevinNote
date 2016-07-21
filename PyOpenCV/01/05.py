#!/usr/bin/python 

from PIL import Image
from pylab import *

im = array(Image.open('empire.jpg'))
print im.shape, im.dtype


im = array(Image.open('empire.jpg').convert('L'), 'f')
print im.shape, im.dtype


