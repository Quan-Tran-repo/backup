clc; clear all;
%% Declare
Nx=[-1 0   0.5  1 2 3;
     1 0.5 0.25 0 0 0];
Zx=[-1 0   0.5  1 2   3;
     0 0.5 0.75 1 0.5 0];
Px=[-1 0 0.5 1 2   3;
     0 0 0   0 0.5 1];
Ny=[ 1 2   3 4 5;
     1 0.5 0 0 0];
Zy=[ 1 2   3 4   5;
     0 0.5 1 0.5 0];
Py=[ 1 2 3 4   5;
     0 0 0 0.5 1];
%% Calculation R when x=0.5
R1=min1(Nx,Py,0.5)
R2=min1(Zx,Zy,0.5)
R3=min1(Px,Ny,0.5)
R=max1(R1,R2,R3)
[x,y]=difuz(R)
%% Calculation R when x=2
R1=min1(Nx,Py,2)
R2=min1(Zx,Zy,2)
R3=min1(Px,Ny,2)
R=max1(R1,R2,R3)
[x,y]=difuz(R)