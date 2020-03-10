%% Aaron Sonderegger
% Strain Gauge Model
% The purpose of this is to model the Strain Gauge Wheatstone bridge, to 
% understand how the effects of different configs, (qaurter, half, 3/4 and
% full bridges)
clear,clc
if exist('C:\Users\User\Desktop\Spring 2020 Research\Strain Gage', 'file')
    d = 'C:\Users\User\Desktop\Spring 2020 Research\Strain Gage';
elseif exist('D:\Research\code', 'file')
    d = 'D:\Research\code';
end

if ~strcmp(pwd,d)
   cd(d)
end
addpath('.\MatlabFunctions');


%%
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

disp('Running');
theta = [-60:60];  % [deg]
Vout1 = zeros(size(theta));
Vout2 = zeros(size(theta));
Vout3 = zeros(size(theta));
Vout4 = zeros(size(theta));
Weight = 155;       % [N]
E = 70e9;           % [Pa]
x1 = 0.06;          % [m]
x2 = 0.08;          % [m]
Moment = @(theta,x) Weight*x*cosd(theta);
R1 = 120;
R2 = 120;
R3 = 120;
R4 = 120;

R5 = 500;
R6 = 1000 - R5;
R7 = 1;
R8 = 100;

run('StrainGaugePlacement.m')
% Good Configurations 14-, 16+, 20-, 22+
% 16, 4 and 3 are closest to ground.
% config14 min dV = -0.0242, 0.0353 to 0.1712
% config16 max dV = 0.391V, 0.327 to 0.195, Slope is largest
% config20 min dV = -0.0227, 0.0365 to 0.195, Slope okay
% config22 max dV = 0.389V, 0.326to 0.195, Slope is largetst
config = config14; 

for k = 1:length(theta)
    DeltaR1 = ResistorStrain(config(1,1), theta(k), R1, config(1,2)) + R1;
    DeltaR2 = ResistorStrain(config(2,1), theta(k), R2, config(2,2)) + R2;
    DeltaR3 = ResistorStrain(config(3,1), theta(k), R3, config(3,2)) + R3;
    DeltaR4 = ResistorStrain(config(4,1), theta(k), R4, config(4,2)) + R4;
    
    [Vb1, Va1] = BasicWheatStone(DeltaR1,DeltaR2,DeltaR3,DeltaR4);
    Vout1(k) = (Vb1 - Va1);
%     fprintf('Config1 Vout = %f\n',abs(Vb - Va));
    
    [Vb2, Va2] = config2WheatStone(DeltaR1, DeltaR2, DeltaR3, DeltaR4, R5, R6);
    Vout2(k) = (Vb2 - Va2);
%     fprintf('Config2 Vout = %f\n',abs(Vb - Va));
    
    [Vb3, Va3] = Config3WheatStone(DeltaR1, DeltaR2, DeltaR3, DeltaR4, R5,R6,R7);
    Vout3(k) = (Vb3 - Va3);
%     fprintf('Config3 Vout = %f\n',abs(Vb - Va));
    
    [Vb4, Va4] = Config4WheatStone(DeltaR1, DeltaR2, DeltaR3, DeltaR4, R5,R6,R7,R8);
    Vout4(k) = (Vb4 - Va4);
%     fprintf('Config3 Vout = %f\n',abs(Vb - Va));
end
slope1 = diff(Vout1)./diff(theta);
slope2 = diff(Vout2)./diff(theta);
slope3 = diff(Vout3)./diff(theta);
slope4 = diff(Vout4)./diff(theta);

figure(1)
    subplot(2,1,1)
% p = plot(theta,Vout1,'b', theta,Vout2,'r', theta,Vout3,'y', theta,Vout4,'k');
p = plot(theta,Vout4);
xlabel('\theta, [deg]')
ylabel('\Delta V_o_u_t [V]')
legend('Config 1','Config 2','Config 3','Config 4');
set(p,'linewidth',2)
grid on
hold on
    subplot(2,1,2)
% p = plot(theta(2:end),slope1,'b', theta(2:end),slope2,'r', theta(2:end),slope3,'y', theta(2:end),slope4,'k')
p = plot(theta(2:end), slope4)
xlabel('\theta, [deg]')
ylabel('dV/d\theta [V]')
legend('Config 1','Config 2','Config 3','Config 4');
set(p,'linewidth',2)
grid on
hold on
