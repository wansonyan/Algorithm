#include<iostream>
#include<string.h>
using namespace std;
string s[1024] = {" /\\", "/__\\"};

void dfs(int n){
	int step = (1<<n-1);//左移
	for(int i=2*step-1; i>=step; --i){
		s[i] = s[i-step];
		for(int j=1; j<2*step-i; j++)
         s[i]+=" ";
		s[i] += s[i-step];
	}
	string tmp;
	for(int i=step-1; i>=0; --i){
		tmp = "";
		for(int j=1; j<=step; j++)
         tmp+=" ";
		s[i] = tmp + s[i];
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=2; i<=n; i++)
     dfs(i);
	for(int i=0; i<=(1<<n)-1; ++i){
		cout<<s[i]<<endl;
	}
	return 0;
}