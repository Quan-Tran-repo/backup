clc;clear all;
%% Declaration
a=sym('a');b=sym('b');c=sym('c');d=sym('d');e=sym('e');
I=eye(3);
%% T02
% Finding rotation matrix
Rz=rotate_z(I,-90);
% Finding transformation matrix
T02=transform_Q(Rz,-b,c+e,0)
%% T23
% Finding rotation matrix
Ry=rotate_y(I,90);
% Finding transforming matrix
T23=transform_Q(Ry,e,0,a)
%% T03
T03=T02*T23
%% T34
% Finding rotation matrix
Rx=rotate_x(I,-90);
Ry1=rotate_y(I,-90);
R=Rx*Ry1
% Finding transforming matrix
T34=transform_Q(R,d,0,c)
%% T04
T04=T03*T34
%% T45
% Finding rotation matrix
Rz1=rotate_z(I,90);
Rx1=rotate_x(I,-90);
R1=Rz1*Rx1
% Finding transforming matrix
T45=transform_Q(R1,b,0,d)
%% T05
T05=T04*T45