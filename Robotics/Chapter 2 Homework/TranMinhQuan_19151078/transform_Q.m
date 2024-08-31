function out = transform_Q(R,x,y,z)
out=[R(1,1) R(1,2) R(1,3) x;
     R(2,1) R(2,2) R(2,3) y;
     R(3,1) R(3,2) R(3,3) z;
     0      0      0      1];
end

