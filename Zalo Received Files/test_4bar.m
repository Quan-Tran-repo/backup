% Input 
AB = 0.055;
BC = 0.16;
DC = 0.4;
xD = 0; yD = 0;
rD = [xD yD 0];
tstep = pi/8;
beta0 = 2*pi/45;
alpha0 = pi/2;
frs = 8;
astep = 2*pi/16;

%Position Analysis
xC0 = DC*cos(beta0);
yC0 = DC*sin(beta0);
xA = xC0;
yA = yC0-0.16-0.055;
ADx = atan(yA/xA);


% Preallocating arrays for speed 
k = 0;                      % counter k
acol = zeros(1,frs);      
xBcol  = zeros(1,frs);
yBcol  = zeros(1,frs);
xCcol  = zeros(1,frs);
yCcol  = zeros(1,frs);
bcol   = zeros(1,frs);

for i = 1:1:frs+1
    acol(i) = -pi/2 + astep*k;
    k = k+1;
    xBcol(i) = AB*cos(acol(i))+xA;
    yBcol(i) = AB*sin(acol(i))+yA;
    
    % Phương trình đư�?ng tròn tâm D bán kính 100 với C luôn trên đó 
    syms xC yC
    eqnC1 = xC^2 + yC^2 == 0.4^2;
    eqnC2 = (xC-xBcol(i))^2 + (yC-yBcol(i))^2 == BC^2;
    Csol = solve(eqnC1,eqnC2,xC,yC);
    xC = eval(Csol.xC);
    yC = eval(Csol.yC);
    if yC(1) < yBcol(i)
        yCcol(i) = yC(2);
        xCcol(i) = xC(2);
    else
        yCcol(i) = yC(1);
        xCcol(i) = xC(1);
    end
    vecAB = [xBcol(i)*xCcol(i)-xBcol(i)*yBcol(i)-yCcol(i)];
    vecDC -xA yBcol(i)-yA];
    vecBC = [= [xCcol(i)-xD yCcol(i)-yD];
    bcol(i) = atan(yCcol(i)/xCcol(i));
    plot([xA,xBcol(i)],[yA,yBcol(i)],'b-o',...
         [xBcol(i),xCcol(i)],[yBcol(i),yCcol(i)],'b-o',...
         [xCcol(i),xD],[yCcol(i), yD],'b-o')
    axis([-0.1 0.5 -0.25 0.15]);
    grid on;
    getframe;
    omega3 = [0 0 pi/3]
end
 