bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();  //no.of rows
    int n = mat[0].size();  //no.of cols 
    int low = 0;
    int high = m*n -1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        int row_index = mid/n;
        int col_index = mid%n;
        if(mat[row_index][col_index] == target)
        {
            return(true);
        }
        else if(mat[row_index][col_index] > target)
        {
            high = mid-1;
        }
        else
        {
           low = mid+1;
        }

    }
    return(false);
}