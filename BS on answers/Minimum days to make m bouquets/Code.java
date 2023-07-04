public class Code {

    public static boolean calc(int[] arr, int mid, int k, int m)
    {
        int count = 0;
        int ans = 0;
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] <= mid)
            {
                count++;
            }
            else
            {
                ans += count/k;
                count = 0;
            }
        }
        ans += count/k; //to not miss out any cases
        if(ans >= m)
        {
            return(true);
        }
        return(false);
    }
    public static int roseGarden(int[] arr, int r, int b) {
        // Write your code here.
        //r = no.of flowers in a bouquet (k)
        //b = no.of bouquets (m)
        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;
        for(int i = 0; i < arr.length; i++)
        {
            mini = Math.min(mini,arr[i]);
            maxi = Math.max(maxi,arr[i]);
        }
        if(b > arr.length/r) return -1;
        int low = mini;
        int high = maxi;
        while(low <= high)
        {
            int mid = low + ((high-low)/2);
            boolean ans = calc(arr,mid,r,b);
            if(ans == false) //not an answer
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return(low);
    }
}