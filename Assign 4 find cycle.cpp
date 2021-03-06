#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int a, b;
     int cost;
};

int n, m;
vector<Edge> edges;

void place()
{
	cin >> n >> m;
	int ai, bi, c;
	while (m--)
	{
		cin >> ai >> bi >> c;
		struct Edge e = {ai-1, bi-1, c};
		edges.push_back(e);
	}
	vector<long long> d(n, 0);
	vector<int> p(n, -1);
	int w;
	for (int i = 0; i < n; ++i)
	{
		w = -1;
		for (struct Edge e : edges)
		{
			if (d[e.a] + e.cost < d[e.b])
			{
				d[e.b] = d[e.a] + e.cost;
				p[e.b] = e.a;
				w = e.b;
			}
		}
	}

	if (w == -1)   
	{
		cout << "NO\n";
	}
	else
	{
		for (int i = 0; i < n; ++i)
        {
            w = p[w];
        }
		vector<int> cycle;
		for (int v = w;; v = p[v])
		{
			cycle.push_back(v);
			if (v == w && cycle.size() > 1)
            {
                break;
            }
				
		}
    
		reverse(cycle.begin(), cycle.end());

		cout << "YES\n";
		for (auto q : cycle)
        {
            cout << q+1<< ' ';
        }	
		cout << endl;
	}
}

int main()
{
	place();
	return 0;
}