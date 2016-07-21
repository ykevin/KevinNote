#!/usr/bin/python 

from PIL import Image
from pylab import *

pil_im = array(Image.open('empire.jpg').convert('L'))
imshow(pil_im)
title("image")
show()
