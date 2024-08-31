clc;clear all;
I=[1 0 0;0 1 0;0 0 1]
Rz=rotate_z(I,30)
Rx=rotate_x(I,30)
R=Rz*Rx