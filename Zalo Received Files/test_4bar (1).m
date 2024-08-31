% Input 
AB = 0.055;
BC = 0.16;
DC = 0.4;
xD = 0; yD = 0;
rD = [xD yD 0];
tstep = pi/8;
beta0 = 2*pi/45;
alpha0 = pi/2;

%Position Analysis
xC0 = DC*cos(beta0);
yC0 = DC*sin(beta0);
xA = xC0;
yA = yC0-0.16-0.055;
ADx = atan(yA/xA);

% Gravitational force

dball = 0.04;
rhopoly = 1200; %(kg/m^3)
rhosteel = 7860; %(kg/m^3)
w = 5*10^-3; %default width of links
h = 15*10^-3; %default height of links 
phihole = 5*10^-3; %default hole diameter 
m1 = AB*h*w*rhopoly + pi*(h/2)^2*w*rhopoly - pi*(phihole/2)^2*w*rhopoly;
m2 = BC*h*w*rhopoly + pi*(h/2)^2*w*rhopoly - pi*(phihole/2)^2*w*rhopoly;
m3 = DC*h*w*rhopoly + pi*(h/2)^2*w*rhopoly - pi*(phihole/2)^2*w*rhopoly;
mball = (4/3)*pi*(dball/2)^3*rhosteel;
g = 9.8;
P1 = [0 -m1*g 0];
P2 = [0 -m2*g 0];
P3 = [0 -m3*g 0];
Pball = [0 -mball*g 0];
    
% Moment of Inertia, assuming all links are rectangular prisms turning
% about z axis
    
I1 = m1*(AB^2+h^2)/12;
I2 = m2*(BC^2+h^2)/12;
I3 = m3*(DC^2+h^2)/12;

% User define initial position and number of frames

phiorg = input('Please input starting position (from -5*pi/12 to 0): ');
frs = input('Please input desired number of frames (recommended:12): ');
astep = abs(phiorg)*2/frs;


% Preallocating arrays for speed 
k = 0;                      % counter k
acol = zeros(1,frs);
bcol   = zeros(1,frs);
xBcol  = zeros(1,frs);  
yBcol  = zeros(1,frs);
xCcol  = zeros(1,frs);
yCcol  = zeros(1,frs);
%vC3col = zeros(1,frs);
omega1col = zeros(1,frs);
omega2col = zeros(1,frs);
omega3col = zeros(1,frs);
aC3col = zeros(1,frs);
aB2col = zeros(1,frs);
R03col = zeros(1,frs);
R23col = zeros(1,frs);
r03xcol = zeros(1,frs);
r03ycol = zeros(1,frs);
r23xcol = zeros(1,frs);
r23ycol = zeros(1,frs);
R32col = zeros(1,frs);
R12col = zeros(1,frs);
r12xcol = zeros(1,frs);
r12ycol = zeros(1,frs);
R01col = zeros(1,frs);
R21col = zeros(1,frs);
r01xcol = zeros(1,frs);
r01ycol = zeros(1,frs);
Fin3col = zeros(1,frs);
Fin2col = zeros(1,frs);
Fin1col = zeros(1,frs);
Min1col = zeros(1,frs);
Min2col = zeros(1,frs);
Min3col = zeros(1,frs);
alpha2col = zeros(1,frs);
alpha1col = zeros(1,frs);
Mdcol = zeros(1,frs);
P1col = zeros(1,frs);
P2col = zeros(1,frs);
P3col = zeros(1,frs);
Pballcol = zeros(1,frs);

