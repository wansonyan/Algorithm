#include<iostream>
#include<stdio.h>
using namespace std;

int getLen(int n){
    if(n==0)
        return 1;
	int len=0;
	while(n){
		n/=10;
		len++;
	}
	return len;
} 
int cal(long long int n){
	int dict[10] = {0,9,99,351,927,2151,4671,9783,20079,40743};
	long long int dig[10] = {0,1,10,100,1000,10000,100000,1000000,10000000,100000000};	
	int mon[9] = {1,2,4,8,16,32,64,128,256};//与以下的binary数组相配合，记录操作次数用的
	int len,highest,value;
	len = getLen(n);//取得位数 
	highest = n/dig[len];//取得最高位 
	value += dict[len-1] + (dict[len]-dict[len-1])/9*(highest-1);//len-1位的情况全部包括进来，最高位从1到highest-1的情况全部包括进来
	//对最高位为highest的数进行枚举 
	long long int res;
	for(int j=0;j<=9;j++){//从左往右数第二位 从0到9枚举
		//co<<j<<e;
		int binary[9] = {0,0,0,0,0,0,0,0,0};//二进制位类似于状态位
		if(j!=highest){//只取和最高位不相同的数，因为相同的数必然会包含在这些不同的数中
						//220:     枚举 0:  四类情况 200 202 220 222
						//         枚举 1:  四类情况 211 212 221 222
						//         枚举 2:  四类情况 222 222 222 222 
						//         枚举 3:  四类情况 233 232 223 222
						//         枚举 4:  四类情况 244 242 224 222
						//         枚举 5:  四类情况 255 252 225 222
						//         枚举 6:  四类情况 266 262 226 222
						//         枚举 7:  四类情况 277 272 227 222
						//         枚举 8:  四类情况 288 282 228 222
						//         枚举 9:  四类情况 299 292 229 222 
						//只需跳过枚举2并且第四列的数据删到只剩一个，剩下的就是可能出现的枚举，在和数据比大小，最后一列全部相同的情况总共出现9次
						//先挑出所有的比220小的数，再判断222是否小于220，大于就不操作，小于等于就要减掉多加上的8次 
			int cnt = 0;
			while(1){//不论与N的大小全部枚举出来,暴力解法				
				res=highest*dig[len];
				for(int i=8;i>=10-len;i--){
					if(binary[i]==0)
						res += dig[9-i]*j;
					else 
						res += dig[9-i]*highest;
				}	
				if(res<=n){
					value++;//只要res小于等于n就加进来 
				}
				for(int i=8;i>=10-len;i--){//+1操作 			
					if(binary[i]==0){
						binary[i] = 1;
						break;
					}else{
						binary[i] = 0;
					}				
				}
				cnt++;
				if(cnt==mon[len-1])
				 break;	//操作2^（len-1）方停止 
			} 
		}
	}//最后的res是全1的类型 
	if(res<=n) 
	  value -= 8;	
	return value;
}
// int main(){
// 	int n;
// 	int dict[10] = {0,9,99,351,927,2151,4671,9783,20079,40743};
// 	while(scanf("%d",&n)!=EOF){
// 		if(n==1000000000){
// 			cout<<dict[9]+1<<endl;
// 		}else if(n<=100){
// 			cout<<n<<endl;
// 		}else{
// 			cout<<cal(n)<<endl;	
// 		}
// 	}	
// 	return 0;
// }

int main(){
	int n;
	int dict[10] = {0,9,99,351,927,2151,4671,9783,20079,40743};
	cin>>n;
	if(n==1000000000){
 			cout<<dict[9]+1<<endl;
	}else if(n<=100){
 			cout<<n<<endl;
 		}else{
 			cout<<cal(n)<<endl;	
 		}
	return 0;
}