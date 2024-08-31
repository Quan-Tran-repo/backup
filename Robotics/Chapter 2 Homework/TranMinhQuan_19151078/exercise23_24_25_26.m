clc; clear all;
%% Declaration
I=eye(3);
%% T01
% Finding rotation matrix
Rx=rotate_x(I,180);
% Finding transformation matrix
T01=transform_Q(Rx,-3.5,3,3)
%% T12
% Finding rotation matrix
Ry=rotate_y(I,90);
Rz=rotate_z(I,-90);
R=Ry*Rz;
% Finding transformation matrix
T12=transform_Q(R,0,3,3)
%% T02
T02=T01*T12
%% T23
% Finding the angel a
a=asind(3/5)
%Finding the rotation matrix
Ry1=rotate_y(I,-90);
Rx1=rotate_x(I,(180+a));
R1=Ry1*Rx1
%Finding the transformation matrix
T23=transform_Q(R1,0,7,0)
%% T03
T03=T02*T23
%% T34
%Finding the rotation matrix
Ry2=rotate_y(I,180);
%Finding the transformation matrix
T34=transform_Q(Ry2,3.5,0,0)
%% T04
T04=T03*T34