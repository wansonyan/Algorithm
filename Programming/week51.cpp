// 先排序，也可以不排序
//使用DFS暴力搜索，过程中进行剪枝
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
void dfs(vector<long long> &papers, vector<int> &time, int k, int idx)
{
	if (idx == papers.size())
	{
		int t = *max_element(time.begin(), time.end());
		if (t < ans)
			ans = t;
		return;
	}
	for (int i = 0; i < k; i++)
	{
		if (time[i] + papers[idx] > ans)
			continue;
		time[i] += papers[idx];
		dfs(papers, time, k, idx + 1);
		time[i] -= papers[idx];
		if (time[i] == 0)
			break;
	}
}
int minmaxReadingTime(vector<long long> &papers, int k)
{
	int n = papers.size();
	sort(papers.begin(), papers.end());
	vector<int> time(k, 0);
	dfs(papers, time, k, 0);
	return ans;
}


int main()
{
	int n, k, l;
	vector<long long> papers;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		papers.push_back(l);
	}
	int sum;
	sum=minmaxReadingTime(papers,k);
	cout<<sum<<endl;
}