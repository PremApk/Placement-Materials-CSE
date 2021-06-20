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

int main()
{
	int i,m,e;
	int a,b;
	cin>>m>>e;
	for(i=1;i<=m;i++)
	{
		arr[i] = new node(i);
		visited[i] = false;
	}
	for(i=1;i<=e;i++)
	{
		cin>>a>>b;
		arr[a]->link.push_back(b);
		arr[b]->link.push_back(a);
	}
	queue<node*> q;
	visited[1] = true;
	q.push(arr[1]);
	while(!q.empty())
	{
		struct node * temp = q.front();
		cout<<temp->n;
		q.pop();
		for(auto & l : temp->link)
		{
			if(!visited[l])
			{	
				visited[l] = true;
				q.push(arr[l]);
			}	
		}
	}
}
