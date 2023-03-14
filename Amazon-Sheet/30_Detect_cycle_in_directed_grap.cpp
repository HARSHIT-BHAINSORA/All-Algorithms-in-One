class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        
        vector<int>indegree(V);
        int no_nodes = 0;
        queue<int>q;
        
        for(int i = 0 ; i < V ; i++)
        {
            for(auto neig : adj[i])
            {
                indegree[neig]++;
            }
        }
        
        for(int i = 0 ; i < V ; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            no_nodes++;
            
            for(auto neig : adj[node])
            {
                indegree[neig]--;
                if(indegree[neig] == 0)
                    q.push(neig);                    
            }
        }
        
        return no_nodes < V ? 1 : 0;
    }
};