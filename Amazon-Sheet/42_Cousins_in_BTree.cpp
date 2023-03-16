
/*
    Problem Statement - Cousins --> 1 . having same level 
                                    2.  having different parent 

    Intiution - need level and parent of x and y --> track the level and parent and then check                                 
*/


 unordered_map<int , pair<int , int>>mp;

    void dfs(TreeNode* root , int level , int parent)
    {
        if(root == NULL)
            return ;

        mp[root->val] = {level , parent};

        dfs(root->left , level+1 , root->val);
        dfs(root->right , level+1 , root->val);    
    }


    bool isCousins(TreeNode* root, int x, int y) {
        
        dfs(root , 0 , -1);

        if((mp[x].first == mp[y].first) && (mp[x].second != mp[y].second))
            return true;
        return false;    
    }