#include<bits/stdc++.h>
using namespace std;


int main()
{
    

    return 0;
}

class Graph{
public:
	int V;
	list<int> *l;


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
    bool checkBipartite(int node,vector<int>&color){
        queue<int> q;
        color[node]=1;
        q.push(node);
        
        while(!q.empty()){
            auto src=q.front();
            q.pop();
            for(auto x:l[src]){

                if(color[x]==-1){    // unvisited nodes
                    if(color[src] == 1)  color[x] = 0;
                    else if(color[src] == 0)  color[x] = 1;
                    q.push(x);
                }
                else if(color[x]==color[src]){   // visited nodes(checks for same color as parent)
                    return false;
                }
            }
        }
        return true;
}
	

};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // int n = graph.size();
        Graph g(n+1);
        for(int i =0 ;i<dislikes.size();i++)
        {
            g.addEdge(dislikes[i][0] , dislikes[i][1]);
        }

        vector<int>color(n+1,-1); // -1 for uncolored , 0/1 for alterante coloring

        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)    // calls BFS for every disconnected component
            {
                if(g.checkBipartite(i,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
    
};