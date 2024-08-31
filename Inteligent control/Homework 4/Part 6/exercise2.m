clc;clear all;
%% Declare
A1=[0 1   2 3    4    5 6;
    0 0.5 1 0.66 0.33 0 0];
A2=[0 1   2 3 4 5 6;
    1 0.5 0 0 0 0 0];
A3=[0 1 2 3    4    5 6;
    0 0 0 0.333 0.666 1 1];
B1=A1;
B2=A2;
B3=A3;
C1=[0 1   2 3   4 5 6;
    0 0.5 1 0.5 0 0 0];
C2=[0 1   2 3 4 5 6;
    1 0.5 0 0 0 0 0];
C3=[0 1 2 3   4 5 6;
    0 0 0 0.5 1 0 0];
%% Calculation max_min (1,3)
D1=min2(A1,B3,C1,1,3)
D2=min2(A2,B2,C2,1,3)
D3=min2(A3,B1,C3,1,3)
D=max1(D1,D2,D3)
%% Calculation max_min (0,5)
D1=min2(A1,B3,C1,0,5)
D2=min2(A2,B2,C2,0,5)
D3=min2(A3,B1,C3,0,5)
D=max1(D1,D2,D3)
%plot(D(1,:),D(2,:))
%% Calculation max_prod (1,3)
D1=prod2(A1,B3,C1,1,3)
D2=prod2(A2,B2,C2,1,3)
D3=prod2(A3,B1,C3,1,3)
D=max1(D1,D2,D3)
%plot(D(1,:),D(2,:))
%% Calculation max_prd (0,5)
D1=prod2(A1,B3,C1,0,5)
D2=prod2(A2,B2,C2,0,5)
D3=prod2(A3,B1,C3,0,5)
D=max1(D1,D2,D3)
%plot(D(1,:),D(2,:))