clc; clear all; close all; 
%% Nyquist diagram with K=10
G=tf(10,conv([1 0.2],[1 8 20]));
figure; nyquist(G);title('Nyquist diagram with K=10');
figure; margin(G);
%% Nyquist diagran with K=400
G1=tf(400,conv([1 0.2],[1 8 20]));
figure; nyquist(G1);title('Nyquist diagram with K=400');
figure; margin(G1);
