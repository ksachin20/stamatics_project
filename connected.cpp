#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
vector<int> v1[N];

vector<int> connected_comp_id_vector(N,0);

int key = 1;

// using dfs 
void dfs(int vertex,vector<int> &temp)
{
    connected_comp_id_vector[vertex] = key;
    temp.push_back(vertex);
    for (auto child : v1[vertex])
    {
        if(connected_comp_id_vector[child]) continue;

        dfs(child , temp);
    }
}

int main(int argc, char const *argv[])
{
    int n , m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x , y;
        cin >> x >> y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        if(connected_comp_id_vector[i]) continue;
        dfs(i , temp);
        key++;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"Vertex: "<<i<<" ID:"<<connected_comp_id_vector[i]<<"\n";
    }
    
    return 0;
}
