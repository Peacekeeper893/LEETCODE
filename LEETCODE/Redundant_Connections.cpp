#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    /*In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.*/
    return 0;
}
class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}
	void bfs(int source){

		queue<int> q;
		bool *visited = new bool[V]{0};

		q.push(source);
		visited[source] = true;

		while(!q.empty()){
			//Do some work for every node
			int f = q.front();
			cout<<f <<endl;
			q.pop();

			//PUsh the nbrs of current node inside q if they are not already visited
			for(auto nbr : l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
	

};



class Solution {
public:


int find(vector<int>&parent,int x)
{
    if(x==parent[x])
    {
        return x;
    }
    return parent[x]=find(parent,parent[x]);
}

void Union(int u,int v,vector<int>&parent,vector<int>&rank)
{
    u=find(parent,u);
    v=find(parent,v);
    if(rank[u]>rank[v])
    {
        rank[u]=(rank[u]+rank[v]);
        parent[v]=u;
    }
    else
    {
        rank[v]=(rank[v]+rank[u]);
        parent[u]=v;
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        Graph g(n+1);

        vector<int> parent(n+1);
        vector<int> rank(n+1);

        for(int i = 1;i<=n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }

        for(auto x : edges){

            if(find(parent , x[0]) == find(parent , x[1]))
            {
                return x;
            }
            else{

                Union(x[0] , x[1] , parent , rank);
            }

        }

        return {};


        
    }
};