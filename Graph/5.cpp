TOPOLOGICAL SORT USING DFS / BFS

DFS

	
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



BFS

    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V , 0);
	    vector<int>ans;
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        for(auto neig : adj[i])
	        {
	            indegree[neig]++;
	        }
	    }
	    
	    queue<int>q;
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
        
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto neig : adj[node])
            {
                indegree[neig]--;
                if(indegree[neig] == 0)
                    q.push(neig);
            }
        }
	   
	    return ans;        
	}