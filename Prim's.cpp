/*
Prime's Algorithms for finding the Minimum Spanning Tree in an undirected, weighted graphs, edge weights are considered distinct and non-negative. The input format is as below : 
First line : <number of nodes in the graphs = n> <number of edges in the graphs = m>
Next m lines : <source node for edge j, considering 1 based indices> <destination> <edge weight>
*/
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 1003

int vis[N] = {0};
vector <pair <int, int> > v[N];
set <int> mst;

class edge{
	public : 
	    int s;
	    int d;
	    int w;
};

vector <edge> mstans;

int main(){
	ios::sync_with_stdio(false);
	int n, m; cin>>n>>m;
	int x, y, i, ans = 0, w, e, c;
	int minp, mine;
	while(m--){
		cin>>x>>y>>w;
		v[x].push_back({y, w});
		v[y].push_back({x, w});
	}
	edge temp;
	int temps, tempd, tempw;
	mst.insert(1);
	while(mst.size() != n){
		minp = 0, mine = INT_MAX;
		for(auto it : mst){
			for(auto p : v[it]){
				if(mst.find(p.first) != mst.end()) continue;
				else{
					if(p.second < mine){
						minp = p.first;
						mine = p.second;
						temps = it; tempd = minp; tempw = mine;
					}
				}
			}
		}
		ans = ans + mine;
		mst.insert(minp);
		temp.s = temps; temp.d = tempd; temp.w = tempw;
		mstans.push_back(temp);
	}
	cout<<"Total weight of the MST = "<<ans<<"\n";
	cout<<"Details of the MST edges\n"<<"Source"<<setw(15)<<"Destination"<<setw(15)<<"Weight\n";
	for(auto it : mstans){
		cout<<it.s<<setw(15)<<it.d<<setw(15)<<it.w<<"\n";
	}
	return 0;
}
