//定义起始指针和结束指针，通过这个两个指针寻找最大的长度
#include<iostream>
#include<stdio.h>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//定义需要返回的长度len
		int len_MAX = 0;
		//随时记录长度
		int	len = 0;
		//考虑没有元素或只有一个元素的字符串
		if (s.length() == 0)
		{
			return 0;
		}
		if (s.length() == 1)
		{
			return 1;
		}

		//下面是字符串长度为2及2以上的情况
		//定义起始指针和尾指针
		int pStart = 0;
		int pEnd = 0;
		//定义一个标志判断字符串是否有相同元素,存在则置1，不存在则置0
		int flag = 0;
			for (pEnd = pStart + 1; pEnd < s.length(); pEnd++)
			{
				//判断尾部和之前的元素是否相等，
				//如果相等则记录此时的长度，并比较取最大，同时移动头指针到相同元素的位置
				//如果不等则继续，
				//定义一个用于遍历头和尾之间的指针t
				for (int t = pStart; t < pEnd; t++)
				{
					if (s[t] == s[pEnd])
					{
						len = pEnd - pStart;
						if (len > len_MAX)
						{
							len_MAX = len;
						}
                        //不能将pEnd赋值给pStart
                        //"dvdf"这个情况无法解决
						pStart = t+1;
						flag = 1;
					}
				}
				//如果最后一段出现了最长字符串且此时没有相同元素
				if (pEnd == s.length() - 1)
				{
					len = pEnd - pStart + 1;
					if (len > len_MAX)
					{
						len_MAX = len;
					}
				}
			}

		
		return len_MAX;
	}
};