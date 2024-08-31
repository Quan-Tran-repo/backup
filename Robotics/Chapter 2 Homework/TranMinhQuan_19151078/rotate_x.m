function out=rotate_x(A,theta)
temp=[1     0           0;
      0     cosd(theta) -sind(theta);
      0     sind(theta) cosd(theta)];
out=temp*A;
end

