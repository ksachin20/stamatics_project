#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
 
vector<int> adj[N];
bool visited[N];

int time_in[N];     
int time_out[N];    

int current_time=0; 

void dfs(int source)     // DFS function 
{
    time_in[source] = current_time;
    current_time++;
    visited[source] = true;         // maintaining visited array
    for (int child : adj[source])
    {
        
        if(!visited[child]){
            dfs(child);
        }
    }
    time_out[source] = current_time;
    current_time++;
}

bool tree_edge(int start,int end){
    return time_in[start] < time_in[end] && time_out[start] > time_out[end];
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
    dfs(2); // taking root node as 0 
    for (int i = 0; i < v; i++)
    {
        cout<<"Vertice : "<<i<<" In time: "<<time_in[i]<<" Out time: "<<time_out[i]<<"\n";    
    }
    for (auto edge:edges)
    {
        if(tree_edge(edge.first , edge.second)){
            cout<<"("<<edge.first<<","<<edge.second<<")"<<" -> tree edge\n";
        }
        else{
            cout<<"("<<edge.first<<","<<edge.second<<")"<<" -> back edge\n";
        }
    }
    return 0;
}
