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

/* to keep track of visted nodes while performing bfs */
bool visited[MAXN];

/* Queue ADT to perform BFS */
queue<int> que;

// BFS utility
void bfs(int n)
{
	visited[n] = true;
	
	// to print in bfs order
	cout << n << " ";
	
	que.pop();	// Remove front most element from queue
	
	for(auto& l : arr[n]->links)
		if(!visited[l])
			que.push(l);		// add to front of queue if not visited
	
	if(!que.empty())
		bfs(que.front());		// Go to the first element in queue
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
	 * If the entire graph is connected, just add que.push(1); and use bfs(1); once
	 * Although, the loop will work for all cases, so it's safe to stick with it.
	*/
	for (int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			que.push(i);
			bfs(i);
		}
	}
	
	
	return 0;
}
