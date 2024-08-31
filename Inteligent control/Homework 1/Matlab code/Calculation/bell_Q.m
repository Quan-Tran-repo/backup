function [u] = bell_Q(x,W,S,C)
u=1/(1+abs((x-C)/W)^(2*S));
end

