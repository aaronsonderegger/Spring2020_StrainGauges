function [ V3, V4 ] = BasicWheatStone( R1, R2, R3, R4 )
%BasicWheatStone Summary of this function goes here
%   Detailed explanation goes here
Vin = 5;
V3 = (1/R2)/(1/R2 + 1/R3)*Vin;
V4 = (1/R1)/(1/R1 + 1/R4)*Vin;
end

