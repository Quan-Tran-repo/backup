function [u] = left(x,L,R)
if x<=L
    u=1;
elseif (x>L) && (x<R)
    u=(R-x)/(R-L);
else
    u=0;
end
end

