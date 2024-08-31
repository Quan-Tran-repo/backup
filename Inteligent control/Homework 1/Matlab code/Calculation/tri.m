function [u] = tri(x,L,C,R)
if x<=L
    u=0;
elseif (x>L) && (x<C)
    u=(x-L)/(C-L);
elseif (x>=C) && (x<R)
    u=(R-x)/(R-C);
else
    u=1;
end
end

