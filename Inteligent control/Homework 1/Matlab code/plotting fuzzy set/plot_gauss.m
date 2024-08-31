function plot_gauss(W,C)
x=-100:0.1:100;
y=[];
for i=-100:0.1:100
    y=[y exp(-(i-C)^2/(2*W^2))];
end
plot(x,y);
end

