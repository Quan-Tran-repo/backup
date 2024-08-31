function [u] = gauss_Q(x,W,C)
u=exp(-(x-C)^2/(2*W^2));
end

