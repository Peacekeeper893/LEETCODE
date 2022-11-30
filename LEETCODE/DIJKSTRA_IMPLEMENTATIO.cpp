//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        queue<pair<int , int>  >pq;
        
        vector<int> dist(V+1 ,INT_MAX );
        
        dist[S] = 0;
        pq.push({0 , S});
        
        
        while(pq.empty() == false)
        {
            auto p = pq.front();
            pq.pop();
            
            int w = p.first;
            int node = p.second;
            
            for(auto nbr : adj[node])
            {
                int nbr_node = nbr[0];
                int nbr_w = nbr[1];
                
                if(dist[nbr_node] > nbr_w + w)
                {
                    dist[nbr_node] = min(dist[nbr_node] , nbr_w + w);
                    pq.push({dist[nbr_node] , nbr_node});
                }
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends