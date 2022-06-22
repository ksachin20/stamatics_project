#include<bits/stdc++.h>

using namespace std;

# define INF 1e18LL
#define M 1000000007

typedef pair<long long, int> pairup;


class Graph                    // this class represents a directed graph using adjacency list representation
{
	int V;                               // no. of vertices

	list< pair<long long, int> > *adj;    //it is weighed graph so it store weigh

public:
	Graph(int V);                           // Constructor

	
	void addEdge(int u, int v, int w);            //to add edge to graph

	
	void shortestPath(int s);    // to get shortest graph
};

Graph::Graph(int V)                    // allocation of memory for adjacency list
{
	this->V = V;
	adj = new list<pairup> [V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
}


void Graph::shortestPath(int src)
{
	
	priority_queue< pairup, vector <pairup> , greater<pairup> > pq;          //create priority queue i.e. max heap

	vector<long long> dist(V, INF);                 // vector which store distance and initialise with infinite value
	vector<int> totalWays(V,0);
	vector<int> mnmFlight(V, INF);
	vector<int> mxmFlight(V,0);
	totalWays[src]=1;
	mxmFlight[src]=mnmFlight[src]=0;

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
        long long w=pq.top().first;
        
		pq.pop();
        if(dist[u]<w) continue;

		list< pair<long long, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;                // get vertex label and weight of current adjacent of u
			int weight = (*i).second;

			if (dist[v] == dist[u] + weight)                  // updating distance of v, if there is shorted path to v through u
			{
				totalWays[v]=(totalWays[v]%M+totalWays[u]%M)%M;
				mnmFlight[v]= min(mnmFlight[v], mnmFlight[u]+1);
				mxmFlight[v]=max(mxmFlight[v], mxmFlight[u]+1);
				// pq.push(make_pair(dist[v], v));
				
			}
			else if (dist[v] >dist[u] + weight)
			{
				dist[v] = dist[u] + weight;             // updation of distance of v
				totalWays[v]=totalWays[u]%M;
				mxmFlight[v]=mxmFlight[u]+1;
				mnmFlight[v]=mnmFlight[u]+1;
				pq.push(make_pair(dist[v], v));
				
			}
			
		}
	}

	
cout<<dist[V-1]<<" "<<totalWays[V-1]<<" "<<mnmFlight[V-1]<<" "<<mxmFlight[V-1]<<endl;           // this print shortest distance dist[V-1]
}

int main()
{
    int n, m;
    cin>>n;
    Graph g(n);
    cin>>m;
    int a, b, c;
    while(m--)
    {
        cin>>a>>b>>c;
        g.addEdge(a-1, b-1, c);
    }
	g.shortestPath(0);

	return 0;
}