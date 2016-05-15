#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define vi vector<int>
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
#define pre() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;


struct suffix_array{
	string T;
	vi SA,Pos,Rank,LCP;
	vi tmpSA,tmpRank,ctr;
	int L;

public:
	suffix_array(){}
	suffix_array(const char *P){
		T = string(P) + '$'; L = len(T);
		SA.resize(L); Pos.resize(L); Rank.resize(L); LCP.resize(L);
		tmpSA.resize(L); tmpRank.resize(L); ctr.resize(max(L,300) + 1);
	}
	suffix_array(const char **P,int n){
		T = ""; char delm = '$';
		loop(i,n) {
			T += string(P[i]) + delm;
			delm++; 
		}
		L = len(T);
		SA.resize(L); Pos.resize(L); Rank.resize(L); LCP.resize(L);
		tmpSA.resize(L); tmpRank.resize(L); ctr.resize(max(L,300));
	}
	
	void sort(int k){
		fill(all(ctr),0);
		loop(i,L) ctr[((i + k < L) ? Rank[i + k] : 0) + 1]++;
		loop(i,sz(ctr) - 1) ctr[i + 1] += ctr[i];
		loop(i,L) {
				int u = ((SA[i] + k) < L) ? Rank[SA[i] + k] : 0;
				tmpSA[ctr[u]++] = SA[i];
		}
		loop(i,L) SA[i] = tmpSA[i];		
	}

	void BuildSA(){
		// initialize		
		loop(i,L) SA[i] = i,Rank[i] = T[i];
		sort(0);		
				
		// main loop
		for(int k = 1,cnt; (k << 1) < L;k <<= 1){
				sort(k);
				sort(0);
				tmpRank[SA[0]] = cnt = 0;
				loop(i,L){
						if(!i) continue;
						cnt += !(Rank[SA[i]] == Rank[SA[i-1]] && Rank[SA[i]+k] == Rank[SA[i-1]+k]);		
						tmpRank[SA[i]] = cnt;				
				}
				loop(i,L) Rank[i] = tmpRank[i];
				break;
		}
		loop(i,L) Pos[SA[i]] = i;
	}

	void BuildLCP(){
		int l = 0;
		loop(i,L) {
				if(Pos[i]) {
						int j = SA[Pos[i]-1];
						while(i + l < L && j + l < L && T[i + l] == T[j + l]) l++; 
				}
				LCP[Pos[i]] = l;
				if(l) l--;
		}
	}

	int lower_bound(int s,char *P){
		int e = L - 1;
		while(s < e){
				int m = (s + e) >> 1;
				if(strcmp(T.c_str() + SA[m],P) >= 0) e = m;
				else s = m + 1;
		}		
		return s;
	}

	pi EqualRange(char *P){
		pi ret;
		ret.xx = lower_bound(0,P);
		P[strlen(P) - 1]++;
		ret.yy = lower_bound(ret.xx,P);
		return ret;
	}
	
	void PrintSA(){loop(i,L) cerr << T.c_str() + SA[i] << endl;}
	void PrintLCP(){loop(i,L) cerr << T.c_str() + SA[i] << " " << LCP[i] << endl;}
};


const int MAX = 250011 << 1;
int n,m;
char line[MAX + 10];


int main(){
	scanf("%d %s",&n,line);	
	loop(i,n) line[i + n] = line[i];
        line[n <<= 1] = '\0';
	suffix_array SA = suffix_array(line);	
	SA.BuildSA();	
	SA.BuildLCP();
	double tot = 0;
	deque<pi> window; window.pb(mp(0,0));
	loop(i,n + 1){
		if(!i) continue;
		while(!window.empty() && SA.LCP[i] <= window.back().xx) window.pop_back();
		window.pb(mp(SA.LCP[i],i)); 
		if(SA.SA[i] < (n >> 1)) {
			//cerr << " " <<  min(window.front().xx,n >> 1) << endl;
			//loop(j,n >> 1) cerr << line[SA.SA[i] + j];
			tot += min(window.front().xx,n >> 1);			
			window.clear();
		}		
	}
	printf("%.3lf\n",tot / ((n >> 1) - 1));	
	return 0;
}