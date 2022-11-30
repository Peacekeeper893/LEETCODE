#include<bits/stdc++.h>
using namespace std;


int main()
{
    

    return 0;
}
class DSU {
    int* parent;
    int* rank;
 
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
   
    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
 
class Graph {
    vector<pair<int, pair<int, int>>> edgelist;
    int V;
 
public:
    Graph(int V) { this->V = V; }
 
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w,{ x, y} });
    }
 
    int kruskals_mst()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());
 
        // Initialize the DSU
        DSU s(V);
        int ans = 0;

        // cout << "Following are the edges in the constructed MST"<< endl;
        for (auto edge : edgelist) {
            int w = edge.first;
            int x = edge.second.first;
            int y = edge.second.second;
 
            // Take this edge in MST if it does not forms a cycle
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                // cout << x << " -- " << y << " == " << w << endl;
            }
        }
       
        // cout << "Minimum Cost Spanning Tree: " << ans;
        return ans;
    }
};


class Solution {
public:


    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        Graph g(n);

    for(int i =0;i<n;i++)
    {
        auto first = points[i];
        for(int j = i+1;j<n;j++)
        {
            auto sec=  points[j];
            int weight = abs(first[0] - sec[0]) + abs(first[1] - sec[1]);
            g.addEdge(  i, j ,weight );
        }

    }

    return g.kruskals_mst();

    }
};