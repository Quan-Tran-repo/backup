function C=min_intersect(A,B)
n=length(A(1,:));
C=[];
for i=1:n
   if (A(2,i)<B(2,i))
       C=[C A(2,i)];
   else 
       C=[C B(2,i)];
   end
end 
end

