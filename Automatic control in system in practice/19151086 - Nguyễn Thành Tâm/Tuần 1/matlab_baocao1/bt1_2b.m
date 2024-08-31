clc
G1=tf([0 5],[0 1]);
G2=tf([0 1],[1 1]);
G3=tf([1 0],[0 1]);
G4=tf([0 1],[0 1]);
G5=tf([0 1],[0 1]);
T=append(G1,G2,G3,G4,G5);
inputs=5;
outputs=2;
Q=[1 -2 5 0
   2 1 3 -4
   3 -2 5 0
   4 2 0 0];
Ts=connect(T,Q,inputs,outputs);
Tf=tf(Ts)
