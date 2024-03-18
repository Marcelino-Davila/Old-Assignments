% 1.)
mu1 = 100;  
sigma1 = 5; 
mu2 = 150; 
sigma2 = 15; 
% 2.)
rho = 0;
% 3.)
alpha = linspace(0, 1, 101);
% 4.)
mu = alpha * mu1 + (1 - alpha) * mu2;
varY = alpha.^2 * sigma1^2 + (1 - alpha).^2 * sigma2^2+2*rho*alpha*sigma1.*(1-alpha)*sigma2;
% 5.)

% 6.)

% 7.)
rho2 = -1;
varY2 = alpha.^2 * sigma1^2 + (1 - alpha).^2 * sigma2^2+2*rho2*alpha*sigma1.*(1-alpha)*sigma2;
rho3 = 1;
varY3 = alpha.^2 * sigma1^2 + (1 - alpha).^2 * sigma2^2+2*rho3*alpha*sigma1.*(1-alpha)*sigma2;
figure;
plot(mu, varY, 'b');
xlabel('Mu');
ylabel('Variance');
hold on
plot(mu,varY2, 'g')
plot(mu,varY3, 'r')
legend;
hold off