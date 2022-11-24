//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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

    void dfsHelper(int node,vector<bool> &visited){
    visited[node] = true;
    //make a dfs call on all its unvisited neighbours
    for(int nbr : l[node]){
        if(!visited[nbr]){
            dfsHelper(nbr,visited);
        }
    }
    return;

}

	void printAdjList(){
		//Iterate over all the rows
		for(int i=0;i<V;i++){
			cout<<i<<"-->";
			//every element of ith linked list
			for(auto node:l[i]){
				cout << node <<",";
			}
			cout <<endl;

		}


	}

};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        int n = adj.size();
        int m = adj[0].size();

        Graph g(n);

        for(int i =0;i<n;i++)
        {
            for(int j= 0 ;j<m;j++)
            {
                if(i<j and adj[i][j] == 1)
                {
                    g.addEdge(i , j);
                }
            }
        }

        vector<bool> visited(n , false);
        int count = 0;

        for(int i =0;i<n;i++)
        {
            if(visited[i] == false)
                {
                    g.dfsHelper(i , visited);
                    count++;
                }
        }

        return count;
    }
};

/*{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
*/