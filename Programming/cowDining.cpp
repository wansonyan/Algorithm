#include<bits/stdc++.h>
using namespace std;
const int MAXN=30010;
const int INF=0x7fffffff;

inline int read(){
    int sum=0,flag=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-')flag=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
    return flag*sum;
}

bool check=true;
int deep[MAXN];
int fd,ans;//fd为当前最小的剩余容量
int link[MAXN],tot=1;
struct edge{
    int y,v,next;
}e[MAXN<<1];
int head,tail,q[MAXN];
int n,f,d;
void insert(int x,int y,int v){//建边
    e[++tot].y=y;e[tot].v=v;e[tot].next=link[x];link[x]=tot;
    e[++tot].y=x;e[tot].v=0;e[tot].next=link[y];link[y]=tot;
}
void init(){
     n=read();f=read();d=read();
     int sum=2+n+n+f+d;
     for(int i=1;i<=n;++i){
        insert(f+i+1,f+n+i+1,1);
        int x=read(),y=read();
        for(int j=1;j<=x;++j){
            int t=read();
            insert(t+1,f+i+1,1);
        }
        for(int j=1;j<=y;++j){
            int t=read();
            insert(f+n+i+1,f+n+n+t+1,1);
        }
     }
     for(int i=1;i<=f;++i)
        insert(1,i+1,1);
     for(int i=1;i<=d;++i)
        insert(f+n+n+i+1,sum,1);
     n=sum;
}
void bfs(){//构造分层图
    memset(deep,-1,sizeof(deep));
    head=tail=0;
    q[++tail]=1;deep[1]=0;
    while(head<tail){
        int k=q[++head];
        for(int i=link[k];i;i=e[i].next)
            if(e[i].v&&deep[e[i].y]<0){
                deep[e[i].y]=deep[k]+1;
                q[++tail]=e[i].y;
            }
    }
    if(deep[n]!=-1) check=true;
}
//dfs代表一次增广，函数返回本次增广的流量，返回0表示无法增广
int dfs(int k,int l){//l是整条增广路对最大流的贡献
    if(k==n) return l;
    int maxl=0;
    for(int i=link[k];i&&maxl<l;i=e[i].next){//优化当前弧
        int y=e[i].y;
        if(deep[y]==deep[k]+1&&e[i].v){//优化分层图
            if(fd=dfs(y,min(e[i].v,l-maxl))){
                maxl+=fd;
                e[i].v-=fd;
                e[i^1].v+=fd;
            }
        }
    }
    if(!maxl) deep[k]=-1;
    return maxl;
}
void dinic(){
    while(check){
        check=false;
        bfs();//要不停的建立分层图，如果bfs不到汇点才结束
        if(!check) break;
        //一次bfs要不停的找增广路，直到找不到为止
        while(fd=dfs(1,INF)) ans+=fd;
    }
}
int main(){
    init();
    dinic();
    printf("%d\n",ans);
    return 0;
}
