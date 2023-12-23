#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
   long long  n,k,a[100000],b[100000];
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		if(a[i]==-1)
			continue;
		b[i]++;
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				a[j]=-1;
				b[i]++;
			}
		}
	}
	while(k>0){
		long long min = n , index;
		for(int i=0;i<n;i++){
			if(b[i]!=0&&b[i]<min){
				min = b[i];
				index = i;
			}
		}
		if(k<min){
			k=0;
		}else{
			k = k - min;
			b[index] = 0; 
		}
	}
	long long num = 0;
	for(int i=0;i<n;i++){
		if(b[i]!=0){
			num++;
		}
	}
	cout<<num;
	return 0;
}
