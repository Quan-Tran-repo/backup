function [ENA,In1,In2] = L298(in1)
ENA=abs(in1);
if     in1>0
    IN1=0; IN2=1;
elseif in1<0
    IN1=1; IN2=0;
else 
    IN1=0;IN2=0;
end
end
