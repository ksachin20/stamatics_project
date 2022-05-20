#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

vector<int> v1[N];
bool visited[N];

bool dfs(int vertex,int parent)
{
    visited[vertex] = true;
    bool w = false;
    for (auto child : v1[vertex])
    {
        if(visited[child] && child != parent) return true;

        if(visited[child]) continue;

        w = dfs(child,vertex);
    }
    return w;
}

int main(int argc, char const *argv[])
{
    int v , e;
    cin>> v >> e;
    for (int i = 0; i < e; i++)
    {
        int x , y;
        cin >> x >> y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    for (int i = 0; i < v; i++)
    {
        if(visited[i]) continue;

        if(dfs(i,-1))
        {
            cout<<"Cycle is present In the Graph\n";
            return 0;
        }
    }
    cout<<"Cycle Not Present\n";
    return 0;
}
