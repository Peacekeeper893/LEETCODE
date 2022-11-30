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

    void dfsHelper(int i , vector<bool>& visited ,stack<int>& s )
    {
        visited[i] = true;
        
        for(auto nbr : l[i])
        {
            if(visited[nbr] == false )
                dfsHelper(nbr , visited,s);
        }
        
        s.push(i);
    }

};

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        vector<string> res;
        unordered_map<string , int> idx_map;
        unordered_set<string> sup_set;

        for(auto x : supplies)
        {
            sup_set.insert(x);
        }
        int n = recipes.size();

        int idx = 0;

        for(auto x : recipes)
        {
            idx_map[x] = idx++;
        }

        Graph g(n);

        for(int i =0;i<n;i++)
        {
            auto ing = ingredients[i];
            bool flag = true;

            for(int j =0;j<ing.size();j++){

                if(idx_map.find(ing[j]) != idx_map.end())
                {
                    // found another recipe...add the edge
                    g.addEdge(idx_map[ing[j]] , idx_map[recipes[i]],false);
                }
            }         
        }
        

        stack<int> s;
        vector<bool> visited(n , false);

        for(int i =0;i<n;i++)
        {
            if(visited[i] == false)
                g.dfsHelper(i , visited , s);
        }
        vector<int> topres;

        while(s.empty() == false)
        {
            topres.push_back(s.top());
            s.pop();
        }

        for(auto x : topres)
        {
            int curr_recipe = x;
            auto ing = ingredients[curr_recipe];
            bool flag = true;

            for(int i = 0;i<ing.size();i++)
            {
                if(sup_set.find(ing[i]) == sup_set.end())
                    flag = false;
            }

            if(flag == true)
            {
                res.push_back(recipes[x]);
                sup_set.insert(recipes[x]);
            }
        }




        return res;
        
    }
};