#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 300005
#define M 30
#define ll long long 
#define ld long double
#define pb push_back
#define ff first
#define ss second

struct trie{
	int zero, one, l, r;
};

trie t[N*M];
int a[N], p[N];
int cur = 2, n;

void add(int x){
	int b, node = 1;
	for(b=M; b>=0; b--){
		if(x & (1<<b)){
			if(!t[node].one) t[node].one = cur++;
			t[node].r++;
			node = t[node].one;
		}
		else{
			if(!t[node].zero) t[node].zero = cur++;
			t[node].l++;
			node = t[node].zero;
		}
	}
}

void del(int x){
	int b, node = 1;
	for(b=M; b>=0; b--){
		if(x & (1<<b)){
			t[node].r--;
			if(t[node].r == 0){
				t[node].one = 0; break;
			}
			node = t[node].one;
		}
		else{
			t[node].l--;
			if(t[node].l == 0){
				t[node].zero = 0; break;
			}
			node = t[node].zero;
		}
	}
}

int get(int x){
	int b, node = 1, po, ans;
	ans = 0;
	for(b=M; b>=0; b--){
		po = (1<<b);
		if(x & po){
			if(!t[node].one){
				ans = ans + po;
				node = t[node].zero;
			}
			else node = t[node].one;
		}
		else{
			if(!t[node].zero){
				ans = ans + po;
				node = t[node].one;
			}
			else node = t[node].zero;	
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	int i, ans;
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	for(i=0; i<n; i++){
		cin>>p[i];
		add(p[i]);
	}
	for(i=0; i<n; i++){
		ans = get(a[i]);
		cout<<ans<<" ";
		del(a[i] ^ ans);
	}
	return 0;
}
