//Dijkstra's algorithm approach

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) 
    {
        // code here
        //can be solved using bfs as well as Dijkstra's algorithm
        //here using Dijkstra's 
        int n = grid.size();
        int m = grid[0].size();
        
        //queue is enough as the distance between each adjacent cell is constant
        // {dist, {x,y}}
        queue<pair<int, pair<int,int>> > q;
    
        //dist array
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        
        //initial config
        dist[source.first][source.second] = 0;
        q.push({0, source});
        
        //edge case - what if the source is the destination
        if(source.first == destination.first && source.second == destination.second)
        {
            return 0;
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            auto it = q.front();
            int distance = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            
            for(int i= 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dist[nrow][ncol] > distance + 1)
                {
                    dist[nrow][ncol] = distance + 1;
                    
                    //condition for finding if the destination is reached
                    if(nrow == destination.first && ncol == destination.second)
                    {
                        return distance+1;
                    }
                    
                    q.push({distance + 1, {nrow,ncol}});
                }
            }
        }
        
        return -1;
    
    
                         
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends


// -----------------------------------------------------------------------------------

//BFS approach

#include <bits/stdc++.h>

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    // Write your code here
    //m - no of rows && n - no.of cols
    int m = matrix.size();
    int n = matrix[0].size();
    //visited array
    vector<vector<int>> vis(m, vector<int>(n,0));

    //priority queue - min heap - {distance, coordinatepair}
    priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int> >>, greater< pair<int, pair<int,int> > > >pq;

    //push the src cell
    if(matrix[src.first][src.second] == 1)
    {
        pq.push({0,src});
        vis[src.first][src.second] = 1;
    }

    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    int ans = -1;

    while(!pq.empty())
    {
        int distance = pq.top().first;
        pair<int,int> cell = pq.top().second;
        int row = cell.first;
        int col = cell.second;

        if(row == dest.first && col == dest.second)
        {
            ans = distance;
            break;
        }

        pq.pop();

        for(int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] != 1 && matrix[nrow][ncol] == 1)
            {
                pq.push({distance+1, make_pair(nrow,ncol)});
                vis[nrow][ncol] = 1;
            }
        }

    }

    return ans;


}

