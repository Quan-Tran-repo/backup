function C = max5(C1,C2,C3,C4,C5)
n=length(C1(1,:));
C=C3;
for i=1:n
    C(2,i)=max(C1(2,i),max(max(max(C2(2,i),C3(2,i)),C4(2,i)),C5(2,i)));
end
end

