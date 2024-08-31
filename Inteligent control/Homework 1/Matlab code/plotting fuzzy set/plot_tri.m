function plot_tri(L,C,R)
y=[];
for i=(L-2):0.1:(R+2)
    if (i<L) || (i>R)
        y=[y 0];
    elseif (i>=L) && (i<=C)
        y=[y (i-L)/(C-L)];
    else 
        y=[y (R-i)/(R-C)];
    end
end
t=(L-2):0.1:(R+2);
plot(t,y);
end

