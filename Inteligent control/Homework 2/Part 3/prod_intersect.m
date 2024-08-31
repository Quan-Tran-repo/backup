function C = prod_intersect(A,B)
n=length(A(1,:));
C=[];
for i=1:n
    temp=A(2,i)*B(2,i);
    C=[C temp];
end 
end

