#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 10004
#define M 20
#define ll long long 
#define ld long double
#define pb push_back
#define ff first
#define ss second

vector <int> g[N];
int tin[N], tout[N], dp[N][M];
bool isroot[N];
int timer;
int n, m, tot;

void init(){
	timer = 0;
	for(int i=1; i<=n; i++){
		isroot[i] = true;
		g[i].clear();
	}
	tot = log2(n);
	if(1<<tot < n) tot++;
}

void dfs(int node, int par){
	tin[node] = ++timer;
	dp[node][0] = par;
	for(int i=1; i<=tot; i++){
		dp[node][i] = dp[dp[node][i-1]][i-1];
	}
	for(auto it : g[node]){
		if(it != par){
			dfs(it, node);
		}
	}
	tout[node] = ++timer;
}

bool ispar(int x, int y){
	return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int lca(int x, int y){
	if(ispar(x, y)) return x;
	if(ispar(y, x)) return y;
	for(int i=tot; i>=0; i--){
		if(!ispar(dp[x][i], y)){
			x = dp[x][i];
		}
	}
	return dp[x][0];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, T; cin>>T;
	int u, v, i, j, q;
	for(t=1; t<=T; t++){
		cin>>n;
		init();
		for(i=1; i<=n; i++){
			cin>>m;
			while(m--){
				cin>>j;
				isroot[j] = false;
				g[i].pb(j);
				g[j].pb(i);
			}
		}
		for(i=1; i<=n; i++){
			if(isroot[i]){
				dfs(i, i);
				break;
			}
		}
		cout<<"Case "<<t<<":\n";
		cin>>q;
		while(q--){
			cin>>u>>v;
			cout<<lca(u, v)<<"\n";
		}
	}
	return 0;
}
