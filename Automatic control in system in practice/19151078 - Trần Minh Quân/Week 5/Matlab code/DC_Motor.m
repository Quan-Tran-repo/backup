function [theta_2d,i_d] = DC_Motor(theta_d,i,ea,Td)
%% Declare the parameters
Ra=2;
La=0.5;
Jm=0.02;
Dm=0.002953;
Kt=1.28;
Kb=0.0015;
%% System differential equations:
i_d=1/La*ea-Kb*La-theta_d-Ra/La*i;
theta_2d=Kt/Jm*i-Dm/Jm*theta_d-Td;