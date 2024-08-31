clc; clear all;
%% Declaration for G1,G2,G3,G4,G5,G6,G7,G8,G9,G10
G1=5;
G2=tf([1],[1 1]);
G3=tf([1 0],[1]);
G4=tf([1],[1 1]);
G5=tf([1 0],[1]);
G6=tf([1 2],[1]);
G7=tf([1],[1]);
G8=tf([1],[1 0]);
G9=tf([3],[4 1]);
G10=1
% Transducer at the input
T1=append(G1,G2,G3,G4,G5,G6,G7,G8,G9,G10);
Q=[1 -7 10;...
2 1 -8;...
3 2 0;...
4 3 -9;...
5 4 6;...
6 2 0;...
7 5 0;...
8 5 0;...
9 5 0];
inputs=10;
outputs=5;
Ts=connect(T1,Q,inputs,outputs);
T=minreal(tf(Ts))