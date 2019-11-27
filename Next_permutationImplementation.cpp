#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 1000006
#define M 30
#define ll long long 
#define ld long double
#define pb push_back
#define ff first
#define ss second

int a[N], ac[N];

void init(int n){
	for(int i=1; i<=n; i++){
		a[i] = rand()%N;
		ac[i] = a[i];
	}
}

void print(int x, int n){
	if(x == 0){
		for(int i=1; i<=n; i++){
			cout<<a[i]<<" ";
		}
	}
	else{
		for(int i=1; i<=n; i++){
			cout<<ac[i]<<" ";
		}	
	}
	cout<<"\n";
}

void NP(int n){
	int i, j;
	i = n;
	while(i > 1 && a[i-1] >= a[i]) i--;
	if(i == 1) return;
	j = n;
	while(a[j] <= a[i-1]) j--;
	swap(a[j], a[i-1]);
	j = n;
	while(i < j){
		swap(a[i], a[j]);
		i++; j--;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	srand(time(0));
	int i, j, n;
	cin>>n;
	init(n);
	/*for(i=1; i<=n; i++){
		cin>>a[i];
	}*/
	print(0, n);
	print(1, n);
	NP(n);
	print(0, n);
	next_permutation(ac+1, ac+n+1);
	print(1, n);
	return 0;
}
