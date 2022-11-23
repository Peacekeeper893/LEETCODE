#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    /*Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

    Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

    Notice that you can return the vertices in any order.*/

    // We only have to count the number of nodes with zero incoming edges.
    return 0;
}

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int> inEdge(n , 0);
        vector<int> res;

        for(auto x : edges)
        {
            inEdge[x[1]] +=1;
        }

        for(int i =0;i<n;i++)
        {
            if(inEdge[i] == 0)
                res.push_back(i);
        }

        return res;
        
    }
};