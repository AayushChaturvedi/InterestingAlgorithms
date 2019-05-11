#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 100005
#define M 30
#define ll long long 
#define ld long double
#define pb push_back
#define ff first
#define ss second

int lg2[N] = {0};
int spart[N][M] = {0};
int a[N];
int n, m, i, j, l, r;

void init(){
	lg2[2] = 1;
	for(i=3; i<N; i++){
		lg2[i] = lg2[i/2] + 1;
	}
	for(i=0; i<n; i++){
		spart[i][0] = a[i];
	}
	for(j=1; j<M; j++){
		for(i=0; i + (1<<j) < N; i++){
			spart[i][j] = min(spart[i][j-1], spart[i + (1<<(j-1))][j-1]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	init();
	cin>>m;
	while(m--){
		cin>>l>>r;
		j = lg2[r-l+1];
		cout<<min(spart[l][j], spart[r-(1<<j)+1][j])<<"\n";
	}
	return 0;
}   
