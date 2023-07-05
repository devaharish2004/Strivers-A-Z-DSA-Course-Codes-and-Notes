public class Code 
{
    public static int findmax(int[] arr)
    {
        int m = Integer.MIN_VALUE;
        for(int i = 0; i < arr.length; i++)
        {
            m = Math.max(m,arr[i]);
        }
        return(m);
    }

    public static boolean calc(int[] arr, int limit, int mid)
    {
        int sum = 0;
        for(int i = 0; i < arr.length; i++)
        {
            sum += arr[i]/mid;
            if(arr[i]%mid != 0) sum++;
            if(sum > limit)
            {
                return(false);
            }
        }
        return(true);
    }
    public static int smallestDivisor(int arr[], int limit) 
    {
        // Write your coder here
        int low = 1;
        int high = findmax(arr);
        while(low <= high)
        {
            int mid = (low+high)/2;
            boolean ans = calc(arr,limit,mid);
            if(ans == true)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
}