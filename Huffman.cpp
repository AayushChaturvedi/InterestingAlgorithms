#include <bits/stdc++.h>

using namespace std;

#define N 500
#define ff first
#define ss second
#define ld long double

string s, t;
map <int, int> mp;
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
	freopen("inputhuffman.txt", "r", stdin);
	getline(cin, s);
	for(auto it : s){
		mp[it - ' ']++;
	}
	for(auto it : mp){
		node temp;
		temp.data = it.ff;
		temp.freq = it.ss;
		temp.left = NULL;
		temp.right = NULL;
		nodes.push_back(temp);
	}
	node root = build();
	bfs(&root, "");
	/*
	// Uncomment to see the codes for each character
	for(auto it : mp){
		cout<<char(it.ff + ' ')<<" "<<len[it.ff]<<" "<<codes[it.ff]<<"\n";
	}
	*/
	t = "";
	for(auto it : s){
		t += codes[it - ' '];
	}
	/*
	// Uncomment to print the orginal texts.
	cout<<"Original String:\n";
	cout<<s<<"\n";
	cout<<"Encoded string:\n";
	cout<<t<<"\n";
	*/
	ld l1 = s.length()*7;
	ld l2 = t.length();
	cout<<"Original length:\t"<<l1<<"\nEncoded length :\t"<<l2<<"\n";
	cout<<"Percentage compression:\n";
	ld ans = (l2)/l1;
	ans = ans * 100;
	cout<<setprecision(5)<<fixed<<ans<<"%";
	return 0;
}
