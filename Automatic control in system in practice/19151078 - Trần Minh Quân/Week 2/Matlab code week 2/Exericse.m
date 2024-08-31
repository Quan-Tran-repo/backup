clc; clear all; close all
%% Plot root locus of the system
G=tf([1 1],conv([1 5 0],[1 3 9]));
figure; rlocus(G);
grid on;
%% Plot bode diagram of the system
G=tf([57 57],conv([1 5 0],[1 3 9]));
figure;bode(G);title('Bode diagram of the system when K = Kgh/2=57');
figure;margin(G);
%% Plot Nyquist diagram of the system
G=tf([57 57],conv([1 5 0],[1 3 9]));
figure;nyquist(G);title('Nyquist diagram of the system when K = Kgh/2=57');


