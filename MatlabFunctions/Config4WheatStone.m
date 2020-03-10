function [ V3, V4 ] = Config4WheatStone( R1, R2, R3, R4, R5, R6, R7, R8 )
%CONFIG4WHEATSTONE Summary of this function goes here
%   Detailed explanation goes here

Vin = 5;

V3 = 1;
V4 = 1;
V7 = 1;
V8 = 1;
V3_old = V3;
V4_old = V4;
V7_old = V8;
V8_old = V8;

A = R3/R2;

B = (1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R5 + 1/R6);
C = (1/R5)/       (1/R1 + 1/R4 + 1/R5 + 1/R6);
D = (1/R1)/       (1/R1 + 1/R4 + 1/R5 + 1/R6);
E = (1/R1 + 1/R6)/(1/R1 + 1/R4 + 1/R5 + 1/R6);

F = (1/R1 + 1/R2)/(1/R1 + 1/R2 + 1/R7);
G = (1/R2)/       (1/R1 + 1/R2 + 1/R7);
H = (1/R1)/       (1/R1 + 1/R2 + 1/R7);
I = (1/R1 + 1/R2)/(1/R1 + 1/R2 + 1/R7);

J = (1/R1 + 1/R2 + 1/R5)/(1/R1 + 1/R2 + 1/R6 + 1/R8);
K = (1/R2 + 1/R5)/       (1/R1 + 1/R2 + 1/R6 + 1/R8);
L = (1/R1 + 1/R5 + 1/R6)/(1/R1 + 1/R2 + 1/R6 + 1/R8);
M = (1/R1 + 1/R2)/       (1/R1 + 1/R2 + 1/R6 + 1/R8);

for k = 1:30
    V3 = A*(Vin - V4 - V7 - V8);
    V4 = B*Vin - C*V4 - D*V7 - E*V8;
    V7 = F*Vin - G*V3 - H*V4 - I*V8;
    V8 = J*Vin - K*V3 - L*V4 - M*V8;
    
    error3 = 100*abs(V3 - V3_old);
    error4 = 100*abs(V4 - V4_old);
    error7 = 100*abs(V7 - V7_old);
    error8 = 100*abs(V8 - V8_old);
    if(error3 < 0.1 && error4 < 0.1 && error7 < 0.1 && error8 < 0.1)
        break
    end
    V3_old = V3;
    V4_old = V4;
    V7_old = V8;
    V8_old = V8;
end
end

