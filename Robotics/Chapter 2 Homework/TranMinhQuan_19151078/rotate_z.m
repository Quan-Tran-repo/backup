function out=rotate_z(A,theta)
temp=[cosd(theta) -sind(theta) 0;
      sind(theta)  cosd(theta) 0;
      0            0           1];
out=temp*A;
end

