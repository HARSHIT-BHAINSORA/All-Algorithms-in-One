/*
    same as the Merge K sorted Linked list
    1.  merge sort T.C - O(nlogn)
    2. Min Heap and sort only k ele for k arrays -> for to traversal we have to store row and col 
*/  

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans;
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int , int>>> , greater<pair<int ,  pair<int , int >>>>pq;
        
        for(int i = 0 ; i < K ; i++)
            pq.push( { arr[i][0] , {i , 0}});
            
        while(!pq.empty())
        {
            int val = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            pq.pop();
            
            ans.push_back(val);
            
            if(col+1 < K)
                pq.push({arr[row][col+1] , {row , col+1}});
            
        }
        return ans;
    }
};

