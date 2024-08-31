function plot_left(L,R)
y=[];
for i=(L-2):0.1:(R+2)
    if (i<L)
        y=[y 1];
    elseif (i>=L) && (i<=R)
        y=[y (R-i)/(R-L)];
    else 
        y=[y 0];
    end
end
t=(L-2):0.1:(R+2);
plot(t,y);
end

