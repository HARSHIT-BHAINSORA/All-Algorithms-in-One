 
 // think about the backtracking and store ans on its if we find the node where left and right have certain value it 
 // mean that Lca
 
 
 Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL)
            return NULL;
        
        if(root->data == n1 || root->data == n2)
            return root;
        
        Node * left = lca(root->left , n1 , n2);
        Node *right = lca(root->right , n1 , n2);
        
        if(left && right)
            return root;
            
            
        return left == NULL ? right : left;    
    }