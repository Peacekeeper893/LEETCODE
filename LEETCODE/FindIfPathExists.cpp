#include<bits/stdc++.h>
using namespace std;


int main()
{
    

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

        bool bfs(int source , int destination){

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

        if(visited[destination] == true)
            return true;
        else
            return false;
	}
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        Graph g(n);

        for(auto x : edges)
        {
            g.addEdge(x[0] , x[1]);
        }

        return g.bfs(source , destination);
        
    }
};