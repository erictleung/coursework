#!/bin/python

# import packages
import numpy as np

# column picture
j = np.array([[2, -1]]).T
k = np.array([[-1, 2]]).T
l = np.array([[0, 3]]).T

## test equality
1*j + 2*k == l

# matrix picture
A = np.array([[2, -1],[-1, 2]])
b = np.array([[0, 3]]).T
x = np.array([[1, 2]]).T

## test equality
np.dot(A, x) == b
