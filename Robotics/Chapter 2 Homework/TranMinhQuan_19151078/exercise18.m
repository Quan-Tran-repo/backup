clc; clear all;
%Declare unit matrix I
I=eye(3);
%Find the rotation matrix
Rx2=rotate_x(I,-90);
Rz2=rotate_z(I,180+36.9);
R2=Rx2*Rz2
%Find the transforming matrix
Tbc=transform_Q(R2,3,0,0)