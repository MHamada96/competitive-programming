#include <bits/stdc++.h>
#define PI acos(-1)
#define all(V) V.begin() ,V.end()
#define print(Q,t) copy(all(Q),ostream_iterator<t>(cout,"\n"))
#define pre() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define loop(i,n) for(int i = 0;i < (n);i++)
using namespace std;

typedef complex<double> cd;
typedef vector<cd> vcd; 

vcd A(1 << 21),B(1 << 21),C(1 << 21),D(1 << 21),E(1 << 21),F(1 << 21);
int V1[1 << 21],V2[1 << 21],V3[1 << 21];
int *p,*q,*u;

int rev(int n,int l){
	char s[l + 1];
	for(int i = 0;i < l;i++) s[i] = '0';
	for(int i = 0;n;i++,n /= 2) s[i] = n%2 + '0';
	int ans = 0;
	for(int i = 0;i < l;i++) ans = (ans << 1) + (s[i] - '0');
	return ans;
}
int len(int n){
	int ans = 0;
	for(;n;n /= 2) ans++;
	return ans;
}

void bit_rev(vcd & IN,vcd & OUT,int L){
	int l = len(L - 1);
	for(int i = 0;i < L;i++)
		OUT[rev(i,l)] = IN[i];
}

void FFT(vcd & IN,vcd & OUT,int n,bool perform_inv){ 
	bit_rev(IN,OUT,n);
	for(int s = 1,lg = len(n) - 1;s <= lg;s++){
		int m = (1 << s);
		cd wm = cd(cos(2.0*PI/m),sin(2.0*PI/m));
		for(int k = 0;k < n;k += m){
			cd w = cd(1.0,0.0);
			for(int j = 0;j < m/2;j++){
				cd t = w*OUT[k + j + m/2];
				cd u = OUT[k + j];
				OUT[k + j] = u + t;
				OUT[k + j + m/2] = u - t;
				if(perform_inv) w /= wm;
				else w *= wm;
			}
		}
	}
	if(perform_inv) for(int i = 0;i < OUT.size();i++) OUT[i] /= n;
}

void multiply(int m,int n,int & L){
        for(int i = 0;i < m;i++) A[i] = cd(p[i],0.0);
	for(int i = 0;i < n;i++) B[i] = cd(q[i],0.0);
	cd zero(0.0,0.0);
	int l = (1 << (1 + len(max(m,n))));
	while(m < l) A[m++] = zero;
	while(n < l) B[n++] = zero;
	FFT(A,C,l,0); FFT(B,D,l,0);
	for(int i = 0;i < l;i++) E[i] = C[i] * D[i];
	FFT(E,F,l,1);
	for(int i = 0;i < l;i++) V3[i] = round(real(F[i]));
	int j = 0;
	for(int i = 0;i < l;i++) if(V3[i]) j = i,V3[i] = 1;
	L = j + 1;
}

int n,k;

void EXP(){
	int m1 = 0,m2 = 1;
	loop(i,1 << 21) if(V1[i]) m1 = i + 1;
	V2[0] = 1;
	while(k > 1){
		if(k & 1) {
			p = V1,q = V2;
			multiply(m1,m2,m2);
			copy(V3,V3 + m2,V2);
		}
		p = V1,q = V1;
		multiply(m1,m1,m1);
		copy(V3,V3 + m1,V1);
		k >>= 1;
	}
	p = V1,q = V2;
	multiply(m1,m2,m1);
	copy(V3,V3 + m1,V1);
}

int main(){
	scanf("%d %d",&n,&k);	
	loop(i,n) {
		int a;
		scanf("%d",&a);
		V1[a] = 1;
	}
	EXP();
	loop(i,1 << 21) if(V1[i]) printf("%d ",i);
	puts("");
}
