def gcd(a,b):
	while b:
		a,b = b,a%b;
	return a;

def get(n):
	S = [[0,1]];
	for i in range(1,n + 1):
		for j in range(1,i + 1):
			g = gcd(i,j);
			a = j/g;
			b = i/g;
			if [a,b] not in S:
				S.append([a,b]);
	S.sort(key = lambda s : s[0]*1.0/s[1]);
	a,b = 0,1;
	for i in range(len(S) - 1):
		d = b * S[i + 1][1];
		a = a*S[i + 1][1] + S[i][1]*b;
		b = d;
		g = gcd(a,b);
		a /= g;
		b /= g;
	return [a,b];

def phi(n):
	ans = n;
	i = 2;
	while i*i <= n:
		if n%i == 0:
			ans = (ans * (i - 1))/i;
		while n%i == 0:
			n /= i;
		i += 1;
	if n != 1:
		ans = (n - 1)*ans/n;
	return ans;


N = 20; s = 2;
for i in range(2,N + 1):
	s += phi(i);
	print i,get(i),3*s - 4;

