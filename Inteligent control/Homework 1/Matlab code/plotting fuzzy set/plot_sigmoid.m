function plot_sigmoid(S,C)
x=-10:0.1:10;
y=[];
for i=-10:0.1:10
    y=[y 1/(1+exp(-S*(i-C)))];
end
plot(x,y);
end

