/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return f(grid,0,n-1,0,n-1);
    }
    
    Node* f(vector<vector<int>> &g, int r1, int r2, int c1, int c2)
    {
        if(r1<0 or r2>g.size()-1 or c1<0 or c2>g.size()-1)
            return NULL;
        if(r1 > r2 or c1 > c2)
            return NULL;
        
        int o = 0, z = 0;
        bool notSame = false;
        
        for(int i=r1;i<=r2;i++)
        {
            for(int j=c1;j<=c2;j++)
            {
                if(g[i][j] == 0) z++;
                else o++;
                if(z and o) 
                {
                    notSame = true;
                    break;
                }
            }
        }
        
        Node* temp = new Node();
        
        if(!notSame)
        {
            temp->isLeaf = true;
            temp->val = (z)?false:true;
        }
        else {
            temp->val = true;
            int rd = (r2-r1)/2;
            int cd = (c2-c1)/2;
            
            temp->topLeft = f(g,r1,r1+rd,c1,c1+cd);
            temp->topRight = f(g,r1,r1+rd,c1+cd+1,c2);
            temp->bottomLeft = f(g,r1+rd+1,r2,c1,c1+cd);
            temp->bottomRight = f(g,r1+rd+1,r2,c1+cd+1,c2);
        }
        
        return temp;
    }
};