#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

inline int read(){
    int sum=0,flag=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-')flag=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
    return flag*sum;
}


int n,m;
int mp[201][201];
int ans=0,tmp;
int deep[1001],que[100001];

bool bfs(int s){
    int head=1,tail=1;
    memset(deep,0xff,sizeof(deep));
    que[1]=s;
    deep[s]=0;
    while(head<=tail){
        int x=que[head];
        for(int i=1;i<=m;i++){
            if(deep[i]<0&&mp[x][i]>0){
                que[++tail]=i;
                deep[i]=deep[x]+1;
            }
        }
        head++;
    }
    if(deep[m]>0) return 1;
    return 0;
}

int dfs(int x,int minn){
    if(x==m) return minn;
    int ret=0;
    for(int i=1;i<=m;i++){
        if(mp[x][i]&&deep[i]==deep[x]+1)
            if((ret=dfs(i,min(minn,mp[x][i])))){
                mp[x][i]-=ret;
                mp[i][x]+=ret;
                return ret;
            }
    }
    return 0;
}

int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++){
        int x=read(),y=read(),w=read();
        mp[x][y]+=w;
    }
    while(bfs(1)){
        while((tmp=dfs(1,INF))){
            ans+=tmp;
            
        }
    }
    printf("%d\n",ans);
    return 0;
}