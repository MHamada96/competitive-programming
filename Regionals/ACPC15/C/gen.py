import os;
c = 1;
for x in xrange(10):
	print x;	
	os.system("python gen.py");
	os.system("./test < in.in > out.out");
	os.system("diff out.out correct.out > err.out");
	f = file("err.out","r");
	F = [line for line in f];
	if len(F):
		print "fail";
		c = 0;
		break;
	f.close();
if c : print "pass";
