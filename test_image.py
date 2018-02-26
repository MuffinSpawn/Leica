# -*- coding: utf-8 -*-
"""
Created on Sun Feb 25 22:11:22 2018

@author: peter
"""

import io
import matplotlib.pyplot as plt
import numpy
from PIL import Image

with open('C:/Users/peter/Pictures/pier.jpg', 'br') as f:
    image_data = f.read()

stream = io.BytesIO(image_data)
img = Image.open(stream)

plt.imshow(numpy.asarray(img))
