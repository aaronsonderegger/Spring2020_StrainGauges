function [ V3, V4 ] = Config3WheatStone( R1, R2, R3, R4, R5, R6, R7 )
%CONFIG3WHEATSTONE Summary of this function goes here
%   Detailed explanation goes here
Vin = 5;

V2 = 1;
V3 = 1;
V4 = 1;

V2_old = V2;
V3_old = V3;
V4_old = V4;

A = (1/R7)/(1/R1 + 1/R2 + 1/R5 + 1/R7);
B = (1/R1 + 1/R5 + 1/R7)/(1/R1 + 1/R2 + 1/R5 + 1/R7);
C = (1/R7)/(1/R1 + 1/R3 + 1/R5 + 1/R7);
D = (1/R1 + 1/R5 + 1/R7)/(1/R1 + 1/R3 + 1/R5 + 1/R7);
E = (1/R1 +1/R5)/(1/R1 + 1/R3 + 1/R5 + 1/R7);
F = (1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R5 + 1/R6);

for k = 1:50
    V2 = A*Vin - B*V3;
    V3 = C*Vin - D*V2 - E*V4;
    V4 = F*(V2 +V3);
    error2 = abs(100*(V2 - V2_old));
    error3 = abs(100*(V3 - V3_old));
    error4 = abs(100*(V4 - V4_old));
    if(error2 < 0.1 && error3 < 0.1 && error4 < 0.1)
       break 
    end   
    V2_old = V2;
    V3_old = V3;
    V4_old = V4;
end

% V3 = (A - B*F - C*D*F)/(B*G + C*E - C*D*G)*Vin
% V2 = (F - G*(A - B*F - C*D*F)/(B*G + C*E -C*D*G))*Vin
% V4 = (D*F - D*G*(A - B*F - C*D*F)/(B*G + C*E - C*D*G) + E*(A - B*F -C*D*F)/(B*G + C*E - C*D*G))*Vin

end

