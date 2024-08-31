clc;clear all;
%% Declaration for G1,G2,G3,G4,G5
G1=tf([5],[1]);
G2=tf([1],[1 1]);
G3=tf([1 0],[1]);
G4=tf([1],[1]);
G5=1;
% Transducer at the input
T1=append(G1,G2,G3,G4,G5);
Q=[1 -2 5 0;...
2 1 3 -4;...
3 -2 5 0;...
4 2 0 0];
inputs=5;
outputs=2;
Ts=connect(T1,Q,inputs,outputs);
T=tf(Ts)