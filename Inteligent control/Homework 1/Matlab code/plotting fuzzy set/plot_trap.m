function plot_trap(L,C1,C2,R)
y=[];
for i=(L-2):0.1:(R+2)
    if (i<L) || (i>R)
        y=[y 0];
    elseif (i>=L) && (i<=C1)
        y=[y (i-L)/(C1-L)];
    elseif (i>=C2) && (i<=R) 
        y=[y (R-i)/(R-C2)];
    else 
        y=[y 1];
    end
end
t=(L-2):0.1:(R+2);
plot(t,y);
end
