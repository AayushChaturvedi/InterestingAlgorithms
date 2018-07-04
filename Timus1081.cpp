#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 102

int dp[N];

void show(int n, int k){
	if(n == 0)
		return;
	if(n == 1 && k == 1){
		cout<<"0";
		return;
	}
	else if(n == 1 && k == 2){
		cout<<"1";
		return;
	}
	if(k <= dp[n-1]){
		cout<<"0";
		show(n-1, k);
	}
	else{
		cout<<"10";
		show(n-2, k-dp[n-1]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n, k, i; cin>>n>>k;
	dp[1] = 2; dp[2] = 3;
	for(i=3; i<44; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	if(k > dp[n]){
		cout<<"-1";
		return 0;
	}
	show(n, k);
	return 0;
}
