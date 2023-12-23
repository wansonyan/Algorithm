#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

 int flag=-1;//定义一个全局变量标记字符串最初是回文串还是删除一个字符后是回文串
           //若x==-1 则字符串本身就是回文串
bool isString(const string &s,int low,int high){
    for(int i=low,j=high;i<j;++i,--j){
        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}


int isHuiwenString(string s){
    int low=0,high=s.length()-1;
    while (low<high)
    {
        char s1=s[low],s2=s[high];
        if(s1==s2){
            ++low;
            --high;
        }else{
            if(isString(s,low,high-1)){
                flag=high;
                return 1;
            }
            else if(isString(s,low+1,high)){
                flag=low;
                return 1;
            }
            else
            return 0;
        }
    }
    return 1;
}

string s;
int main(){
    cin>>s;
    int n=s.length();
    int str=isHuiwenString(s);
    if(str==0)
        cout<<"false"<<endl;
    else{
        for(int i=0;i<n;i++)
            if(i==flag){
             continue;
        }
        cout<<"true"<<endl;
    }
    return 0;
}

