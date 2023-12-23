#include<iostream>
#include<bits/stdc++.h> 
#define N  100010
using namespace std;

int main(){
	int n=0;
	cin>>n;
    int s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	if(n <= 2){
		cout<<n;
		return 0;
	}
	int lp=0;
	int rp=0;
	int a[N]={0};
	int maxLen=0;
	int count=0;
	while(rp < n){
		if(a[s[rp]] == 0)count++;
		a[s[rp]]++;
		while(count > 2){
			a[s[lp]]--;
			if(a[s[lp]] == 0)count--;
			lp++;
		}
		maxLen = maxLen>rp-lp+1? maxLen:rp-lp+1;
		rp++;
	}
	cout<<maxLen<<endl;
	return 0;
}


// 使用双指针i和j，i表示当前输入的数的下标，j表示与下标为i的数保持最长合法区间的最远数的下标。
// 由于区间最多有两个相同的数，所以我们使用变量num1、num2来记录数字，count1、count2来记录数字在合法区间内出现的次数。
// 变量ans用于记录当前最大的合法区间长度。
// 我们将使用num2、count2作为接收新出现数字的载体；num1、count1作为接收num2被替代的数字的载体。
// 当出现的数字是两个变量中的一个时，此变量count++；当出现的数字不是两个变量中的任意一个时我们需要根据count的情况进行判断。
// 若count1=0则num1、count1接收num2、count2的值， num2、count2接收新的数字；
// 若count2=0则num2、count2接收新的数字。
// 都不等于0时使用l指针来逼近i遍历合法区间内的数字，直到合法区间内只剩下一个数字为止（某一count为0）
// int main(){
//     int n = 0;
//     cin >> n;
//     int a[n];
//     int count1 = 0, count2 = 0, num1 = 0, num2 = 0;
//     int j = 0;
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         if (a[i] != num1 && a[i] != num2)
//         {
//             while(j<i && count1>0 && count2>0){
//                 if(a[j]==num1)
//                     count1--;
//                 if(a[j]==num2)
//                     count2--;
//                 j++;
//             }
//             if(count1==0){
//                 count1 = count2;
//                 num1 = num2;
//             }
//             count2 = 1;
//             num2 = a[i];
//         }
//         else
//         {
//             if(a[i]==num1)
//                 count1++;
//             else
//                 count2++;
//         }
//         ans = i - j + 1 > ans ? i - j + 1 : ans;
//     }
//     cout << ans << endl;
//     return 0;
// }