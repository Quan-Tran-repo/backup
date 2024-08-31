clc; clear all;
%% Declaration
I=eye(3);
d1=sym('d1'); d2=sym('d2');d3=sym('d3');d6=sym('d6');
%% T01
% Finding rotation matrix
Rx=rotate_x(I,-90);
Ry=rotate_y(I,90);
R=Rx*Ry
% Finding transformation matrix
T01=transform_Q(R,0,0,d1)
%% T12
% Finding rotation matrix
Rz=rotate_z(I,-90);
Rx1=rotate_x(I,90);
R1=Rz*Rx1;
% Finding transformation matrix
T12=transform_Q(R1,0,0,d2)
%% T23
%Finding the rotation matrix
Rz2=rotate_z(I,-90);
%Finding the transformation matrix
T23=transform_Q(Rz2,0,0,d3)
%% T34
%Finding the rotation matrix
Rx2=rotate_x(I,-90);
%Finding the transformation matrix
T34=transform_Q(Rx2,0,0,0)
%% T45
%Finding the rotation matrix
Rx3=rotate_x(I,90);
%Finding the transformation matrix
T45=transform_Q(Rx3,0,0,0)
%% T56
%Finding the rotation matrix
R2=I;
%Finding the transformation matrix
T56=transform_Q(R2,0,0,d6)
%% T06
T06=T01*T12*T23*T34*T45*T56