#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 102
#define ll long long 

int sum[N][N], a[N][N], dp[N]; 

int main(){
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n; cin>>n;
	int i, j, k, ans, temp;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	for(i=0; i<n; i++){
		sum[i][0] = 0;
	}
	for(i=0; i<n; i++){
		for(j=1; j<=n; j++){
			sum[i][j] = sum[i][j-1] + a[i][j-1];
		}
	}
	ans = a[0][0];
	for(i=0; i<n; i++){
		for(j=i; j<n; j++){
			dp[0] = sum[0][j+1] - sum[0][i];
			ans = max(ans, dp[0]);
			for(k=1; k<n; k++){
				temp = sum[k][j+1] - sum[k][i];
				dp[k] = temp + max(0, dp[k-1]);
				ans = max(ans, dp[k]);
			}
		}
	}
	cout<<ans;
	return 0;
}
