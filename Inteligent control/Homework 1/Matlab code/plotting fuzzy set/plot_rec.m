function plot_rec(C1,C2)
y=[];
for i=(C1-2):0.1:(C2+2)
    if (i<C1) || (i>C2)
        y=[y 0];
    else 
        y=[y 1];
    end
end
t=(C1-2):0.1:(C2+2);
plot(t,y);
end
