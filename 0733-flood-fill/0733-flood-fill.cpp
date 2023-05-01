class Solution {
private:
    int d[5] = {0,1,0,-1,0};
    
    void bfs(int i, int j, vector<vector<int>> &img, int color)
    {
        int m = img.size();
        int n = img[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        int originalColor = img[i][j];
        img[i][j] = color;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nx = row + d[k];
                int ny = col + d[k+1];
                
                if(nx<0 or ny<0 or nx>=m or ny>=n)
                    continue;
                if(img[nx][ny] == originalColor)
                {
                    q.push({nx,ny});
                    img[nx][ny] = color;
                }
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color)
            return image;
        
        int m = image.size();
        int n = image[0].size();
        
        bfs(sr,sc,image,color);
        return image;
    }
};