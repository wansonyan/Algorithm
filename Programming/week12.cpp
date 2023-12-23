#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	string input;
	cin>>input>>k;
	int len = input.size()-k+1;
	for(int a=0; a<26; a++) {
		multimap<string,int> node;
		for(int i=0; i<len; i++) {
			char head = input[i];
			if(head == (char)(a+'a'))
				node.insert(pair<string,int>(input.substr(i,k),i+1));
		}
		if(!node.size()) continue;
		multimap <string,int>::iterator it ;
		for(it= node.begin(); it!=node.end(); ++it) {
			printf("%d ",it->second);
		}
		node.clear();
	}
	return 0;
}
