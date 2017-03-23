from random import *;
from string import *;
from os import system;

MAXN = 5;
MAXM = 5;
MAXA = 5;

def create_test():
	f = file("in.in","w");
	f.write("100\n");
	for t in xrange(100):
		n = 50;
		R = randint(1,10**9);
		f.write("%d %d\n"%(n,R));
		for i in xrange(n):
			x = randint(0,10**9);
			y = randint(0,10**9);
			f.write("%d %d\n"%(x,y));
	f.close();
def run():
	system("./test < in.in > out.out");
	system("./AC < in.in > correct.out");


def is_correct():
	system("diff out.out correct.out > err.log");
	f = file("err.log");
	F = [l for l in f];
	f.close();
	return len(F) == 0;

def main():
	i = 1;
	while True:
		create_test();
		break;
		run();
		if not is_correct():
			print "found";
			break;
		print "done with %d"%i;
		i += 1;

if __name__ == "__main__":
	main();