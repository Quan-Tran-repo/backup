function [x,y] = difuz(A)
% Find x
n=length(A(1,:));
temp=0;
t=0;
j=0;
for i=1:n
    temp=temp+A(1,i)*A(2,i);
end
x=temp/sum(A(2,:));
% Find y
while (t==0)
    j=j+1;
    if x<A(1,j)
        t=j;
    end
end
y=(A(2,t)-A(2,t-1))/(A(1,t)-A(1,t-1))*(x-A(1,t-1))+A(2,j-1);
end

