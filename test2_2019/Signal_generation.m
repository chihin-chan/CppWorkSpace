clear all
close all
clc

% Underlying function
a =  2/5;
b = -3/2;
c =  1.0;
d =  2.0;
func = @(x) a*x.^3 + b*x.^2 + c*x + d;

% Number of points
N = 5000;
% Assuming the data is equispaced
x = linspace(0,5,N);
y = 0*rand(1,N)+func(x);

A = [x; y];

fileID = fopen('data.txt','w');
fprintf(fileID,'%6s %12s\n',num2str(N)," ");
fprintf(fileID,'%6.2f %12.8f\n',A);
fclose(fileID);

figure(1)
plot(x,y,"o")
title("Signal")