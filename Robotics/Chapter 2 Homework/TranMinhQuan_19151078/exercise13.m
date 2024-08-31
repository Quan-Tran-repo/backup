clc; clear all;
%Find Tab
I=eye(3)                %Declare a unit 3x3 matrix
Rz=rotate_z(I,180)      %Find the rotation matrix 
Tab=transform_Q(Rz,3,0,0) 
%Find Tbc
Ry=rotate_y(I,90)
Rx=rotate_x(I,150)
R=Ry*Rx
Tbc=transform_Q(R,0,0,2)
%Find Tac
Tac=Tab*Tbc