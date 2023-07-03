int floorSqrt(int n)
{
    // Write your code here.
    int low = 1;
    int high = n;
    while(low <= high)
    {
        long long int mid = (low+high)/2;
        long long int val = mid*mid;
        if(val <= n)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return(high);
}
