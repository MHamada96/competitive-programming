#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
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

char name[2][10] = {"Daenerys","Stannis"};

int main(){
	int n,k,x,cnt[2] = {0};
	scanf("%d %d",&n,&k);
	loop(i,n) scanf("%d",&x),cnt[x & 1]++;
	if(cnt[0] + cnt[1] == k) puts(name[cnt[1]%2]);
	else{
		if(cnt[1] - cnt[0] >= k) puts(name[k%2]);
		else if(cnt[0] - cnt[1] >= k) puts(name[0]);
		else puts(name[(cnt[1] - cnt[0] + k)%2]);
	}
	return 0;
}
