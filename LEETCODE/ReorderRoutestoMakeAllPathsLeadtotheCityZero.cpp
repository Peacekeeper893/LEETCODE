#include<bits/stdc++.h>
using namespace std;


int main()
{
    /*There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.*/

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

    int findcnt(unordered_map<int , vector<int> > &inedge)
    {

        vector<bool> visitable(V , false);
        int cnt = 0;

        visitable[0] = true; // can visit the root;

        queue<int> q;
        q.push(0);

        while(q.empty() == false)
        {
            auto temp = q.front();
            q.pop();

            // cout<<"here";

            for(auto nbr : l[temp])
            {
                if(visitable[nbr] == false)
                {
                    visitable[nbr] = true;
                    q.push(nbr);

                    // cout<<nbr<<" ";

                    if( find(inedge[temp].begin() , inedge[temp].end() , nbr) == inedge[temp].end())
                    {
                        cnt++;
                        inedge[temp].push_back(nbr);
                    }

                }
            }
        }

        return cnt;
    }

};
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        Graph g(n);


        for(auto x : connections)
        {
            g.addEdge(x[0] , x[1]);
        }

        unordered_map<int , vector<int> > inedge;

        for(int i =0;i<connections.size();i++)
        {
            inedge[connections[i][1]].push_back(connections[i][0]);
        }// stores the incoming edges



        return g.findcnt(inedge);



        
    }
};