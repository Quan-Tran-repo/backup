clc; clear all;
%% Declare
BNx=[1 2   2.5  3 4 5 6 6.5 7 8 9;
     1 0.5 0.25 0 0 0 0 0   0 0 0];
Nx=[1 2   2.5  3 4   5 6 6.5 7 8 9;
    0 0.5 0.75 1 0.5 0 0 0   0 0 0];
Zx=[1 2 2.5 3 4   5 6   6.5  7 8 9;
    0 0 0   0 0.5 1 0.5 0.25 0 0 0];
Px=[1 2 2.5 3 4 5 6   6.5  7 8   9;
    0 0 0   0 0 0 0.5 0.75 1 0.5 0];
BPx=[1 2 2.5 3 4 5 6 6.5 7 8   9;
     0 0 0   0 0 0 0 0   0 0.5 1];
% figure;
% plot(BNx(1,:),BNx(2,:)); hold on;
% plot(Nx(1,:),Nx(2,:));   hold on;
% plot(Zx(1,:),Zx(2,:));   hold on;
% plot(Px(1,:),Px(2,:));   hold on;
% plot(BPx(1,:),BPx(2,:)); hold on;
BNy=[0 1   2 3   4 5 6 7 8 9 10 11 12;
     0 0.5 1 0.5 0 0 0 0 0 0 0  0  0];
Ny=[0 1 2 3   4 5   6 7 8 9 10 11 12;
    0 0 0 0.5 1 0.5 0 0 0 0 0  0  0];
Zy=[0 1 2 3 4 5   6 7   8 9 10 11 12;
    0 0 0 0 0 0.5 1 0.5 0 0 0  0  0];
Py=[0 1 2 3 4 5 6 7   8 9   10 11 12;
    0 0 0 0 0 0 0 0.5 1 0.5 0  0  0];
BPy=[0 1 2 3 4 5 6 7 8 9   10 11   12;
     0 0 0 0 0 0 0 0 0 0.5 1  0.5  0];
% figure;
% plot(BNy(1,:),BNy(2,:)); hold on;
% plot(Ny(1,:),Ny(2,:));   hold on;
% plot(Zy(1,:),Zy(2,:));   hold on;
% plot(Py(1,:),Py(2,:));   hold on;
% plot(BPy(1,:),BPy(2,:)); hold on;
%% Calculation of R when x1=2.5 and x2=6.5 and difuzzying
%Row1
R1=prod2(BNx,BNx,BPy,2.5,6.5)
R2=prod2(Nx,BNx,BPy,2.5,6.5)
R3=prod2(Zx,BNx,Py,2.5,6.5)
R4=prod2(Px,BNx,Py,2.5,6.5)
R5=prod2(BPx,BNx,Zy,2.5,6.5)
%Row2
R6=prod2(BNx,Nx,BPy,2.5,6.5)
R7=prod2(Nx,Nx,Py,2.5,6.5)
R8=prod2(Zx,Nx,Py,2.5,6.5)
R9=prod2(Px,Nx,Zy,2.5,6.5)
R10=prod2(BPx,Nx,Ny,2.5,6.5)
%Row3
R11=prod2(BNx,Zx,Py,2.5,6.5)
R12=prod2(Nx,Zx,Py,2.5,6.5)
R13=prod2(Zx,Zx,Zy,2.5,6.5)
R14=prod2(Px,Zx,Ny,2.5,6.5)
R15=prod2(BPx,Zx,Ny,2.5,6.5)
%Row4
R16=prod2(BNx,Px,Py,2.5,6.5)
R17=prod2(Nx,Px,Zy,2.5,6.5)
R18=prod2(Zx,Px,Ny,2.5,6.5)
R19=prod2(Px,Px,Ny,2.5,6.5)
R20=prod2(BPx,Px,BNy,2.5,6.5)
%Row5
R21=prod2(BNx,BPx,Zy,2.5,6.5)
R22=prod2(Nx,BPx,Ny,2.5,6.5)
R23=prod2(Zx,BPx,Ny,2.5,6.5)
R24=prod2(Px,BPx,BNy,2.5,6.5)
R25=prod2(BNx,BPx,BNy,2.5,6.5)
%Max
RR1=max5(R1,R2,R3,R4,R5)
RR2=max5(R6,R7,R8,R9,R10)
RR3=max5(R11,R12,R13,R14,R15)
RR4=max5(R16,R17,R18,R19,R20)
RR5=max5(R21,R22,R23,R24,R25)
R=max5(RR1,RR2,RR3,RR4,RR5)
% figure;
% plot(R(1,:),R(2,:));
%Difuz
[x,y]=difuz(R)
