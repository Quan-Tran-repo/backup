function C = prod1(A,B,x)
m=length(A(1,:));
n=length(B(1,:));
C=B;
i=0;
t=x;
% Find x's location
while(t==x)
    i=i+1;
    if (x==A(1,i))
        t=i;
    end 
end

for j=1:n
  C(2,j)=B(2,j)*A(2,t);
end
end

