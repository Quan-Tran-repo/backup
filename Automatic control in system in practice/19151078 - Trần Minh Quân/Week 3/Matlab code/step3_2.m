clc; clear all; close all;
%% Step response of the system when K reached it limit at 102
G=tf([102 102],conv([1 5 0],[1 3 9]));
Gk=feedback(G,1);
figure;step(Gk); title('Step response of the system with K=Kgh=102');
%% Step response of the system with K=9.21 (POT = 25%)
G1=tf([9.21 9.21],conv([1 5 0],[1 3 9]));
Gk1=feedback(G1,1);
figure;step(Gk1); title('Step response of the system with K=9.21');
S1=stepinfo(Gk1)
%% Step response of the system with K=19.2 (txl=4s)
G2=tf([19.2 19.2], conv([1 5 0],[1 3 9]));
Gk2=feedback(G2,1);
figure;step(Gk2,5); title('Step response of the system with K=19.2');
S2=stepinfo(Gk2,'SettlingTimeThreshold',0.02)
%% Plot both step response from b and c
figure; step(Gk1); title('Step response of both system b and c'); hold on;
step(Gk2);
legend('K=9.21(POT 25%)','K=19.2(txl=4s)');
grid on;