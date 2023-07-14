class Code_Better_Approach {
    public boolean searchMatrix(int[][] matrix, int target) {
        int low_row = 0;
        int high_row = matrix.length-1;
        while(low_row <= high_row)
        {
            int mid_row = (low_row+high_row)/2;
            if(matrix[mid_row][0] > target)
            {
                high_row = mid_row - 1;
            }
            else
            {
                int low_col = 0;
                int high_col = matrix[mid_row].length-1;
                while(low_col <= high_col)
                {
                    int mid_col = (low_col + high_col)/2;
                    if(matrix[mid_row][mid_col] == target)
                    {
                        return(true);
                    }
                    else if(matrix[mid_row][mid_col] < target)
                    {
                        low_col = mid_col + 1;
                    }
                    else
                    {
                        high_col = mid_col - 1;
                    }
                }
                low_row = mid_row + 1;
            }
        }
        return(false);
    }
}