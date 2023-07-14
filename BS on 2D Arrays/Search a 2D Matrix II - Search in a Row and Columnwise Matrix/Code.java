class Code {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int row = 0;
        int col = cols-1;
        while(col >= 0 && row <= rows-1)
        {
            if(matrix[row][col] == target)
            {
                return(true);
            }
            else if(matrix[row][col] > target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        return(false);
    }
}