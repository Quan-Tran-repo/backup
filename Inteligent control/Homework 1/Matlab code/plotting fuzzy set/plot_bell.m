function plot_bell(W,S,C)
x=-100:0.1:100;
y=[];
for i=-100:0.1:100
    y=[y 1/(1+abs((i-C)/W)^(2*S))];
end
plot(x,y);
end

