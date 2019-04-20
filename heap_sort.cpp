#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 1000006
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

void print(int n){
	for(int i=1; i<=n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void max_heapify(int i, int n){
	int l = 2*i;
	int r = 2*i + 1;
	int largest = i;
	if(l <= n && a[l] > a[largest]){
		largest = l;
	}
	if(r <= n && a[r] > a[largest]){
		largest = r;
	}
	if(largest != i){
		swap(a[largest], a[i]);
		max_heapify(largest, n);
	}
}

void build_max_heap(int n){
	for(int i=n/2; i>=1; i--){
		max_heapify(i, n);
	}
}

void heap_sort(int n){
	build_max_heap(n);
	int sz = n;
	for(int i=n; i>=2; i--){
		swap(a[1], a[i]);
		sz--;
		max_heapify(1, sz);
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input1.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand(time(0));
	int n, t;
	cin>>t;
	while(t--){
		cin>>n;
		init(n);
		clock_t clk = clock();
		heap_sort(n);
		clk = clock() - clk;
		cout<<"heap_sort vs C++17 sort():";
		cout<<fixed<<setprecision(6)<<setw(10)<<n<<" "<<setw(15)<<((double)clk)/CLOCKS_PER_SEC<<" ";
		clk = clock();
		sort(ac+1, ac+n+1);
		clk = clock() - clk;
		cout<<fixed<<setprecision(6)<<setw(15)<<((double)clk)/CLOCKS_PER_SEC<<"\n";
	}
	return 0;
}
