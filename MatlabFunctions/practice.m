Vin = 5;
R1 = 120;       % [ohm], Top
R2 = 120;       % [ohm], Bottom
R3 = 120;       % [ohm], Top
R4 = 120;       % [ohm], Bottom
R5 = 1000;
R6 = 1000;
R7 = 500;
R8 = 500;

syms v2 v3 v4
one = v2 == (1/R7)/              (1/R1 + 1/R2 + 1/R5 + 1/R7)*Vin ...
    -(1/R1 + 1/R5 + 1/R7)/(1/R1 + 1/R2 + 1/R5 + 1/R7)*v3;

two = v3 == (1/R7)/              (1/R1 + 1/R3 + 1/R5 + 1/R7)*Vin ...
    -(1/R1 + 1/R5 + 1/R7)/(1/R1 + 1/R3 + 1/R5 + 1/R7)*v2 ...
    -(1/R1 +1/R5)/        (1/R1 + 1/R3 + 1/R5 + 1/R7)*v4;

three = v4 == (1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R5 + 1/R6)*v2 ...
    +(1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R5 + 1/R6)*v3;
sol = solve(one,two,three);
fprintf('%f, %f, %f\n',[double(sol.v2),double(sol.v3),double(sol.v4)]);


V2 =10;
V3 =2;
V4 =5;
for k = 1:20
V2 = (1/R7)/              (1/R1 + 1/R2 + 1/R5 + 1/R7)*Vin ...
    -(1/R1 + 1/R5 + 1/R7)/(1/R1 + 1/R2 + 1/R5 + 1/R7)*V3;

V3 = (1/R7)/              (1/R1 + 1/R3 + 1/R5 + 1/R7)*Vin ...
    -(1/R1 + 1/R5 + 1/R7)/(1/R1 + 1/R3 + 1/R5 + 1/R7)*V2 ...
    -(1/R1 + 1/R5)/       (1/R1 + 1/R3 + 1/R5 + 1/R7)*V4;

V4 = (1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R5 + 1/R6)*V2 ...
    +(1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R5 + 1/R6)*V3;
end

fprintf('%f, %f, %f\n',[V2,V3,V4]);

A = (1/R7)/              (1/R1 + 1/R3 + 1/R5 + 1/R7);
B = (1/R1 + 1/R5 + 1/R7)/(1/R1 + 1/R3 + 1/R5 + 1/R7);
C = (1/R1 + 1/R5)/       (1/R1 + 1/R3 + 1/R5 + 1/R7);
D = (1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R5 + 1/R6);
E = (1/R1 + 1/R5)/(1/R1 + 1/R4 + 1/R5 + 1/R6);
F = (1/R7)/              (1/R1 + 1/R2 + 1/R5 + 1/R7);
G = (1/R1 + 1/R5 + 1/R7)/(1/R1 + 1/R2 + 1/R5 + 1/R7);

V2 = 1;
V3 = 1;
V4 = 1;
V2_old = V2;
V3_old = V3;
V4_old = V4;
for k = 1:30
    V2 = F*Vin - G*V3;
    V3 = A*Vin - B*V2 - C*V4;
    V4 = D*V2 + E*V3;
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
fprintf('%f, %f, %f\n',[V2,V3,V4]);


V3 = (A - B*F - C*D*F)/(B*G + C*E - C*D*G)*Vin;
V2 = (F - G*(A - B*F - C*D*F)/(B*G + C*E -C*D*G))*Vin;
V4 = (D*F - D*G*(A - B*F - C*D*F)/(B*G + C*E - C*D*G) + E*(A - B*F -C*D*F)/(B*G + C*E - C*D*G))*Vin;
fprintf('%f, %f, %f\n',[V2,V3,V4]);
fprintf('===================\n');


%%
