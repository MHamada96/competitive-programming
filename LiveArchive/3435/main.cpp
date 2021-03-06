#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
#define ll long long
#define pi pair<int,int>
#define point pair<double,double>
#define pl pair<ll,ll>
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

char line[1 << 20],tmp[1 << 20];
int n,L;

void prefix(char key,char q,char *p,int c){
	if(!c) return;
	if(key == 'a') {
		strcpy(tmp,"against ");
		strcpy(tmp + strlen(tmp),p);
	}
	else if(key == 'p'){
		if(q == 'o'){
			strcpy(tmp,"after ");
			strcpy(tmp + strlen(tmp),p);
		}
		else{
			strcpy(tmp,"before ");
			strcpy(tmp + strlen(tmp),p);
		}
	}
	else if(key == 'u'){
			strcpy(tmp,"not ");
			strcpy(tmp + strlen(tmp),p);
	}
	else {
			strcpy(tmp,p);
			strcpy(tmp + strlen(tmp)," again");		
	}
	strcpy(line,tmp);
}

bool getpref(char & a,char & b,char *&p){
	char names [][10] = {"anti","post","pre","re","un"};
	loop(i,5){
		if(L <= strlen(names[i])) continue;
		int offset = strlen(names[i]);
		char t = line[offset]; line[offset] = 0;
		int v = strcmp(line,names[i]);
		line[offset] = t;
		if(v == 0){
			p = line + offset;
			a = names[i][0];
			b = names[i][1];
			return 1;
		}
	}	
	return 0;
}

bool getsuff(char & a,char & b,char *&p){
	char names[][10] = {"er","ing","ize","s","tion"};
	loop(i,5){
		if(L <= strlen(names[i])) continue;
		int offset = strlen(names[i]);
		int v = strcmp(line + L - offset,names[i]);
		if(v == 0){
			p = line;
			line[L - offset] = 0;
			a = names[i][0];
			b = names[i][1];
			return 1;
		}
	}
	return 0;
}

void suffix(char a,char b,char *p,int c){
	if(!c) return;
	char pre [] [50] = {"one who ","to actively ","change into ","multiple instances of ","the process of "};
	char post[] [20] = {"s","","","","ing"};
	int k;
	if(a == 'e') k = 0;
	if(a == 'i') k = 1 + (b == 'z');
	if(a == 's') k = 3;
	if(a == 't') k = 4; 
	strcpy(tmp,pre[k]);
	strcpy(tmp + strlen(tmp),p);
	strcpy(tmp + strlen(tmp),post[k]);
	strcpy(line,tmp);
}

int main(){
	scanf("%d",&n);
	loop(i,n){
		scanf("%s",line); L = strlen(line);
		//cerr << line ;			
		char a,b,*p = 0,c,d,*q = 0;
		int z1 = getpref(a,b,p);
		int z2 = getsuff(c,d,q);
		//cerr << " " << z1 << " " << z2 << " " << a << " " << b << " " << c << " " << d << endl;
		if(q){
			strcpy(tmp,q);
			strcpy(line,tmp);
		}
		if(p){
			strcpy(tmp,p);
			strcpy(line,tmp);
		}
		suffix(c,d,line,z2);
		prefix(a,b,line,z1);
		printf("%s\n",line);
	}
	return 0;
}
