#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 100001


struct node
{
	int n;
	vector<int> link;
	node(int num)
	{
		this->n = num;
	}
};

node * arr[MAX]; 
bool visited[MAX];

void dfs(int v, vector<int> &mem,int& clink)
{
	visited[v] = true;
	clink++;
	mem.push_back(v);
	for(auto & l : arr[v]->link)
	{
		if(!visited[l])
			dfs(l,mem,clink);
	}
}


int main()
{
	int n,i,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		arr[i] = new node(i);
		visited[i] =  false;
	}
	int a,b;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		arr[a]->link.push_back(b);
		arr[b]->link.push_back(a);
	}
	vector<int> countlink;
	for(i=1;i<=n;i++)
	{
		int c = 0;
		vector<int> mem;
		if(!visited[i])
		{
			dfs(i,mem,c);
			countlink.push_back(c);
			cout<<"For node "<<i<<": ";
			for(auto & p : mem)
				cout<<p<<"->";
			cout<<"\n";
			cout<<c<<"\n";
		}
			
	}
	return 0;
}
