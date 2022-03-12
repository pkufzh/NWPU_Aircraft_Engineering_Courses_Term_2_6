%% 数据准备
clear all
clf
clc
t=[3.31 9.50 16.13 25.88 35.91 42.97 75.31 82.12 123.22 138.87];  % 放电时间
Q=[1298.9 1172.7 1042.8 872.1 732.9 645.8 362.4 325.4 154.7 118.7]; % 电量
C=0.5e-6;
RS=1e8;
q=zeros(1,10);
tt=zeros(1,10);
tq=zeros(1,10);
for i=1:10
    q(i)=log(Q(i));
    tt(i)=t(i)*t(i);
    tq(i)=t(i)*q(i);
end
t10=mean(t);
t20=mean(tt);
q0=mean(q);
tq0=mean(tq);
R=(-1/C)*((t10*t10-t20)/((t10*q0)-tq0));
fprintf('高电阻预估值为：%f（欧姆）\n',R);
nh=abs((R-RS)/RS);
fprintf('与标准电阻误差为：%.2f%%\n',nh*100);
%% 绘图
plot(t,Q,'m.','MarkerSize',20);
xlabel('t'),ylabel('Q'),title('t-Q变化图像');
grid on;
box on;
figure;
n=1;
p=polyfit(t,q,n);
ti=3.31:0.01:138.87;
qi=polyval(p,ti);
plot(t,q,'b.','MarkerSize',20);
hold on
plot(ti,qi,'r-','LineWidth',2);
xlabel('\itt'),ylabel('\itlnQ'),title('t-lnQ变化图像');
legend('实验数据点','线性拟合直线');
grid on;
box on;