#include <bits/stdc++.h>

void dfs(int row, int col, int row_base, int col_base, int n, int m, vector<pair<int,int>> &temp, vector<vector<int>> &vis, int** arr)
{
    //here no diagonal elements are to be taken
    vis[row][col] = 1;
    //this line makes the difference 
    //row_base and col_base indicates the starting position of a new island
    //if we subtract row_base and col_base from row and col, we could get the same cooordinates
    //if the pattern is same, then when we insert it in the set it will not count as distinc
    temp.push_back({row-row_base, col-col_base});
    
    int drow[] = {-1,0,1,0};
    int dcol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && arr[nrow][ncol] == 1)
        {
            dfs(nrow,ncol,row_base,col_base,n,m,temp,vis,arr);
        }
    }
}


int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    //using dfs approach
    //create visited array
    vector<vector<int>> vis(n,vector<int>(m,0));

    //set of vector that contains pairs
    set<vector<pair<int,int>>> ans;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(vis[i][j] == 0 && arr[i][j] == 1)
            {
                //create a temporary vector for storing all the locations of that land
                vector<pair<int,int>>temp;
                dfs(i,j,i,j,n,m,temp,vis,arr);
                ans.insert(temp);
            }
        }
    }

    return ans.size(); // no.of distinct lands
    
}