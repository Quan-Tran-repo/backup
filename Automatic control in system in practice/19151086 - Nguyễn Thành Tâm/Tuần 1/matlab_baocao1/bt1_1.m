clc; clear all;
%% Declaration for G1, G2, G3, H1
G1=tf(5,1);
G2=tf(1,[1 1]);
G3=tf([1 0],[1]);
H1=tf(1,1);
%% Calculate the transfer function
GA= parallel(G1,G3); 
GB=feedback(G2,H1);
G = series(GA,GB); 
TF = minreal(feedback(G,1))