n = int(raw_input());
A = map(int,raw_input().split());
A.sort();
print A;
ans = 0;
for i in xrange(n):
	ans += abs(i + 1 - A[i]);
print ans;
