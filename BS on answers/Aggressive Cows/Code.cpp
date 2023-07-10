int place(vector<int>& stalls, int n, int mid, int k)
{
    int countOfCows = 1;
    int last = stalls[0];
    for(int i = 1; i < n; i++)
    {
        if(stalls[i]-last >= mid) //if the minimum distance is satisfied
        {
            countOfCows++;
            last = stalls[i];
        }
        if(countOfCows >= k) return(true);
    }
    return(false);
}



int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n-1];
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(place(stalls,n,mid,k) == true)
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