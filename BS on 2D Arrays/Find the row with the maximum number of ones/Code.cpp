int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int maxi = 0;
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        int low = 0;
        int high = m-1;
        int index = -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(matrix[i][mid] == 0)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
                index = mid;
            }
        }
        if(index != -1)
        {
            if(maxi < m-index)
            {
                maxi = m-index;
                ans = i;
            }
        }
        
    }
    return(ans);

}