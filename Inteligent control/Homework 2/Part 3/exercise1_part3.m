clc; clear all; close all;
%% a)Min
A=[-3 -2 -1 0 1 2 3;
    0.5 1 0.6 0.3 0.1 0.3 0.7];
B=[-3 -2 -1 0 1 2 3;
    0.3 0.4 0.3 0.5 1 0.5 0];
C=min_intersect(A,B)
%% a) PROD
A=[-2 -1 0 1 2;
    1 0.6 0.3 0.1 0];
B=[-2 -1 0 1 2;
    0 0.5 1 0.5 0];
C=prod_intersect(A,B)
%% b) Max
A=[-2 -1 0 1 2;
    1 0.6 0.3 0.1 0];
B=[-2 -1 0 1 2;
    0 0.5 1 0.5 0];
n=length(A(1,:));
C=max_union(A,B)
%% b) Sum
A=[-2 -1 0 1 2;
    1 0.6 0.3 0.1 0];
B=[-2 -1 0 1 2;
    0 0.5 1 0.5 0];
C=sum_union(A,B)