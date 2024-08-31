
A=[0 1 0; 0 -4 -0.03;0 0.6 -10];
B=[0;0;8.237];
C=[1 0 0];
%L=[-11; 116.982;24287.4];
%L=[1; 20.982; 4161.267];
%L=[16; 35.982; 3.6];
L=[46; 653.982; 12688.267];

clc;
close all;
figure(); 
plot(s1.time,s1.signals.values);
hold on;
plot(s2.time,s2.signals.values(:,2));
hold on;
plot(s3.time,s3.signals.values(:,2));
hold on;
plot(s4.time,s4.signals.values(:,2));
hold on;
grid on;
xlabel('time(s)');
ylabel('angular position');

figure(); 
xlabel('time(s)');
ylabel('amplitude');
plot(s1b.time,s1b.signals.values);
hold on;
plot(s2b.time,s2b.signals.values(:,2));
hold on;
plot(s3b.time,s3b.signals.values(:,2));
hold on;
plot(s4b.time,s4b.signals.values(:,2));
hold on;
grid on;
xlabel('time(s)');
ylabel('angular velocity');

figure(); 
plot(s1c.time,s1c.signals.values);
hold on;
plot(s2c.time,s2c.signals.values(:,2));
hold on;
plot(s3c.time,s3c.signals.values(:,2));
hold on;
plot(s4c.time,s4c.signals.values(:,2));
hold on;
grid on;
xlabel('time(s)');
ylabel('current(A)');


