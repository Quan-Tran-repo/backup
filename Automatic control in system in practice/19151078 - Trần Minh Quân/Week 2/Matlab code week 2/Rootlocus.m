clc; clear all; close all;
%% Plot the root locus of the system
G=tf([1],conv([1 0.2],[1 8 20]));
rlocus(G);
grid on