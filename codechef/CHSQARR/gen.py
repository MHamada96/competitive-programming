from random import randint
from os import system
from time import sleep

MAX = 50;
MAXX = 1000;
m = n = x = y = None;
A = None;
def CreateTest():
	global m,n,x,y,A;
	f = file("in.in","w");
	m,n = [randint(1,MAX) for i in xrange(2)];
	A = [[randint(1,MAXX) for j in xrange(n)] for i in xrange(m)];
	f.write(str(m) + " " + str(n) + "\n");
	for i in xrange(m):
		f.write(" ".join([str(x) for x in A[i]]) + "\n");
	x,y = randint(1,m),randint(1,n)
	f.write("1\n" + str(x) + " " + str(y) + "\n");
	f.close();

def solve():
	ans = 1 << 50;
	for i in xrange(m - x + 1):
		for j in xrange(n - y + 1):
			S = mx = 0;
			for ix in xrange(i,i + x):
				for jx in xrange(j,j + y):
					S += A[ix][jx];
					mx = max(mx,A[ix][jx]);	
			ans = min(ans,mx * x*y - S);
	return ans;
def judge():
	cor = solve();
	system("./test < in.in > out.out");
	f = file("out.out");
	f = [l for l in f];
	f = int(f[0]);
	return f == cor;

t = 1;
while True:
	CreateTest();
	if not judge:
		print "found";
		break
	print "Done %d"%t
	t += 1;
	sleep(1);
