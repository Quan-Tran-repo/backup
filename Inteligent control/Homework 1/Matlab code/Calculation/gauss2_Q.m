function [u] = gauss2_Q(x,W1,C1,W2,C2)
if(x<=C1)
    u=exp(-(x-C1)^2/(2*W1^2));
elseif x>=C2
    u=exp(-(x-C2)^2/(2*W2^2));
else
    u=1;
end

