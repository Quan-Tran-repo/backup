clc; clear all;
%% Declaration for G1,G2,G3,G4,G5,G6,H1,H2,H3
G1=5;
G2=tf([1],[1 1]);
G3=tf([1 0],[1]);
G4=tf([1],[1 1]);
G5=tf([1 0],[1]);
G6=tf([1 2],[1]);
H1=tf([1],[1]);
H2=tf([1],[1 0]);
H3=tf([3],[4 1]);
%% Calculate the transfer function of the system
GA=parallel(G3,G6/G4);
GB=feedback(series(G4,G5),H3);
GC=feedback(series(series(G2,GA),GB),H2);
G=minreal(feedback(series(GC,G1),H1))