S = set()
for y in xrange(10000):
	y += 1989;
	y = str(y);
	for i in xrange(len(y) - 1,-1,-1):
		s = y[i:];
		if s not in S: break;
	print y ,s;
     	S.add(s);
