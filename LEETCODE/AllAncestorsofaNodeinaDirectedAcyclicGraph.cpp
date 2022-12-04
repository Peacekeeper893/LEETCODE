#include<bits/stdc++.h>
using namespace std;


int main()
{
    

    return 0;
}

class Graph
{

    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void dfsHelper(int node, vector<bool> &visited ,stack<int> &s)
    {
        visited[node] = true;
        // make a dfs call on all its unvisited neighbours
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited,s);
            }
        }

        s.push(node);
        return;
    }


};


class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

    Graph g(n);
    vector<vector<int>> res(n);
    unordered_map<int , vector<int> > inedge;
    for(auto x : edges){
        g.addEdge(x[0] , x[1] , false);
        inedge[x[1]].push_back(x[0]);
    }

/*
    for(auto x : inedge)
    {
        cout<<x.first<<":  ";

        for(auto y : x.second)
            cout<<y<<" ";

        cout<<endl;
    }

    WORKING FINE....

*/
    vector<bool> visited(n, false);
    stack<int> s;
    vector<int> topo;

    for (int i = 0; i < n;i++){
        if(!visited[i])
        {
            g.dfsHelper(i, visited , s);
        }
    }
    while(s.empty() == false){
        topo.push_back(s.top());
        s.pop();
    }
    // topological sorting is obtained in vector topo...

    for(int i = 0;i<topo.size() ; i++)
    {
        int curr_node = topo[i];
        set<int> curr;  // PROVIDES SORTED ANSWER WITHOUT REPETITIONS

        if(inedge.find(curr_node) == inedge.end())
        {
            continue;   // NO INCOMING EDGES
        }
        else
        {
            vector<int>edgeList = inedge[curr_node];
            vector<int> ans;

            for(auto x : edgeList)  // TRAVERSE ALL THE INCOMING EDGES
            {
                curr.insert(x);     // INSERT THE VERTEX AND ALL ITS INCOMING EDGES(COMPUTED PREVIOUSLY)
                for(auto y : res[x])
                {
                    curr.insert(y);
                }
            }
            for(auto z : curr)
            {
                ans.push_back(z);
            }
            res[curr_node] = ans;
        }
    }

    return res;
        
    }
};