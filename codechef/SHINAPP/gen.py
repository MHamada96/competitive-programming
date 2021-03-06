dp = [{} for i in range(301)]
def solve(n,k):
	global dp;
	if n == 1: return (k > 0) * 1;
	if dp[n].has_key(k) : return dp[n][k];
	dp[n][k] = 0;
	for i in range(1,k/n + (k%n != 0)):
		dp[n][k] += solve(n - 1,k - i*n);
	return dp[n][k];

for n in range(1,11):
	for k in range(1,51):
		print solve(n,k),
	print ;
