// BFS

// topological sort : A order is followed after the topolical sort is implemented 
// "order" : The parent neig always in the left side of the child neig.(child incoming edge)



#include<bits/stdc++.h>
using namespace std;

void addEdges(vector<int>adjList[] , int src , int dest)
{
    adjList[src].push_back(dest);
}

void printGraph(vector<int>adjList[] , int V){
    for(int v = 0 ; v < V ; v++)
    {
        cout<<"The node is = " << v<<endl;
        cout<<"The neighbours are = ";  
        for(auto neig : adjList[v])
        {
            cout<< neig << " ";
        }
        cout<<endl;
    }
}

vector<int> topologicalSort(vector<int>adjList[] , int V)
{
    vector<int>ans;
    vector<int>storeIndegree(V , 0);
    queue<int> q;

    // task1 : indegree store for every vertices

    for(int v = 0 ; v < V ; v++)
    {
        for(auto neig : adjList[v])
        {
            storeIndegree[neig]++;
        }
    }

    // task2 : find "zero" indegree push in queue(bex starting always from no incoming edges vertex)

    for(int v = 0 ; v < V ; v++)
    {
        if(storeIndegree[v] == 0)
            q.push(v);
    }

    // implement bfs
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto neig : adjList[node])
        {
            storeIndegree[neig]--;
            if(storeIndegree[neig] == 0)
                q.push(neig);
        }
    }
    
    return ans;
}

int main(){
    int V , E;

    cout<< "Enter the number of Vertices = ";
    cin >> V;

    cout<<"Enter the number of Edges  = ";
    cin >> E;

    int src , dest ;

    vector<int>adjList[V];

    for(int e = 0 ; e < E ; e++)
    {
        cin>>src;
        cin>>dest;

        addEdges(adjList , src , dest);
    }

    printGraph(adjList , V);

    cout << "The topological Sort of given graph is = ";
    vector<int> ans = topologicalSort(adjList , V);

    for(auto it : ans)
        cout <<  it << " ";


    return 0;
}


// DFS

// Topological sort using dfs 
	
	// 1 . components  2. visited array   3. stack -> reverse the sequence
	
	
	void dfs(int node , vector<int> adj[] , vector<bool>&vis , vector<int>&ans)
	{
	    vis[node] = true;
	    
	    for(auto neig : adj[node])
	    {
	        if(!vis[neig])
	        {
	            dfs(neig , adj , vis , ans);
	        }
	    }
	    
	    ans.push_back(node);
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>vis(V,false);
        vector<int>ans;
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i , adj , vis , ans);
	        }
	    }
	    
	    reverse(ans.begin() , ans.end());
	    return ans;
	}