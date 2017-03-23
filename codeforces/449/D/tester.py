from random import *;
from string import *;
from os import system;

MAXN = 5;
MAXM = 5;
MAXA = 10**6;

def create_test():
	f = file("in.in","w");
	n = 200;
	f.write("%d\n"%n);
	for i in xrange(n):
		f.write("%d "%randint(1,MAXA));
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
