function C=sum_union(A,B)
n=length(A(1,:));
C=[];
for i=1:n
    temp=A(2,i)+B(2,i);
    if (temp>1)
        temp=1;
    end
    C=[C temp];
end 
end

