#include <bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    //initialize the queue
    //queue member will be {{row,col},t};
    queue<pair<pair<int,int>,int>> q;
    //initialize a visited array
    int visited[n][m];

    //first push all the rotten oranges in the queue
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({{i,j},0});
                visited[i][j] = 2;
            }
            else //if the cell is empty or the orange is fresh
            {
                visited[i][j] = 0;
            }
        }
    }

    //each drow[i] and drow[j] defines the top, right, bottom and left elements of the current element respectively
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    //to find the maximum time
    int time_max = 0;
    //bfs approach
    while (!q.empty()) {

        int r = q.front().first.first; //row
        int c = q.front().first.second; //col
        int t = q.front().second; //time
        time_max = max(t,time_max);

        q.pop(); //remove the pair

        for(int i = 0; i < 4; i++) //for each of the adjacent cells
        {
            int new_row = r + drow[i];
            int new_col = c + dcol[i];
            //checking if the row value and column values are valid
            //also checking that if the cell is not rotten, if it is rotten no need to go to that cell
            //also checking if the grid has a fresh orange in that cell
            //if it is empty no need to go to the cell
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && visited[new_row][new_col] != 2 && grid[new_row][new_col] == 1)
            {
                q.push({{new_row,new_col},t+1}); //since it will account to the next second
                visited[new_row][new_col] = 2;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] != 2 && grid[i][j] == 1) //if the cell is not visited and the cell in the grid is fresh
            {
                return -1;
            }
        }
    }

    return time_max;
}