function [u] = z(x,L,R)
if x<=L
    u=1;
elseif (x>L) && (x<(L+R)/2)
    u=1-2*((L-x)/(R-L))^2;
elseif (x>=(L+R)/2) && (x<R)
    u=2*((R-x)/(R-L))^2;
else
    u=0;
end
end

