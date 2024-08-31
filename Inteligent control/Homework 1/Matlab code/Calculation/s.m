function [u] = s(x,L,R)
if x<=L
    u=0;
elseif (x>L) && (x<(L+R)/2)
    u=2*((L-x)/(R-L))^2;
elseif (x>=(L+R)/2) && (x<R)
    u=1-2*((R-x)/(R-L))^2;
else
    u=1;
end
end

