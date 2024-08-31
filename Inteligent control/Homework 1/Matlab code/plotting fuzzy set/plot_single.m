function plot_single(C)
y=[];
for i=(C-2):0.001:(C+2)
    if i==C
        y=[y 1];
    else 
        y=[y 0];
    end
end
t=(C-2):0.001:(C+2);
plot(t,y);
end

