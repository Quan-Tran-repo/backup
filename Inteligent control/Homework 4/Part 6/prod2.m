function C = prod2(A1,A2,B,x,y)
n=length(B(1,:));
C=B;
i=0;
t1=x;t2=y;
% Find x's location
while(t1==x)
    i=i+1;
    if (x==A1(1,i))
        t1=i;
    end 
end
i=0;
% Find y's location
while (t2==y)
    i=i+1;
    if (y==A2(1,i))
        t2=i;
    end 
end
t=A1(2,t1)*A2(2,t2);
for j=1:n
  C(2,j)=B(2,j)*t;
end
end