s = "FOOLING";
S = set();
def f(u,v):	
	print u,v;	
	for i in xrange(7):
		if u[i] == v[i]:
			return ;
	S.add(u);

u = s;
u = [c for c in s];
u.sort()

ctr = 0;
V = [0 for i in xrange(7)];
def gen(i,z): 	
	global ctr
	if i == 7: 
		ctr += 1;	
		f(z,s);
		return ;

	for j in xrange(7):
		if not V[j]:
			V[j] = 1;
			gen(i + 1,z + u[j]);
			V[j] = 0;

gen(0,"");
print ctr;
print len(S);