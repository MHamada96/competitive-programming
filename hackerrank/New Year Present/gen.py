val = map(int,"10000000 5000000 5000000 10000000 10000000 5000000 5000000 2500000 2500000 2500000 3333333 1666666 1 1 3333333".split());

def trans(A):
	global val;
	for i in xrange(6):
		A[i] = val[A[i]];
	A.sort();
	return A;

def cond(A):
	A.sort();
	if A[-1] == A[-2] and A[0] + A[3] == A[-1] and A[1] + A[2] == A[-1]: return 1;
	if A[-1] == A[-2] and A[-1] == A[-3] and sum(A[:3]) == A[-1]: return 1;
	return 0;

def f(A):
	A.sort();
	for i in xrange(6):
		for j in xrange(i):
			if A[i] == A[j]:
				return 0;
	return cond(trans(A));

def get_type(A):
	if A[-1] == A[-2] and A[-1] != A[-3]:
		return len(set(A[:4])) - 1;
	return len(set(A[:3])) + 3;	

def sim():
	S = xrange(15);
	so = set();
	for i in S:
		for j in S:
			for k in S:
				for l in S:
					for m in S:
						for n in S:
							if f([i,j,k,l,m,n]):
								A = [i,j,k,l,m,n];
								A.sort();
								so.add(tuple(A));
	T = [[] for i in xrange(7)]
	for A in so:
		A = trans(list(A));
		T[get_type(A)].append(A);
	return T;

T = sim();