for i = 1:1:frs+1
    a = phiorg + astep*k;
    acol(i) = rad2deg(a);
    k = k+1;
    xBcol(i) = AB*cos(a)+xA;
    yBcol(i) = AB*sin(a)+yA;
    P1col(i) = P1(2);
    P2col(i) = P2(2);
    P3col(i) = P3(2);
    Pballcol(i) = Pball(2);
    
    % Phương trình đường tròn tâm D bán kính 100 với C luôn trên đó 
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
    vecAB = [xBcol(i)-xA yBcol(i)-yA 0];
    vecBC = [xCcol(i)-xBcol(i) yCcol(i)-yBcol(i) 0];
    vecDC = [xCcol(i)-xD yCcol(i)-yD 0];
    vecBA = -vecAB;
    vecCB = -vecBC;
    bcol(i) = atand(yCcol(i)/xCcol(i));
    plot([xA,xBcol(i)],[yA,yBcol(i)],'b-o',...
         [xBcol(i),xCcol(i)],[yBcol(i),yCcol(i)],'b-o',...
         [xCcol(i),xD],[yCcol(i), yD],'b-o')
    axis([-0.1 0.5 -0.25 0.15]);
    grid on;
    getframe;

    %Velocity Analysis 

    omega3 = [0 0 4*pi/45];
    vD = [0 0 0];
    vC3 = vD + cross(omega3,vecDC);
    omega3col(i) = norm(omega3);
    %vC3col(i) = norm(vC3);
    
    %Velocity Analysis 
    syms omega2z omega1z
    omega2 = [0 0 omega2z];
    omega1 = [0 0 omega1z];
    eqom = vC3 - cross(omega1,vecBA) - cross(omega2,vecCB);
    eqomx = eqom(1);
    eqomy = eqom(2);
    solvom = solve(eqomx,eqomy,omega1z,omega2z);
    omega1z = eval(solvom.omega1z);
    omega2z = eval(solvom.omega2z);
    omega1col(i) = omega1z;
    omega2col(i) = omega2z;
    omega2 = [0 0 omega2z]; %Renewal
    omega1 = [0 0 omega1z]; %Renewal

    % Acceleration Analysis 
    
    aD = [0 0 0];
    aA = [0 0 0];
    alpha3 = [0 0 0];
    aC3 = aD + cross(alpha3,vecDC) - dot(omega3,omega3)*vecDC;
    aC3col(i) = norm(aC3);

    % Acceleration of link
    syms alpha2z alpha1z
    alpha2 = [0 0 alpha2z];
    alpha1 = [0 0 alpha1z];
    eqaB2 = aC3 + cross(alpha2,vecCB) - dot(omega2,omega2)*vecCB;
    eqaB1 = aA + cross(alpha1,vecBA) - dot(omega1,omega1)*vecBA;
    eqaB  = eqaB1 - eqaB2;
    eqaBx = eqaB(1);
    eqaBy = eqaB(2);
    solaB = solve(eqaBx,eqaBy,alpha2z,alpha1z);
    alpha2z = eval(solaB.alpha2z);
    alpha1z = eval(solaB.alpha1z);
    alpha2col(i)=alpha2z;
    alpha1col(i)=alpha1z;
    alpha2 = [0 0 alpha2z]; %Renewal
    alpha1 = [0 0 alpha1z]; %Renewal
    aB2 = aC3 + cross(alpha2,vecCB) - dot(omega2,omega2)*vecCB;

    % Force Analysis

    % Center of mass 
    xC3 = (xD + xCcol(i))/2;
    yC3 = (yD + yCcol(i))/2;
    xC2 = (xCcol(i)+xBcol(i))/2;
    yC2 = (yCcol(i)+yBcol(i))/2;
    xC1 = (xBcol(i)+xA)/2;
    yC1 = (yBcol(i)+yA)/2;
    vecC2B = [xBcol(i)-xC2 yBcol(i)-yC2 0];
    vecC2C = [xCcol(i)-xC2 yCcol(i)-yC2 0];
    vecC1B = [xBcol(i)-xC1 yBcol(i)-yC1 0];
    vecC1A = [xA-xC1 yA-yC1 0];
    vecDC3 = [xC3 - xD yC3-yD 0];
    aCent3 = aC3/2;
    aCent2 = (aB2 + aC3)/2;
    aCent1 = (aB2 + aA)/2;
    
    % On link 3, assuming the ball lies directly above the link's center of
    % mass

    syms r03y r03x r23y r23x  
    Fin3 = -m3*aCent3;
    Min3 = -I3*alpha3;
    R03 = [r03x r03y 0];
    R23 = [r23x r23y 0];
    eqF3 =  R03 + R23 + Pball + P3 + Fin3;
    eqF3x = eqF3(1);
    eqF3y = eqF3(2);
    eqM3D = cross(vecDC,R23) + cross(vecDC3,Pball + P3 + Fin3) + Min3;
    eqM3Dz = eqM3D(3);

    % On link 2

    syms r12x r12y 
    Fin2 = -m2*aCent2;
    Min2 = -I2*alpha2;
    R12 = [r12x r12y 0];
    R32 = -R23;
    eqF2 = R32 + R12 + P2 + Fin2;
    eqF2x = eqF2(1);
    eqF2y = eqF2(2);
    eqM2 = cross(vecC2C,R32) + cross(vecC2B,R12) + Min2;
    eqM2z = eqM2(3);

    % On link 1

    syms r01x r01y Mdz
    Fin1 = -m1*aCent1;
    Min1 = -I1*alpha1;
    R01 = [r01x r01y 0];
    R21 = -R12;
    Md = [0 0 Mdz];
    eqF1 = R01 + R21 + P1 + Fin1;
    eqF1x = eqF1(1);
    eqF1y = eqF1(2);
    eqM1A = cross(vecAB,R21) + cross(-vecC1A,P1) + cross(-vecC1A,Fin1) + Min1 + Md;
    eqM1Az = eqM1A(3);
    solF = solve(eqF3x, eqF3y, eqF2x, eqF2y, eqF1x, eqF1y, eqM1Az, eqM2z,eqM3Dz);
    r03x = eval(solF.r03x);
    r03y = eval(solF.r03y);
    r23x = eval(solF.r23x);
    r23y = eval(solF.r23y);
    r12x = eval(solF.r12x);
    r12y = eval(solF.r12y);
    r01x = eval(solF.r01x);
    r01y = eval(solF.r01y);
    Mdz  = eval(solF.Mdz);

    % Storing values 
    
    % Link 3

    Fin3col(i) = norm(Fin3);
    R03 = [r03x r03y 0];
    R23 = [r23x r23y 0];
    R03col(i) = norm(R03);
    R23col(i) = norm(R23);
    Min3col(i) = norm(Min3);
    r03xcol(i) = r03x;
    r03ycol(i) = r03y;
    r23xcol(i) = r23x;
    r23ycol(i) = r23y;
    
    % Link 2

    Fin2col(i) = norm(Fin2);
    R12 = [r12x r12y 0];
    R32 = -R23;
    R32col(i) = norm(R32);
    R12col(i) = norm(R12);
    Min2col(i) = norm(Min2);
    r12xcol(i) = r12x;
    r12ycol(i) = r12y;
    
    % Link 1

    Fin1col(i) = norm(Fin1);
    R01 = [r01x r01y 0];
    R21 = -R12;
    R01col(i) = norm(R01);
    R21col(i) = norm(R21);
    Min1col(i) = norm(Min1);
    Mdcol(i) = Mdz;
    r01xcol(i) = r01x;
    r01ycol(i) = r01y;
    
