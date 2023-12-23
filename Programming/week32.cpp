/*
该题是一道多重背包问题
因为本题有禁止购买商品
所以设立两个数组
f(i, j) 表示考虑前 i 种商品，花费 j 元能买的最大原件总和。
g(i, j) 表示考虑后 i 种商品，花费 j 元能买的最大原件总和。
对于单次询问 x, y，则把x元拆成两个部分（x1、x2）
前x1元用于买前y-1商品，后x2元用于买后y+1件商品 
*/ 
#include<bits/stdc++.h>
using namespace std;

const int M = 1000; //身上带的最多的钱
int C[800],V[800],K[800];
int F[801][3001], G[801][3001];

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	 scanf("%d%d%d",&C[i],&V[i],&K[i]);
	 
	
	//正序购买 
	//memset(F, 0, sizeof(F));
	for(int i=1;i<=N;++i){ //考虑第i个商品 
		for(int k=0;k<=K[i];++k){   //第i个商品考虑买k个 
			for(int c=k*C[i];c<=M;++c){  //买该商品花费的钱 
				F[i][c]=max(F[i][c], F[i-1][c-k*C[i]]+k*V[i]); //产生的最大收益 
			}
		}
		for(int c=1;c<=M;++c)
         F[i][c]=max(F[i][c], F[i][c-1]); 
	}
	
	//反序 
	//memset(G, 0, sizeof(G));
	for(int i=N;i>0;--i){  
		for(int k=0;k<=K[i];++k){   
			for(int c=k*C[i];c<=M;++c){  
				G[i][c]=max(G[i][c],G[i+1][c-k*C[i]]+k*V[i]);  
			}
		}
		for(int c=1;c<=M;++c)
         G[i][c]=max(G[i][c],G[i][c-1]); 
	}

	int q,x,y;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y); 
		++y;  //商品编号从0开始 
		
		int sum=0;//最大原价总和
		for(int c=0;c<=x;++c){
			sum=max(sum,F[y-1][c]+G[y+1][x-c]); //第y个商品禁买，花费c买前y-1个商品，花费x-c买后y+1个商品 
		}	
		printf("%d\n",sum);
	}
	return 0;
}




// ★输入样例
// 3
// 1 3 1
// 1 4 1
// 1 5 1
// 1
// 1 2
// ★输出样例
// 4
// ★样例解释
// 资金为 1 且不能购买编号为 2 的商品，因此选择购买 1 件编号为 1 的商品，得到的原价总和为 4 。