clc;
close all;
figure();
%sai so
plot(ss1.time  ,ss1.signals.values  );
hold on;
plot(ss5.time  ,ss5.signals.values  );
hold on;

plot(ss2.time  ,ss2.signals.values  );
hold on;
plot(ss3.time  ,ss3.signals.values  );
hold on;
plot(ss4.time  ,ss4.signals.values  );
hold on;
grid on;
ylabel('Error');
xlabel('Time(s)');
%tin hieu
figure();
plot(th1.time  ,th1.signals.values  );
hold on;
plot(th5.time  ,th5.signals.values  );
hold on;

plot(th2.time  ,th2.signals.values  );
hold on;
plot(th3.time  ,th3.signals.values  );
hold on;
plot(th4.time  ,th4.signals.values  );
hold on;
plot(th5.time  ,th5.signals.values  );
hold on;
grid on;
ylabel('Amplitude');
xlabel('Time(s)');
%output
figure();
plot(set.time  ,set.signals.values  );
hold on;
plot(out1.time  ,out1.signals.values  );
hold on;
plot(out5.time  ,out5.signals.values  );
hold on;
plot(out2.time  ,out2.signals.values  );
hold on;
plot(out3.time  ,out3.signals.values  );
hold on;
plot(out4.time  ,out4.signals.values  );
hold on;

grid on;
ylabel('Length(cm)');
xlabel('Time(s)');