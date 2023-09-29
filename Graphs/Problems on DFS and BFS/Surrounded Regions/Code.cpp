class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col, int m, int n)
    {
        vis[row][col] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && vis[nrow][ncol] != 1)
            {
                dfs(board,vis,nrow,ncol,m,n);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        //m - rows, n - cols
        int m = board.size();
        int n = board[0].size();
        //create visited array
        vector<vector<int>>vis(m, vector<int>(n,0));

        //find the boundary 0's
        for(int i = 0; i < n; i++) //traverse first row and last row
        {
            if(board[0][i] == 'O' && vis[0][i] != 1) //no need to traverse if the cell is already visited
            {
                dfs(board,vis,0,i,m,n);
            } 

            if(board[m-1][i] == 'O' && vis[m-1][i] != 1)
            {
                dfs(board,vis,m-1,i,m,n);
            }
        }

        for(int i = 0; i < m; i++) //traverse first col and last col
        {
            if(board[i][0] == 'O' && vis[i][0] != 1) //no need to traverse if the cell is already visited
            {
                dfs(board,vis,i,0,m,n);
            } 

            if(board[i][n-1] == 'O' && vis[i][n-1] != 1)
            {
                dfs(board,vis,i,n-1,m,n);
            }
        }

        //change all Os to Xs which are not visited
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
        


    }
};