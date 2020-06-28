load datain.txt

for i = 1:100
	  r = datain(i,1);
          a = datain(i,2);
          b = datain(i,3);
          theta = [0:0.1:6.28];
x = r*cos(theta)+a;
y = r*sin(theta)+b;
plot(x,y)
hold on
end

