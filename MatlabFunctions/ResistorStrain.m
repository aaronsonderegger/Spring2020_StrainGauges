function [ ResistorChange ] = ResistorStrain( x, theta, Resistor ,isTop)
%STRAIN Summary of this function goes here
%   Detailed explanation goes here
TB = -1;
if isTop
    TB = 1;
end

Base = 10/1000;         % [m]
Height = 12.3/1000;     % [m]
E_youngsModulus = 190e6; % [Pa]
Fv = 20;                % [N]
Fh = 4;                 % [N]
K = 2;

epsilon = ( (TB*6*x*cosd(theta)/Height + sind(theta))*Fv ...
          + (cosd(theta) - TB*6*x*sind(theta)/Height)*Fh )/(E_youngsModulus*Base*Height);
      
ResistorChange = K*epsilon*Resistor;
end