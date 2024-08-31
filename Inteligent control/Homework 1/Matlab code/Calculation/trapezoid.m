function [u] = trapezoid(x,L,C1,C2,R)
if x<=L
    u=0;
elseif (x>L) && (x<=C1)
    u=(x-L)/(C1-L);
elseif (x>C1) && (x<=C2)
    u=1;
elseif (x>C2) && (x<R)
    u=(R-x)/(R-C2);
else
    u=1;
end
end

