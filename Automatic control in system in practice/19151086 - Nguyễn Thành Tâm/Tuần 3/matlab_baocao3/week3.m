clc 
G=tf(1,conv([1 0.2],[1 8 20]))
Gc=feedback(77.4*G,1)
step(Gc,10)
grid on
hold on
G=tf(1,conv([1 0.2],[1 8 20]))
Gb=feedback(44*G,1)
step(Gb,10)
