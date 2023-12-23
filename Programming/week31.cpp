#include<iostream>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
   int n,a[3000];
   cin>>n;
   for(int i=0;i<n;i++) 
   cin>>a[i];

   int maxLen=0;
   unordered_map<int, int> mp;
   for(int i = 0; i < n; i ++) {
        mp[a[i]] = i;
    }

    for(int i = 0; i < n - 1; i ++) {
        for(int j = i + 1; j < n; j ++) {
            int p = a[i];
            int q = a[j];
            // 定义当前长度
            int cur = 2;
            while(mp.count(p + q)) {
                int count = p + q;
                p = q;
                q = count;
                cur ++;
            }
            maxLen = max(maxLen, cur);
        }
    }
    if(maxLen>=3){
        cout<<maxLen<<endl;
    }else
    cout<<-1<<endl;
}




