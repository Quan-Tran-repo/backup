function [u] = right(x,L,R)
if x<=L
    u=0;
elseif (x>L) && (x<R)
    u=(R-x)/(R-L);
else
    u=1;
end
end

