%% Aaron Sonderegger
% Strain Gauge Model
% The purpose of this is to model the Strain Gauge Wheatstone bridge, to 
% understand how the effects of different configs, (qaurter, half, 3/4 and
% full bridges)
clear,clc
d = 'C:\Users\User\Desktop\Spring 2020 Research\Strain Gage';
if ~strcmp(pwd,d)
   cd(d)
end

% Resistor Values of Strain Gauge.
R1 = 120;       % [ohm], Top
R2 = 120;       % [ohm], Bottom
R3 = 120;       % [ohm], Top
R4 = 120;       % [ohm], Bottom

% ----- Wheatstone Bridge confige ----- 
%       5V
%     /    \
%    R1     R2
%   /        \
%  *   Vout   *
%   \        /
%    R4    R3
%     \    /
%      Gnd

% Governing Equation of a Wheatstone bridge.
% dRx = KR*Rx*epsilon;    Change of resistance KR approximately 2
% Vout = 
 

R5 = 1000;
R6 = 1000;
Vs = 4.96;
% (R3/R5 +R3/R1)/(1 + R3/R1 + R3/R6)
Vb = Vs*(R1*R3*R6 + R3*R5*R6)/(R1*R5*R6 + R3*R5*R6 + R1*R3*R5);
Va = Vs*R4/(R2 + R4);


Vout = Vb - Va

