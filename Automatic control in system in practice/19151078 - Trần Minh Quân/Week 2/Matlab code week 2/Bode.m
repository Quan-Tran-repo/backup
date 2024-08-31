clc; clear all; close all;
%% Bode diagram with K=10
G=tf(10,conv([1 0.2],[1 8 20]));
figure; bode(G,{0.1,100});title('Bode diagram with K=10'); %Drawing the bode diagram
figure; margin(G); %Show the phase margin and gain margin from the bode diagram
Gk=feedback(G,1); %Find the transfer function of a close loop system 
figure; step(Gk,10);title('Step response of the system with K=10') %Find the step response of the system
grid on
%% Bode diagram with K=400
G1=tf(400,conv([1 0.2],[1 8 20]));
figure; bode(G1,{0.1,100});title('Bode diagram with K=400'); %Drawing the bode diagram
figure; margin(G1); %Show the phase margin and gain margin from the bode diagram
Gt=feedback(G1,1); %Find the transfer function of a close loop system 
figure; step(Gt,10);title('Step response of the system with K=400') %Find the step response of the system
grid on