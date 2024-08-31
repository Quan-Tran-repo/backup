clc; clear all;
R=[0.66 0.5 0.4;
    1 0.75 0.6;
    0.75 1 0.8];
A=[0.5 1 0.5;
    2 3 4];
n=length(A(1,:));
m=length(R(:,1));
C=[0 0 0;
    3 4 5];
temp=[];
for i=1:m
    for j=1:n
    if (A(1,j)<R(j,i))
        temp=[temp A(1,j)];
    else
        temp=[temp R(j,i)];
    end
    end
    C(1,i)=max(temp);
    temp=[];
end
C
