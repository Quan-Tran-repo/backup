clc;clear all;
% Declaration
a=sym('a');b=sym('b');c=sym('c');d=sym('d');e=sym('e');
I=eye(3);
% Finding rotation matrix
Rx=rotate_x(I,-90);
Ry=rotate_y(I,180);
R=Rx*Ry
% Finding transformation matrix
T01=transform_Q(R,0,c+e,a-d)