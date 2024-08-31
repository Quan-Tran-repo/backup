clc;close all;
%% Plot step response of the system
figure;
plot(Data1.time,Data1.signals.values);hold on;
plot(Data2.time,Data2.signals.values);hold on;
plot(Data3.time,Data3.signals.values);hold on;
plot(Data4.time,Data4.signals.values);hold on;
plot(Data5.time,Data5.signals.values);hold on;
grid on;
%% Find POT
x1=max(Data1.signals.values);
y1=Data1.signals.values(60000);
x2=max(Data2.signals.values);
y2=Data2.signals.values(60000);
x3=max(Data3.signals.values);
y3=Data3.signals.values(60000);
x4=max(Data4.signals.values);
y4=Data4.signals.values(60000);
x5=max(Data5.signals.values);
y5=Data5.signals.values(60000);
a1=(x1-y1)/y1;
a2=(x2-y2)/y2;
a3=(x3-y3)/y3;
a4=(x4-y4)/y4;
a5=(x5-y5)/y5;
POT=[a1 a2 a3 a4 a5]
%% Find steady state error
e1=100-y1;
e2=100-y2;
e3=100-y3;
e4=100-y4;
e5=100-y5;
Error=[e1 e2 e3 e4 e5]
%% Finding rise time 
%Find time when it reached 10% its steady state
for i=1:60000
    p=Data1.signals.values(i);
    if (p>=Data1.signals.values(60000)/10) && (p<=Data1.signals.values(60000)*11/100)
        tempA10=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    q=Data1.signals.values(i);
    if (q>=Data1.signals.values(60000)*9/10) && (q<=Data1.signals.values(60000)*91/100)
        tempA90=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    p=Data2.signals.values(i);
    if (p>=Data2.signals.values(60000)/10) && (p<=Data2.signals.values(60000)*11/100)
        tempB10=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    q=Data2.signals.values(i);
    if (q>=Data2.signals.values(60000)*9/10) && (q<=Data2.signals.values(60000)*91/100)
        tempB90=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    p=Data3.signals.values(i);
    if (p>=Data3.signals.values(60000)/10) && (p<=Data3.signals.values(60000)*11/100)
        tempC10=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    q=Data3.signals.values(i);
    if (q>=Data3.signals.values(60000)*9/10) && (q<=Data3.signals.values(60000)*91/100)
        tempC90=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    p=Data4.signals.values(i);
    if (p>=Data4.signals.values(60000)/10) && (p<=Data4.signals.values(60000)*11/100)
        tempD10=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    q=Data4.signals.values(i);
    if (q>=Data4.signals.values(60000)*9/10) && (q<=Data4.signals.values(60000)*91/100)
        tempD90=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    p=Data5.signals.values(i);
    if (p>=Data5.signals.values(60000)/10) && (p<=Data5.signals.values(60000)*11/100)
        tempE10=i;
       break
    end
end
%Find time when it reached 10% its steady state
for i=1:60000
    q=Data5.signals.values(i);
    if (q>=Data5.signals.values(60000)*9/10) && (q<=Data5.signals.values(60000)*91/100)
        tempE90=i;
       break
    end
end
t1=tempA90-tempA10;
t2=tempB90-tempB10;
t3=tempC90-tempC10;
t4=tempD90-tempD10;
t5=tempE90-tempE10;
T10= [tempA10 tempB10 tempC10 tempD10 tempE10];
T10= T10/100
T90=[tempA90 tempB90 tempC90 tempD90 tempE90];
T90= T90/100
Response_time=[t1 t2 t3 t4 t5];
Response_time=Response_time/100
%% Finding settling time
temp1=[ ];
for i=1:60000
    p=Data1.signals.values(i);
    q=Data1.signals.values(60000);
    if ((p>=q*98/100) && (p<=q*99/100))||((p>=q*102/100) && (p<=q*103/100))
        temp1=[temp1 i];
    end
end
temp2=[ ];
for i=1:60000
    p=Data2.signals.values(i);
    q=Data2.signals.values(60000);
    if ((p>=q*98/100) && (p<=q*99/100))||((p>=q*102/100) && (p<=q*103/100))
        temp2=[temp2 i];
    end
end
temp3=[ ];
for i=1:60000
    p=Data3.signals.values(i);
    q=Data3.signals.values(60000);
    if ((p>=q*98/100) && (p<=q*99/100))||((p>=q*102/100) && (p<=q*103/100))
        temp3=[temp3 i];
    end
end
temp4=[ ];
for i=1:60000
    p=Data4.signals.values(i);
    q=Data4.signals.values(60000);
    if ((p>=q*98/100) && (p<=q*99/100))||((p>=q*102/100) && (p<=q*103/100))
        temp4=[temp4 i];
    end
end
temp5=[ ];
for i=1:60000
    p=Data5.signals.values(i);
    q=Data5.signals.values(60000);
    if ((p>=q*98/100) && (p<=q*99/100))||((p>=q*102/100) && (p<=q*103/100))
        temp5=[temp5 i];
    end
end
St1=max(temp1);
St2=max(temp2);
St3=max(temp3);
St4=max(temp4);
St5=max(temp5);
Settling_time=[St1 St2 St3 St4 St5]/100