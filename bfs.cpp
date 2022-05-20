#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
vector<int> adj[N];
bool visited[N];


vector<int> distance_vector(N,-1);   //assigning all value with -1 so that those unreachable be it -1

void bfs(int source){          // BFS function
    queue<int> q;
    q.push(source);
    visited[source] =true;
    distance_vector[source]=0;

    while (!q.empty())
    {
        int crt_node = q.front();
        q.pop();
        for(int child : adj[source])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=true;
                distance_vector[child]=distance_vector[crt_node]+1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int v , e;
    cin >> v >> e; // input no of vertices and edges
    
    vector<pair<int,int> > edges;
    for (int i = 0; i < e; i++)
    {
        int x , y;
        cin >> x >> y;
        edges.push_back({x,y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1); // taking root node as 1


    
    for (int i = 0; i < v; i++)    //printing output
    {
        cout<<"Vertex : "<<v<<" Distance: "<<distance_vector[v]<<"\n";
    }
    
    return 0;
}