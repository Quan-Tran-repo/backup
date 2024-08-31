function plot_s(L,R)
y=[];
for i=(L-2):0.1:(R+2)
    if i<=L
        y=[y 0];
    elseif (i>L) && (i<(L+R)/2)
        y=[y 2*((L-i)/(R-L))^2];
    elseif (i>=(L+R)/2) && (i<R)
        y=[y 1-2*((R-i)/(R-L))^2];
    else
        y=[y 1];
    end
end
t=(L-2):0.1:(R+2);
plot(t,y);
end

