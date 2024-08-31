function plot_pi(L,C,R)
y=[];
for i=(L-2):0.1:(R+2)
    if (i<=L) || (i>=R)
        y=[y 0];
    elseif (i>L) && (i<(L+C)/2)
        y=[y 2*((L-i)/(C-L))^2];
    elseif (i>=(L+C)/2) && (i<C)
        y=[y 1-2*((C-i)/(C-L))^2];
    elseif (i>=C) && (i<(R+C)/2)
        y=[y 1-2*((C-i)/(C-R))^2];
    else
        y=[y 2*((R-i)/(C-R))^2];
    end
end
t=(L-2):0.1:(R+2);
plot(t,y);
end

