#include<bits/stdc++.h>
using namespace std;


int main()
{
    

    return 0;
}

class Graph{

	int V;
	list<pair<double,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<double,int> >[V];
	}

	void addEdge(int u,int v,double wt,bool undir = true){

		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}


    double dijkstra(int S , int des)
    {
        queue<pair<double , int> >pq;    
        vector<double> dist(V ,0.00 );
        
        dist[S] = 0;
        pq.push({1.00, S});       
        while(pq.empty() == false)
        {
            auto p = pq.front();
            pq.pop();
            
            double w = p.first;
            int node = p.second;
            
            for(auto nbr : l[node])
            {
                int nbr_node = nbr.second;
                double nbr_w = nbr.first;                
                if(dist[nbr_node] < nbr_w * w)
                {
                    dist[nbr_node] =  nbr_w * w;
                    pq.push({dist[nbr_node] , nbr_node});
                }
            }
        }
        return dist[des];
    }

};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        Graph g(n);
        for(int i = 0;i<edges.size();i++)
        {
            g.addEdge(edges[i][0] , edges[i][1] , succProb[i]);
        }
        return g.dijkstra(start , end);
    }
};