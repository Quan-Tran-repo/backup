function plot_dsig(S1,C1,S2,C2)
x=-10:0.1:10;
y=[];
for i=-10:0.1:10
    y=[y 1/(1+exp(-S1*(i-C1)))-1/(1+exp(-S2*(i-C2)))];
end
plot(x,y);
end

