function [u] = rec(x,C1,C2)
if x<=C1 || x>=C2
    u=0;
else
    u=1;
end
end

