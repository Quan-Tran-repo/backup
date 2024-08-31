clc; clear all;
%% Declaration
Tua=[0.866 -0.5  0 11;
     0.5   0.866 0 -1;
     0     0     1 8;
     0     0     0 1]
Tba=[1 0 0 0;
     0 0.866 -0.5 10;
     0 0.5 0.866 -20;
     0 0 0 1]
 Tcu=[0.866 -0.5 0 -3;
      0.433 0.75 -0.5 -3;
      0.25 0.433 0.866 3;
      0 0 0 1]
  %% Solution
  Tca=Tcu*Tua   %Transform from C to U then from U to A
  Tac=inv(Tca)  %Inverse matrix Tca will find the transform matrix from A to C
  Tbc=Tba*Tac   %Transform from B to A then from A to C