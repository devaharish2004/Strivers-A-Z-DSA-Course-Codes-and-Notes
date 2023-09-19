// DFS Code


void dfs(vector<vector<int>>&image, int n, int m, int x, int y, int p, int val)
{
    image[x][y] = p;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    for(int i = 0; i < 4; i++)
    {
        int nrow = x + drow[i];
        int ncol = y + dcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
        {
            if(image[nrow][ncol] == val)
            {
                dfs(image,n,m,nrow,ncol,p,val);
            }
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    // Write your code here.
    int val = image[x][y];
    dfs(image,n,m,x,y,p,val);
    return image;
}


//BFS Code

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int start_color = image[sr][sc];
        //visited array
        int vis[n][m];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == sr && j == sc)
                {
                    vis[i][j] = 1;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        //bfs traversal
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = color;
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            for(int i = 0; i < 4; i++)
            {
                int new_row = row + drow[i];
                int new_col = col + dcol[i];
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && vis[new_row][new_col] != 1 && image[new_row][new_col] == start_color)
                {
                    image[new_row][new_col] = color;
                    vis[new_row][new_col] = 1;
                    q.push({new_row,new_col});
                }
            }
        }

        return image;
        

    }
};