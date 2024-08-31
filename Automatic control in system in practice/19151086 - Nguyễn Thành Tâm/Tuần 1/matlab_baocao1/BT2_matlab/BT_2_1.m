clc
%k=10
G=tf(10,[1 8.2 21.6 4])
bode(G,{0.1,100})
margin(G)
figure
Gk=feedback(G,1)
pole(G)
step(Gk,10)
figure
grid on

%k=400
G1=tf(400,conv([1 0.2],[1 8 20]))
bode(G1,{0.1,100})
margin(G)
figure
Gt=feedback(G1,1)
pole(G1)
step(Gt,10)

grid on