clc; clear all;
Tab=[0.25 0.43 0.86 5;
     0.87 -0.5 0 -4;
     0.43 0.75 -0.5 3;
     0 0 0 1]
 Tba=inv(Tab)
 Tba(2,4)