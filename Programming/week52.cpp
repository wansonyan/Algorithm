#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(long long &balls,long long &b){
    return balls>b;
}

int main(){
    long long n,m,balls[100000],b[100000],needs[100000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>balls[i];
        b[i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>needs[i];
    }
    sort(needs,needs+m,cmp);
    for(int i=0;i<n;i++){
        if(balls[i]==-1)
            continue;
        b[i]++;
        for(int j=i+1;j<n;j++){
            if(balls[i]==balls[j]){
                balls[j]=-1;
                b[i]++;
            }
        }
    }
    sort(b,b+n,cmp);
    int i,j;
    for(i=0,j=0;i<n&&j<m;i++){
        while(needs[j]==0&&j<m){
            j++;
        }
        if(j==m){
            break;
        }
        if(b[i]<needs[j]){
            cout<<"false"<<endl;
            return 0;
        }
        for(int l=j;l<m;l++){
            if(b[i]>needs[l]){
                b[i]=b[i]-needs[l];
                needs[l]=0;
            }
        }
        j++;
    }
    cout<<"true"<<endl;
    return 0;
}