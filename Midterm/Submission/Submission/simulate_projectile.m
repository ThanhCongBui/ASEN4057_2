function [t, x, y] = simulate_projectile(x0, y0, vx0, vy0, m, r, CD, e, n)
clc;
% Define a comically long time span such that the ball's motion will be
% captured no matter what.

tspan = [0,1e9];

initials = [x0, y0, vx0, vy0];

options = odeset('Events',@ballEvents,'AbsTol',1e-15,'RelTol',1e-10);

% Define initial empty matrices which will be filled with the iterative
% data collected from each run of the simulation. 
tuckY = [];
tuckT = [];
for ii = 1:n
    
    [t,y,te,ye,ie] = ode45(@(t,y)odeProjectile(t,y,m,r,CD),tspan, initials, options);
    initials = [y(end,1), y(end,2), y(end,3), -e.*y(end,4)];
    tspan = [t(end),10.*t(end)];
    tuckY = [tuckY;y(2:length(t),:)];
    tuckT = [tuckT;t(2:length(t))];
 
end
        t = tuckT;
        x = tuckY(:,1);
        y = tuckY(:,2);
end




