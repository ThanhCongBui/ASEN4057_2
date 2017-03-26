function [dy] = odeProjectile(t,y,mass,radius,CD)

if CD == 1
    CD = 0.5;
else
    CD = 0.3;
end

%%% expect X to be of form
% x(1) = x position
% x(2) = y position
% x(3) = x velocity
% x(4) = y velocity

%%% And, of course, output dx will contain:
% dx(1) = x velocity
% dx(2) = y velocity
% dx(3) = x acceleration
% dx(4) = y acceleration

rho = 1.275;  % kg/m.^3 at 15 deg C
dy = [0;0;0;0];

theta = atan(y(4)./y(3));

dy(1) = y(3);
dy(2) = y(4);

speed = sqrt(dy(1).^2 + dy(2).^2);
area = pi.*radius.^2;
drag = 1/2.*CD.*rho.*(speed.^2).*area;

grav = 9.81;
dy(3) = -(drag.*cos(theta))./mass;
dy(4) = -(drag.*sin(theta))./mass - grav;


end


