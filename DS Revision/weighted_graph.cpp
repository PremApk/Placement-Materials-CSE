#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 100001

struct node
{
	int n;
	vector<pair<int,int>> link;
	node(int n)
	{
		this->n = n;	
	}	
};

node *arr[MAX];
bool visited[MAX];

void dfs(int v,vector<int> &mem,int & cost)
{
	visited[v] = true;
	mem.push_back(v);
	for(auto & l : arr[v]->link)
	{
		if(!visited[l.first])
		{
			dfs(l.first,mem,cost);
			cost += l.second;		
		}				
	}
}

int main()
{
	int i,a,b,wt,v,e;
	cin>>v>>e;
	for(i=1;i<=v;i++)
	{
		arr[i] = new node(i);
		visited[i] = false;
	}
	for(i=1;i<=e;i++)
	{
		cin>>a>>b>>wt;
		arr[a]->link.push_back(make_pair(b,wt));
		arr[b]->link.push_back(make_pair(a,wt));
	}
	for(i=1;i<=v;i++)
	{
		vector<int> mem;
		int cost = 0;
		if(!visited[i])
		{
			dfs(i,mem,cost);
			cout<<"For node "<<i<<": ";
			for(auto &l : mem)
				cout<<l<<"->";
			cout<<"\n";
			cout<<"Cost for node "<<i<<": "<<cost<<"\n";
		}
	}
	return 0;
}
