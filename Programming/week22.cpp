#include<bits/stdc++.h>
using namespace std;

int N,L,R;

int df(int n, long long Len, int pos){
	if(R<pos-Len/2 || pos+Len/2<L)
	 return 0;
	if(Len==1)
	 return  n%2;
	
	int dis = (Len+1)/4;
	if(L<=pos && pos<=R)
	 return df(n/2, Len/2, pos-dis) + n%2 + df(n/2, Len/2, pos+dis);
	if(R<pos)
	 return df(n/2, Len/2, pos-dis);
	if(pos<L)
	 return df(n/2, Len/2, pos+dis);
} 

int main(){
	cin>>N>>L>>R;
	long long Len=0;
	for(int i=0; pow(2,i)<=N; ++i)
	 Len+=pow(2,i);
	cout<<df(N, Len, (1+Len)/2)<<endl;
	return 0;
}