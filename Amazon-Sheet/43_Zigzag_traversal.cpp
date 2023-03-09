// using Two Stack 

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        stack<TreeNode*> st1 , st2;
        st1.push(root);
        
        
        if(root == NULL)
            return ans;
        
        while(!st1.empty() || !st2.empty())
        {
            vector<int>v;
            
            while(!st1.empty()){
                auto node = st1.top();
                v.push_back(node->val);
                st1.pop();
                
                if(node->left)
                    st2.push(node->left);
                if(node->right)
                    st2.push(node->right);
                
            }
            
            ans.push_back(v);
            v.clear();
            
              while(!st2.empty()){
                auto node = st2.top();
                v.push_back(node->val);
                st2.pop();
            
                if(node->right)
                    st1.push(node->right);
                if(node->left)
                    st1.push(node->left);
                
            }
            
            if(v.size() > 0)
                ans.push_back(v);
            
        }
        
        return ans;
    }



// Using concept of the odd even level

 vector <int> zigZagTraversal(Node* root)
    {
    	if(root == NULL)
    	    return {};
    	 
    	 queue<Node *>q;
    	 q.push(root);
    	 vector<int>ans;
    	 bool flag = true;
    	 
    	 while(!q.empty())
    	 {
    	     vector<int>curr_level;
    	     int qSize = q.size();
    	     
    	     for(int i = 0 ; i < qSize ;i++)
    	     {
    	         auto node = q.front();
    	         q.pop();
    	         curr_level.push_back(node->data);
    	         
    	         if(node->left)
    	            q.push(node->left);
    	         if(node->right)
    	            q.push(node->right);
    	     }
    	     
    	     if(flag == false)
    	        reverse(curr_level.begin() , curr_level.end());
    	     
    	     for(auto it : curr_level)
    	        ans.push_back(it);
    	   
    	     flag = !flag;     
    	 }
    	 return ans;
    }
