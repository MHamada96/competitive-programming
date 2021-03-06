import matplotlib.pyplot as plt
	
	
def f():
	MAX = 10**5
	prime_div = [i for i in xrange(MAX + 1)];
	for i in xrange(2,MAX + 1):
		if prime_div[i] == i:
			for j in xrange(i*i,MAX + 1,i):
				prime_div[j] = i;
	
	mx = 1
	y = [1 for i in xrange(MAX + 1)];
	for i in xrange(2,MAX + 1):
		num = 1;
		n = i;
		while n > 1:
			p = prime_div[n];
			ctr = 1;
			while n%p == 0:
				ctr += 1;
				n /= p;
			num *= ctr;
		y[i] = num;
	
	plt.hist(y);
	plt.show()

def g(n):
	ctr = [0 for i in xrange(n)];
	for r in xrange(1,n + 1):
		p = 0;
		while p < n:
			ctr[p] += 1;
			p += r;
	ctr[0] = 0;
	print max(ctr);

g(10**5);
