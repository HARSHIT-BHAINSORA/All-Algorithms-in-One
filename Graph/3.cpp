// Bridge in the graph

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>graph[] , int &timer , vector<int>&low , vector<int>&disc , vector<bool>&vis , int parent , int node)
{
    vis[node] = true;
    low[node] = disc[node] = ++timer;

    for(auto neig : graph[node])
    {
        if(neig == parent)
            continue;

        if(!vis[neig]){
            dfs(graph , timer, low , disc , vis , node , neig);

            low[node] = min(low[node] , low[neig]);

            // parent child relation 
            if(low[neig] > disc[node])
                cout<<node << " - " << neig <<endl;
        }
        else if(neig != parent)
        {
            // it mean that there is the other path or a backedge
            low[node] = min(low[node] , disc[neig]);
        }
                
    }

}



int main()
{
    int V, E;
    int timer = 0;
    vector<int> low(V, 0); // early possible time 
    vector<int> disc(V, 0); // discovery time
    vector<bool> vis(V, false);
    int parent = -1;

    cout << "Enter the number of Vertex= ";
    cin >> V;

    cout << "Enter the edges = ";
    cin >> E;
    vector<int> graph[V];

    int src, dest;
    for (int i = 0; i < E; i++)
    {
        cin >> src >> dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
            dfs(graph, timer, low, disc, vis, parent, i);
    }
}