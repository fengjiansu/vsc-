#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a=1,b=1,c;
	cin>>n;
	if(n==1||n==2) cout<<1;
	for(int i=3;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}

	
	cout<<c;

	return 0;
}