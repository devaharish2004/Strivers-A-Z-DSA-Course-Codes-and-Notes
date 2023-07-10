int calcSum(vector<int>&a, int mid)
{
    int subarrays = 1;
    int sum = 0;
    for(int i = 0; i < a.size(); i++)
    {   
        if(sum + a[i] <= mid)
        {
            sum += a[i];
        }
        else
        {
            subarrays++;
            sum = a[i];
        }
    }
    return(subarrays);
}


int largestSubarraySumMinimized(vector<int> a, int k) {
    // Write Your Code Here
    int low = *max_element(a.begin(),a.end());
    int high = accumulate(a.begin(),a.end(),0);
    while(low <= high)
    {
        int mid = (low+high)/2;
        int countOfSubarrays = calcSum(a,mid);
        if(countOfSubarrays > k)
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