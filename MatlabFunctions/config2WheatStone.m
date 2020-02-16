function [ V3, V4] = config2WheatStone( R1, R2, R3, R4, R5, R6 )
%CONFIG2WHEATSTONE Summary of this function goes here
%   Detailed explanation goes here
Vin = 5;

V3 = (1/R2)/(1/R3 + 1/R2)*Vin;
V4 = (1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R6)*Vin;
end

