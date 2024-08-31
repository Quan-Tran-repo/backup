function plot_right(L,R)
y=[];
for i=(L-2):0.1:(R+2)
    if (i<L)
        y=[y 0];
    elseif (i>=L) && (i<=R)
        y=[y (i-L)/(R-L)];
    else 
        y=[y 1];
    end
end
t=(L-2):0.1:(R+2);
plot(t,y);
end

