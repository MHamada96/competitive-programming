def f(u,o):
	v = "";
	for c in u:
		if c == "0": v += o;
		else : v += len(o)*"1";
	return v;

for i in xrange(8):
	s = raw_input();
	u = s;
	for k in xrange(5):
		print u;	
		u = f(u,s);
	print ;
