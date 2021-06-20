#include<bits/stdc++.h>
#define MAXN 100001
#define INF 1e9

using namespace std;

// structure defining each node in the graph
struct node
{
	int n;
	
	// Vector of pair of integers to store links along with weights
	// pair.first -> node number
	// pair-second -> weight
	vector<pair<int,int>> links;
	
	node(int n)
	{
		this->n = n;
	}
};

/* array to store direct pointers */
node* arr[MAXN];


void dijkstras(int src, int n)
{
	/* Result array (will contain final shortest paths from source to all other nodes) */
	int dist[n+1];
	
	/*
	 * This set will serve as our heap from where we can get next node to visit in O(1)
	 * Set is implemented as a balanced tree, so we'll have O(logn) insert and delete
	 * Greedy method - So, minheap will always give shortest path
	 * Opposite of how we are storing links (i.e)
	 * 		pair.first -> distance from source (total weight)
	 * 		pair.second -> node number
	 * distance is stored first because sorting of pairs is done based on first value.
	 * and we want the least distance to be first (Greedy)
	*/
	set<pair<int,int>> heap;
	
	/* to keep track of which nodes we have finalized (calculated shortest path) */
	bool visited[MAXN];
	
	// initialze values
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
		visited[i] = false;
		heap.insert({INF,i});
	}
	
	// Starting from source node
	dist[src] = 0;
	visited[src] = true;
	
	
	// Finding source node entry in heap
	// auto will assume the actual iterator type (set<pair<int,int>>::iterator)
	auto iter = heap.find({INF,src});
	
	if(iter != heap.end())		// Make sure we find source in heap
		heap.erase(iter);
		
	// Changing distance of src to 0 (to start from source)
	heap.insert({0,src});
	
	// Loop till we've visited all nodes (till heap is empty)
	while(!heap.empty())
	{
		// first element in heap is where we wanna go
		auto it = heap.begin();
		
		// Make a copy of the element
		// elem.first -> total distance from source
		// elem.second -> node number
		pair<int,int> elem = *it;
		
		// Remove from heap (we've finalized this node now)
		heap.erase(it);			
			
		// Mark as visited
		visited[elem.second] = true;
		
		// Update final distance 
		dist[elem.second] = elem.first;
		
		/*
		 * Check all links from this node
		 * Update distance if haven't visited node already and distance through this node is lesser
		 * l.first -> link;   l.second -> weight of that link
		*/
		for(auto& l : arr[elem.second]->links)
		{
			if(!visited[l.first] && dist[elem.second] + l.second < dist[l.first])
			{
				auto iter = heap.find({dist[l.first],l.first});
	
				// remove old entry from heap
				if(iter != heap.end())
					heap.erase(iter);
				
				// Update distance on distance array, and add new entry to heap
				
				dist[l.first] = dist[elem.second] + l.second;
				
				heap.insert({dist[l.first],l.first});
			}
		}
	}
		
	// Print final distances
	cout << "From " << src << " to :- \n";
	for (int i = 1; i <= n; i++)
		cout << i << " -> " << dist[i] << endl;
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
	
	int u, v, w;
	
	// get input of m edges (with weights)
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		
		// add link - adding to both nodes link vector (bidirectional link)
		arr[u]->links.push_back({v,w});
		arr[v]->links.push_back({u,w});
	}
	
	dijkstras(1, n);
	
	return 0;
}
