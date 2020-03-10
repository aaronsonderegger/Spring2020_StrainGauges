x1 = 0.06;
x2 = 0.08;
config1 = [x1, true; x2 true; x1 false; x2 false]; % Bad
% top 1 2
% bot 3 4
% config2 = [x1, true; x2 false; x1 true; x2 false]; % Good
config3 = [x1, true; x2 false; x1 false; x2 true]; % Bad
% top 4 1
% bot 3 2
% config4 = [x1, false; x2 true; x1 false; x2 true]; % Good
config5 = [x1, false; x2 true; x1 true; x2 false]; % Bad
% top 3 2
% bot 1 4
config6 = [x1, false; x2 false; x1 true; x2 true]; % Bad
% top 3 4
% bot 1 2

config7 = [x2, true; x1 true; x2 false; x1 false]; % Bad
% top 2 1
% bot 4 3
% config8 = [x2, true; x1 false; x2 true; x1 false]; % Good
config9 = [x2, true; x1 false; x2 false; x1 true]; % Bad
% top 4 1
% bot 2 3
% config10 = [x2, false; x1 true; x2 false; x1 true]; % Good
config11 = [x2, false; x1 true; x2 true; x1 false]; % Bad
% top 2 3
% bot 4 1
config12 = [x2, false; x1 false; x2 true; x1 true]; % Bad
% top 4 3
% bot 2 1
config13 = [x2, true; x2 true; x1 false; x1 false]; % Bad
config14 = [x2, true; x2 false; x1 true; x1 false]; % Good
% Top 3 1
% Bot 4 2
config15 = [x2, true; x2 false; x1 false; x1 true]; % Bad
% Top 4 1
% Bot 3 2
config16 = [x2, false; x2 true; x1 false; x1 true]; % Good
% Top 4 2
% Bot 3 1
config17 = [x2, false; x2 true; x1 true; x1 false]; % Bad
% top 3 2
% bot 4 1
% config18 = [x2, false; x2 false; x1 true; x1 true]; % Bad
% config19 = [x1, true; x1 true; x2 false; x2 false]; % Bad
config20 = [x1, true; x1 false; x2 true; x2 false]; % Good
% Top 1 3
% Bot 2 4
config21 = [x1, true; x1 false; x2 false; x2 true]; % Bad
% top 1 4
% bot 2 3
config22 = [x1, false; x1 true; x2 false; x2 true]; % Good
% Top 2 4
% Bot 1 3
config23 = [x1, false; x1 true; x2 true; x2 false]; % Bad
% top 2 3
% bot 1 4
% config24 = [x1, false; x1 false; x2 true; x2 true]; % Bad