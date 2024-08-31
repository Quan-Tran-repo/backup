clc; clear all;
A=[0 1 2 3 4 5 6 7 8;
    0 0.5 1 1 1 0.5 0.5 0.25 0];
B=[0 1 2 3 4 5 6 7 8;
    0 0.5 0.5 1 0.5 0 0 0 0];
%% 2) Max
n=length(A(1,:));
m=length(B(1,:));
C=[];
temp=[];
for i=1:n
    for j=1:m
        if (A(2,i)>B(2,j))
            temp=[temp A(2,i)];
        else
            temp=[temp B(2,j)];
        end
    end
    C=[temp;C];
    temp=[];
end
C
%% 2) Sum
n=length(A(1,:));
m=length(B(1,:));
C=[];
temp=[];
for i=1:n
    for j=1:m
        temp1=A(2,i)+B(2,j);
        if (temp1<1)
            temp=[temp temp1];
        else
            temp=[temp 1];
        end
    end
    C=[temp;C];
    temp=[];
end
C