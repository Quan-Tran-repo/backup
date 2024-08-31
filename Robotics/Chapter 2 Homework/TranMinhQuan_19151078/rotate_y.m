function out=rotate_y(A,theta)
temp=[cosd(theta)  0    sind(theta);
      0            1    0;
      -sind(theta) 0    cosd(theta)];
out=temp*A;
end