end

% Plotting angular velocities of 3 links

figure(2);
title('Plot of angular velocities with respect to input angle');
xlabel('Input angle {\alpha}');
ylabel('{\omega} (rad/s)');
xlim([acol(1) acol(frs+1)]);
hold on
plot(acol,omega1col);
plot(acol,omega2col);
plot(acol,omega3col);
legend('omega1','omega2','omega3','Location','northwest');
hold off
grid on

% Plotting angular acceleration of 3 links 

figure(3);
title('Plot of angular accelerations with respect to input angle');
xlabel('Input angle {\alpha}');
ylabel('{\alpha} (rad/s^2)');
xlim([acol(1) acol(frs+1)]);
hold on
plot(acol,alpha1col);
plot(acol,alpha2col);
legend('alpha1','alpha2');
hold off
grid on

% Plotting Forces on link 3
 
figure(4);
title('Plot of forces on link 3 with respect to input angle');
xlabel('Input angle {\alpha}');
ylabel('Force (Newton)');
xlim([acol(1) acol(frs+1)]);
ylim([-0.5 3]);
hold on
plot(acol,R03col);
plot(acol,R23col);
plot(acol,Fin3col);
plot(acol,P3col);
plot(acol,Pballcol)
legend('R03','R23','Fin3','P3col','Pball');
hold off
grid on

% Plotting Forces on link 2
 
figure(5);
title('Plot of forces on link 2 with respect to input angle');
xlabel('Input angle {\alpha}');
ylabel('Force (Newton)');
xlim([acol(1) acol(frs+1)]);
ylim([-0.5 2.5]);
hold on
plot(acol,R32col);
plot(acol,R12col);
plot(acol,Fin2col)
plot(acol,P2col)
legend('R32','R12','Fin2','P2');
hold off
grid on

% Plotting Forces on link 1
 
figure(6);
title('Plot of forces on link 1 with respect to input angle');
xlabel('Input angle {\alpha}');
ylabel('Force (Newton)');
xlim([acol(1) acol(frs+1)]);
ylim([-0.5 2.5]);
hold on
plot(acol,R21col);
plot(acol,R01col);
plot(acol,Fin1col)
plot(acol,P1col)
legend('R21','R01','Fin1','P1');
hold off
grid on

% Plotting driving moment
 
figure(7);
title('Plot of all moments with respect to input angle');
xlabel('Input angle {\alpha}');
ylabel('Moment (Nm)');
xlim([acol(1) acol(frs+1)]);
hold on
plot(acol,Mdcol);
plot(acol,Min1col);
plot(acol,Min2col);
plot(acol,Min3col);
legend('Md','Min1','Min2','Min3');
hold off
grid on

% Plotting anlge beat wrt alpha

figure(8);
title('Plot of output angle with respect to input angle');
xlabel('Input angle {\alpha}');
ylabel('Output angle {\beta}');
xlim([acol(1) acol(frs+1)]);
hold on
plot(acol,bcol);
legend('{\beta}');
hold off
grid on





