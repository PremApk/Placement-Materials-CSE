#include<bits/stdc++.h>
#define MAXN 100001

using namespace std;

// structure defining each node in the graph
struct node
{
	int n;
	vector<int> links;
	
	node(int n)
	{
		this->n = n;
	}
};

/* array to store direct pointers */
node* arr[MAXN];

/* to keep track of visted nodes while performing dfs */
bool visited[MAXN];

// DFS utility
void dfs(int n)
{
	visited[n] = true;
	
	// to print in dfs order
	cout << n << " ";
	
	for(auto& l : arr[n]->links)
		if(!visited[l])
			dfs(l);
}

int main()
{
	// n = number of nodes
	// m = number of edges
	int n, m;
	
	cin >> n >> m;
	
	// initialize all nodes
	for (int i = 1; i <= n; i++)
		arr[i] = new node(i);
	
	
	int u, v;
	
	// get input of m edges
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		
		// add link - adding to both nodes link vector (bidirectional link)
		arr[u]->links.push_back(v);
		arr[v]->links.push_back(u);
	}
	
	/*
	 * This for loop is only needed when it's not a connected graph
	 * i.e The graph is divided into seperate components
	 * If the entire graph is connected, just use dfs(1); once
	 * Although, the loop will work for all cases, so it's safe to stick with it.
	*/
	for (int i = 1; i <= n; i++)
	{
		if(!visited[i])
			dfs(i);
	}
	
	
	return 0;
}
