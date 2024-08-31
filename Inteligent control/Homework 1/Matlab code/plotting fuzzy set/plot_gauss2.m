function plot_gauss2(W1,C1,W2,C2)
x=-100:0.1:100;
y=[];
for i=-100:0.1:100
    if (i<=C1)
        y=[y exp(-(i-C1)^2/(2*W1^2))];
    elseif (i>=C2)
        y=[y exp(-(i-C2)^2/(2*W2^2))];
    else
        y=[y 1];
    end
end
plot(x,y);
end

