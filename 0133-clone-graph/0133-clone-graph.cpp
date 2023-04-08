/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
  }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        
        unordered_map<int,Node*> m;
        vector<bool> vis(100,false);
        
        dfs1(node,vis,m);
        Node* clone = m[node->val];
        
        vector<bool> v(100,false);
        dfs2(node,clone,v,m);
        
        // dfs(clone,vis);
        
        return clone;
    }
    
//     void dfs(Node* node, vector<bool> &vis)
//     {
//         vis[node->val] = true;
//         cout<<node->val<<" ";
//         for(auto x:node->neighbors)
//             cout<<x->val<<" ";
        
//         for(auto x:node->neighbors)
//         {
//             if(!vis[x->val])
//             {
//                 dfs(x,vis);
//             }
//         }
//     }
    
    void dfs1(Node* node, vector<bool> &vis, unordered_map<int,Node*> &m)
    {
        Node* nw = new Node(node->val);
        m[node->val] = nw;
        vis[node->val] = true;
        
        for(auto x:node->neighbors)
        {
            if(!vis[x->val])
            {
                dfs1(x,vis,m);
            }
        }
    }
    
    void dfs2(Node* node, Node* clone, vector<bool> &vis, unordered_map<int,Node*> &m)
    {
        vis[node->val] = true;
        // cout<<"a"<<" ";
        
        for(auto x:node->neighbors)
        {
            clone->neighbors.push_back(m[x->val]);
            // cout<<clone->neighbors.back();
        }
        
        for(int i=0;i<node->neighbors.size();i++)
        {
            if(!vis[node->neighbors[i]->val])
            {
                // cout<<clone->neighbors[i]<<" ";
                dfs2(node->neighbors[i],clone->neighbors[i],vis,m);
            }
        }
    }
};