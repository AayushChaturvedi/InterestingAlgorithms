#include <bits/stdc++.h>

using namespace std;

class CN{
public: 
	int real;
	int img;
	CN():real(0), img(0){}
	friend ostream& operator<<(ostream &, const CN &);
	friend istream& operator>>(istream &, CN &);
	CN operator+(const CN &x){
		CN ans;
		ans.real = real + x.real;
		ans.img = img + x.img;
		return ans;
	}
	CN operator-(const CN &x){
		CN ans;
		ans.real = real - x.real;
		ans.img = img - x.img;
		return ans;
	}
	CN operator*(const CN &x){
		CN ans;
		ans.real = real*x.real - img*x.img;
		ans.img = real*x.img + x.real*img;
		return ans;
	}
};

ostream& operator<<(ostream &Out, const CN &x){
	Out<<"("<<x.real<<") + i("<<x.img<<")\n";
	return Out;
}

istream& operator>>(istream &Inp, CN &x){
	Inp>>x.real>>x.img;
	return Inp;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	CN z1, z2;
	cin>>z1>>z2;
	cout<<"Complex Number1 is ="<<z1<<"\n";
	cout<<"Complex Number2 is ="<<z2<<"\n";
	cout<<"z1 + z2 = "<<(z1+z2)<<"\n";
	cout<<"z1 - z2 = "<<(z1-z2)<<"\n";
	cout<<"z1 * z2 = "<<(z1*z2)<<"\n";
	return 0;
}
