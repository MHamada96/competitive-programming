s = [c for c in raw_input()];
s.reverse();
ans = 0
n = len(s);
mod = 10**9 + 7;
for i in xrange(n):
	if s[i] == '1':
		ans += pow(2,n + i - 1,mod);
		if ans >= mod: ans -= mod;

print ans;

