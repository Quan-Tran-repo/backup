function [u] = sigmoid_Q(x,S,C)
u=1/(1-exp(-S*(x-C)));
end
