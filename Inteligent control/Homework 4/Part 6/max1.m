function C = max1(C1,C2,C3)
n=length(C1(1,:));
C=C3;
for i=1:n
    C(2,i)=max(C1(2,i),max(C2(2,i),C3(2,i)));
end
end

