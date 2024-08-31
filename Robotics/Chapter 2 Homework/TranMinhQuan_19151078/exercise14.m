clc; clear all;
%Declare unit matrix 3x3
I=eye(3);
%Find rotation matrix
Ry=rotate_y(I,90)
Rx=rotate_x(I,150)
R=Ry*Rx
%Find Tbc
Tbc=transform_Q(R,0,0,2)