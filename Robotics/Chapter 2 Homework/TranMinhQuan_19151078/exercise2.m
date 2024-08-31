clc; clear all;
I=eye(3)
Rz=rotate_z(I,30)
T=transform_Q(Rz,4,3,0)
iT=inv(T)