function [u] = doublesig(x,S1,C1,S2,C2)
u=1/(1-exp(-S1*(x-C1)))-1/(1-exp(-S2*(x-C2)));
end

