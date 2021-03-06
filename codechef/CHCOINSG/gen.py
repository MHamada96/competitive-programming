MAX = 1000;
P = [];
dp = [-(i != 0)  for i in xrange(MAX)];

def sieve():
	is_p = [1 for i in xrange(MAX + 1)];
	for i in xrange(2,MAX + 1):
		if is_p[i]:
			P.append(i);
			for j in xrange(i*i,MAX + 1,i):
				is_p[j] = 0;

def solve(n):
	if dp[n] != -1: return dp[n];
	dp[n] = not solve(n - 1);
	for p in P:
		q = p;
		while not dp[n] and q <= n:
			dp[n] = not solve(n - q);
			q *= p;
	return dp[n];

sieve();
for i in xrange(MAX):
	if not solve(i):
		print i;
