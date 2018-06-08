#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 1003

int w[N];
string codes[N];
int len[N];

class node{
	public:
		int data;
		int freq;
		node* left;
		node* right;
		string code;
};

vector <node> nodes;

node findMin(){ // This is actually find and "erase" min
	int ans = INT_MAX;
	vector <node>::iterator it, pos;
	for(it = nodes.begin(); it != nodes.end(); it++){
		if(ans > (*it).freq){
			pos = it;
			ans = (*it).freq;
		}
	}
	node ansnode = (*pos);
	nodes.erase(pos);
	return ansnode;
}

node build(){
	while(!nodes.empty()){
		node* temp = new node;
		node* l = new node;
		node* r = new node;
		*l = findMin();
		*r = findMin();
		temp->left = l;
		temp->right = r;
		temp->freq = (l->freq) + (r->freq);
		nodes.push_back(*temp);
		if(nodes.size() == 1) break;
	}
	return nodes[0];
}

void bfs(node* temp, string s){
	node* root = new node;
	root = temp;
	root->code = s;
	string lcode = s + "0";
	string rcode = s + "1";
	if(root == NULL) return;
	else if(root->left == NULL && root->right == NULL){
		codes[root->data] = root->code;
		len[root->data] = (root->code).length();
	}
	else{
		root->left->code = lcode;
		root->right->code = rcode;
		bfs(root->left, lcode);
		bfs(root->right, rcode);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n; cin>>n;
	int i;
	for(i=1; i<=n; i++){
		cin>>w[i];
		node temp;
		temp.data = i;
		temp.freq = w[i];
		temp.left = NULL;
		temp.right = NULL;
		nodes.push_back(temp);
	}
	node root = build();
	bfs(&root, "");
	for(i=1; i<=n; i++){
		cout<<i<<" "<<len[i]<<" "<<codes[i]<<"\n";
	}
	return 0;
}
