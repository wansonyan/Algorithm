// #include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include<string>
// using namespace std;
// int index[1001];
// struct _Node{
//     string s;
//     int index;
// } node[1001];
// void findStr(int k,string s){
//     for (int i = 0; i < s.size() - k + 1; i++){
//         node[i].s = s.substr(i, k);
//         node[i].index = i + 1;
//     }
// }
// bool sortStr(const _Node nd1,const _Node nd2){
//     return nd1.s < nd2.s;
// }
// int main()
// {
//     string s;
//     int k;
//     cin >> s >> k;
//     findStr(k, s);
//     sort(node, node + k, sortStr);
//     for (int i = 0; i < s.size() - k + 1; i++)
//     {
//         // if(i == 1)
//         //     cout << node[i].index;
//         // else
//         //     cout << node[i].index;
//         cout << node[i].index;
//     }
// }
#include <iostream>
#include <cmath>
using namespace std;

string s;
int k,n,m;
int b[100001];
int cmp(int left,int right){
	//k长度的子串，则有n-k+1个子串
	int i=0;
	for(i=0;i<k;)
	{
		if(s[left]==s[right]){
			left++;
            right++;
            i++;
		}else 
            break;
	}
	if(i==k){
		return 1;
	}
	if(s[left]<= s[right]) 
	{
	
		return 1;
	}else
        return 0;
	
}
void MergeSortArr(int arr[],int left,int mid,int right){//该函数同于将两个有序列合并成一个有序列，同时当两个有序列都为同一个元素是一样可以处理 
	int i = left,j = mid + 1;//两个索引用来遍历两个有序列 
	int k=0;//k用来遍历暂存数组temp 
	int temp[right-left+1];//开一个数组暂时存放
	while(i <=mid && j <= right){//对两个有序列进行遍历排序，有一个序列遍历完成结束循环 
		if(cmp(arr[i] , arr[j]))
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++]; 
	}
	while(i <= mid){//将另外一个没有遍历完全的有序列全部插入到temp中 
		temp[k++] = arr[i++];
	} 
	while(j <= right){
		temp[k++] = arr[j++];
	}
	//！！这里需要注意循环的条件里面不能使用left因为left的值在改变 
	for(i = 0;i < k;i++)//将排好序的序列更新到目标数组中 
		arr[left++] = temp[i];
}
//递归方法 
void MergeSort(int arr[],int left,int right){
	if(left == right)//如果两个划分为同一元素，递归结束 
		return ;
	int mid = (left + right) / 2;//对本个划分再次进行划分 
	MergeSort(arr, left, mid);//对左边的序列进行划分此条命令结束代表左边的序列已经有序 
	MergeSort(arr, mid+1, right);//对右边的序列进行划分此条命令结束代表右边的序列已经有序 
	MergeSortArr(arr, left, mid, right);//和并两个序列 
} 
int main()
{
    cin>>s;
    cin>>k;
    n=s.size();//n是字符串长度
    m=n-k+1;//子串个数
    for(int i=0;i<n;i++){
    	b[i]=i;//以子串起始下标作为子串的代表
	}
	MergeSort(b,0,m-1);
	for(int i=0;i<m;i++){
		b[i]++;
		cout<<b[i]<<"";
	}
	return 0;
    
}
// 定义比较函数，如果第一个字符相同则比较第二个字符，以此类推。
// 根据比较函数对子串进行排序