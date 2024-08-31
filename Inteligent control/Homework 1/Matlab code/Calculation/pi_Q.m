function [u] = pi_Q(x,L,C,R)
if x<=L
    u=1;
elseif (x>L) && (x<(L+C)/2)
    u=1-2*((L-x)/(C-L))^2;
elseif (x>=(L+C)/2) && (x<C)
    u=2*((C-x)/(C-L))^2;
elseif (x>C) && (x<(R+C)/2)
    u=2*((C-x)/(C-R))^2;
elseif
    u=1-2*((R-x)/(C-R))^2;
else
    u=0;
end
end