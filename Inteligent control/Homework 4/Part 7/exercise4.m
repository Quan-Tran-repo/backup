clc; clear all;
%% Declare
Nx=[-1 -0.5  0   0.5  1 1.5 2 2.5 3;
     1  0.75 0.5 0.25 0 0   0 0   0];
Zx=[-1 -0.5  0   0.5  1 1.5  2   2.5  3;
     0  0.25 0.5 0.75 1 0.75 0.5 0.25 0];
Px=[-1 -0.5 0 0.5 1 1.5  2   2.5  3;
     0  0   0 0   0 0.25 0.5 0.75 1];
% figure;
% plot(Nx(1,:),Nx(2,:));   hold on;
% plot(Zx(1,:),Zx(2,:));   hold on;
% plot(Px(1,:),Px(2,:));   hold on;
Ny=[ 1 2   3 4 5;
     1 0.5 0 0 0];
Zy=[ 1 2   3 4   5;
     0 0.5 1 0.5 0];
Py=[ 1 2 3 4   5;
     0 0 0 0.5 1];
% figure;
% plot(Ny(1,:),Ny(2,:));   hold on;
% plot(Zy(1,:),Zy(2,:));   hold on;
% plot(Py(1,:),Py(2,:));   hold on;
%% Calculation of R when x1=1.5 and x2=2.5 and difuzzying
%Column 1
R1=min2(Nx,Nx,Py,1.5,2.5)
R2=min2(Nx,Zx,Py,1.5,2.5)
R3=min2(Nx,Px,Zy,1.5,2.5)
%Column 2
R4=min2(Zx,Nx,Py,1.5,2.5)
R5=min2(Zx,Zx,Zy,1.5,2.5)
R6=min2(Zx,Px,Ny,1.5,2.5)
%Column 3
R7=min2(Px,Nx,Zy,1.5,2.5)
R8=min2(Px,Zx,Ny,1.5,2.5)
R9=min2(Px,Px,Ny,1.5,2.5)
%Max
R=max1(max1(R1,R2,R3),max1(R4,R5,R6),max1(R7,R8,R9))
% plot(R(1,:),R(2,:));
%Difuz
[x,y]=difuz(R)
%% Calculation of R when x1=-0.5 and x2=1.5
%Column 1
R1=min2(Nx,Nx,Py,-0.5,1.5)
R2=min2(Nx,Zx,Py,-0.5,1.5)
R3=min2(Nx,Px,Zy,-0.5,1.5)
%Column 2
R4=min2(Zx,Nx,Py,-0.5,1.5)
R5=min2(Zx,Zx,Zy,-0.5,1.5)
R6=min2(Zx,Px,Ny,-0.5,1.5)
%Column 3
R7=min2(Px,Nx,Zy,-0.5,1.5)
R8=min2(Px,Zx,Ny,-0.5,1.5)
R9=min2(Px,Px,Ny,-0.5,1.5)
%Max
R=max1(max1(R1,R2,R3),max1(R4,R5,R6),max1(R7,R8,R9))
% plot(R(1,:),R(2,:));
%Difuz
[x,y]=difuz(R)
%% Calculation of R when x1=-0 and x2=3
%Column 1
R1=min2(Nx,Nx,Py,0,3)
R2=min2(Nx,Zx,Py,0,3)
R3=min2(Nx,Px,Zy,0,3)
%Column 2
R4=min2(Zx,Nx,Py,0,3)
R5=min2(Zx,Zx,Zy,0,3)
R6=min2(Zx,Px,Ny,0,3)
%Column 3
R7=min2(Px,Nx,Zy,0,3)
R8=min2(Px,Zx,Ny,0,3)
R9=min2(Px,Px,Ny,0,3)
%Max
R=max1(max1(R1,R2,R3),max1(R4,R5,R6),max1(R7,R8,R9))
% plot(R(1,:),R(2,:));
%Difuz
[x,y]=difuz(R)
