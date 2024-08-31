clc; clear all;
%% Tab
%Declare a unit 3x3 matrix
I=eye(3);
%Find the rotation matrix
Rx1=rotate_x(I,90);
Rz1=rotate_z(I,180);
R1=Rx1*Rz1
%Find the transformation matrix
Tab=transform_Q(R1,0,4,2) 
%% Tbc
%Find the rotation matrix
Rx2=rotate_x(I,-90);
Rz2=rotate_z(I,180+36.9);
R2=Rx2*Rz2
%Find the transforming matrix
Tbc=transform_Q(R2,3,0,0)
%% Tac
Tac=Tab*Tbc
%% Tca
Tca=inv(Tac)