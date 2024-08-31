clc; clear all; close all;
%% Step response of the system when K reached it limit at 172
G=tf(172,conv([1 0.2],[1 8 20]));
Gk=feedback(G,1);
figure;step(Gk); title('Step response of the system with K=Kgh=172');
%% Step response of the system with K=44 (POT = 25%)
G1=tf(44,conv([1 0.2],[1 8 20]));
Gk1=feedback(G1,1);
figure;step(Gk1,5); title('Step response of the system with K=44');
S1=stepinfo(Gk1)
%% Step response of the system with K=52 (txl=4s)
G2=tf(52,conv([1 0.2],[1 8 20]));
Gk2=feedback(G2,1);
figure;step(Gk2,5); title('Step response of the system with K=52');
S2=stepinfo(Gk2,'SettlingTimeThreshold',0.02)
%% Plot both step response from b and c
figure; step(Gk1,5); title('Step response of both system b and c'); hold on;
step(Gk2,5); 
legend('K=44(POT 25%)','K=52(txl=4s)');
grid on;