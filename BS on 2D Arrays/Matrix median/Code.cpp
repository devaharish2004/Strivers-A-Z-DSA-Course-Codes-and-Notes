int minimum(vector<vector<int>>&matrix, int m, int n)
{
    int ans = INT_MAX;
    for(int i = 0; i < m; i++)
    {
        ans = min(ans,matrix[i][0]);
    }
    return ans;
}

int maximum(vector<vector<int>>&matrix, int m, int n)
{
    int ans = INT_MIN;
    for(int i = 0; i < m; i++)
    {
        ans = max(ans,matrix[i][n-1]);
    }
    return ans;
}

int countOfMin(vector<int>row,int n, int val)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(row[mid] <= val)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return low;

}


int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    //finding the max and min elements (range of search space)
    int low = minimum(matrix,m,n);
    int high = maximum(matrix,m,n);

    //binary search
    while(low <= high)
    {
        int mid = (low+high)/2;
        //traverse through all the rows and find out how many numbers are less than equal to mid
        int count = 0;
        for(int i = 0; i < m; i++)
        {
            count += countOfMin(matrix[i],n,mid);
        }
        if(count > (m*n)/2)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        //this is not denoting the index, it denotes the element.
    }
    return low;


}