clc 
G1=tf(5,1)
G2=tf(1,[1 1])
G3=tf([1 0],1) %% =G5
G4=tf(1,[1 1]) %% = G2
G5=tf([1 0],1)
G6=tf([1 2],1)
H1=tf(1,1)
H2=tf([0 1],[1 0]) 
H3=tf([0 3],[4 1])
G6g4=G6*G4;
GA= G2*(G3+G6g4);
G4G5=G4*G5;
GB=feedback(G4G5,H3);
GC=feedback(GA*GB,H2);
GD=feedback(GC*G1,H1);
GD=minreal(GD)
H=ss(GD)
