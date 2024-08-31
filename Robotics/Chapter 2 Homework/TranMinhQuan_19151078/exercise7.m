clc;clear all;
I=[1 0 0;0 1 0;0 0 1]
Ry=rotate_y(I,30)
Rx=rotate_x(I,45)
R=Ry*Rx