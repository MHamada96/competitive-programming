#include <bits/stdc++.h>
using namespace std;

long long f(vector<int> V){
	int n = V.size();
	vector<int> A(V.size() + 1);
	for(int i = 0;i < V.size();i++) A[i + 1] = V[i];
	long long t = 0;
	for(int i = 1;i <= n;i++){
		int o = i + 2;
		if(o > n) o -= n;
		t += (A[i] - A[o])*(A[i] - A[o]);
	}
	for(int i = 1;i <= n/2;i++){
		int o = 2*i - 1;
		t += (A[2*i - 1] - A[2*i])*(A[2*i - 1] - A[2*i]);
	}	
		

	return t;	
}

void validate(vector<int> & V,vector<int> & Q){
	
}

int main(){
	int n;
	cin >> n;
	vector<int> V(n);
	int s = 0;
	for(int i = 0;i < n;i += 2){
		if((i >> 1) & 1){
			V[s++] = n - i;
			V[s++] = i + 1;			
		}
		else{
			V[s++] = i + 1;
			V[s++] = n - i;
		}
	}
	vector<int> Q = V;
	swap(Q[n - 1],Q[n - 2]);
	if(f(V) < f(Q)) swap(V,Q);
	swap(Q[n - 1],Q[n - 2]);
	swap(Q[2],Q[3]);
	if(f(V) < f(Q)) swap(V,Q);
	for(int i = 0;i < n;i++){
		if(i) cout << " ";
		cout << V[i];
	}
	cout << endl;
	return 0;
}