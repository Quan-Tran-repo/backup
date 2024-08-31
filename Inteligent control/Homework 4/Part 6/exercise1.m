clc;clear all;
%% Declare
A1=[0 1   2 3    4    5 6;
    0 0.5 1 0.66 0.33 0 0];
A2=[0 1   2 3 4 5 6;
    1 0.5 0 0 0 0 0];
A3=[0 1 2 3    4    5 6;
    0 0 0 0.33 0.66 1 1];
B1=[0 1   2 3   4 5 6;
    0 0.5 1 0.5 0 0 0];
B2=[0 1   2 3 4 5 6;
    1 0.5 0 0 0 0 0];
B3=[0 1 2 3   4 5 6;
    0 0 0 0.5 1 0 0];

x=1;
%% Calculation max_min
C1=min1(A1,B1,1)
C2=min1(A2,B2,1)
C3=min1(A3,B3,1)
C=max1(C1,C2,C3)
%plot(C(1,:),C(2,:))
%% Calculation max_prod
C1=prod1(A1,B1,1)
C2=prod1(A2,B2,1)
C3=prod1(A3,B3,1)
C=max1(C1,C2,C3)
%plot(C(1,:),C(2,:))