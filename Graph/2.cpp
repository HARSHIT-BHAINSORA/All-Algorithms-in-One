// Multisource bfs question 

#include <bits/stdc++.h>
using namespace std;


int dx[8] = {-1 , -1 , -1 , 0 , 1, 1 , 1 , 0 };
int dy[8] = {-1 , 0 , 1 , 1, 1, 0 , -1 , -1 };

bool isValid(int row , int col , int n , int m)
{
    if(row >= 0 && row < n && col >= 0 && col < m)
        return true;
    return false;
}

void bfs(vector<vector<int>>&grid , int n , int m , int mx_ele)
{
    
    queue<pair<int , pair<int , int>>>q;
    vector<vector<bool>>vis(n , vector<bool>(m , false));
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(grid[i][j] == mx_ele)
            {
                q.push({0 , { i , j}});
                vis[i][j] = true;
            }
        }
    }
    

    int hours = INT_MIN;
    
    while(!q.empty())
    {
            int curr_hours = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            hours = max(hours , curr_hours);
            
            for(int i = 0 ; i < 8 ; i++)
            {
                int x = row + dx[i];
                int y = col + dy[i];
                
                
                if(isValid(x , y , n , m) && vis[x][y] == false)
                {
                    q.push({curr_hours+1,{x , y}});
                    vis[x][y] = true;
                }
            }
    }
    cout<< hours <<endl;
}




int main() {
	
	int t_case;
	
	cin >> t_case;
	
	while(t_case--)
	{
	    int n , m;
	    
	    cin >> n >> m;
	    
	    vector<vector<int>>grid(n , vector<int>(m));
	    int mx_ele = INT_MIN;
	 
	    for(int i = 0 ; i < n ; i++)
	    {
	        for(int j = 0 ; j < m ; j++)
	        {
	            int temp;
	            cin>>temp;
	            grid[i][j] = temp;
	            
	            mx_ele = max(mx_ele , grid[i][j]);
	        }
	    }
	    
	    bfs(grid , n , m , mx_ele);
	}
	return 0;
}
