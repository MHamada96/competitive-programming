from random import randint;

f = file("in.in","w");
L = int(1e15);
n = 14;
f.write(str(n) + " " + str(L) + "\n");
D = [[0 for i in range(14)] for j in range(14)];
for i in range(n):
	for j in range(i):
		D[i][j] = randint(1,L);
		D[j][i] = D[i][j];
for i in range(n):
	for j in range(n):
		f.write(str(D[i][j]) + " ");
	f.write("\n");
f.close();
