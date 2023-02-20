// 0 / 1 bfs -> (finding shortest path in O(E+V)) - > code in 1 based indexing 
// only apply where 0 or 1 weg is given for every edges of graph

#include<bits/stdc++.h>
using namespace std;


void printGraph(vector<pair<int,int>>graph[] , int V){
    for(int v = 1 ; v <= V ; v++)
    {
        cout<<"The node is = " << v<<endl;
        cout<<"The neighbours are = ";  
        for(auto neig : graph[v])
        {
            cout<< neig.first << " " << neig.second << "  ";
        }
        cout<<endl;
    }
}


void bfsAlgo(vector<pair<int , int>>graph[] , vector<int>&dis , int src , vector<bool>&vis)
{
    deque<pair<int , int>>dq;
    dq.push_back({src , 0});
    dis[src] = 0;

    while(!dq.empty())
    {
        int curr_node = dq.front().first;
        int curr_dis = dq.front().second;

        vis[curr_node] = true;
        dq.pop_front();


        for(auto it : graph[curr_node])
        {
            int next_node = it.first;
            int next_dis = it.second;

            if(vis[next_node] == true)
                continue;

            if(dis[next_node] > dis[curr_node] + next_dis)
            {
                dis[next_node] = dis[curr_node] + next_dis;

                // if  y dis is zero we know dis we not increased add at front 
                if(next_dis == 0)
                    dq.push_front({next_node , dis[next_dis]});
                // if y+1 dis then add at last
                else if(next_dis == 1)
                    dq.push_back({next_node , dis[next_dis]});    
            }
        }
    }
}


int main(){
    
    int V , E;
    
    cout << "Enter the number of Vertices = ";
    cin >> V;

    cout<<"Enter the number of Edges = ";
    cin >> E;

    int src , dest;

    vector<pair<int , int >>graph[V+1];

    for(int e = 0 ; e < E ; e++)
    {
        cin >> src >> dest;
        graph[src].push_back({dest , 0});
        graph[dest].push_back({src, 1});
    }

    printGraph(graph , V);

    int source;
    cout<<"Enter the source = " ;
    cin>>source;

    vector<int>dis(V+1,INT_MAX);
    vector<bool>vis(V+1,false);

    bfsAlgo(graph , dis , source , vis);

    cout << "The shortest distance from "<< source << " is = ";

    for(int i = 1 ; i <= V ; i++)
        cout<<dis[i]<<" ";
    return 0;

}