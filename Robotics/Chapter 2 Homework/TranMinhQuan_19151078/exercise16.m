clc; clear all;
%Declare a unit 3x3 matrix
I=eye(3);
%Find the rotation matrix
Rx=rotate_x(I,90);
Rz=rotate_z(I,180);
R=Rx*Rz
%Find the transformation matrix
Tab=transform_Q(R,0,4,2) 