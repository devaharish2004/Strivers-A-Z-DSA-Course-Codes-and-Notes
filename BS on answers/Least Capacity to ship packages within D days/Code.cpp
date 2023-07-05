int sum(vector<int>& weights)
{
    int ans = 0;
    for(int i = 0; i < weights.size(); i++)
    {
        ans += weights[i];
    }    
    return(ans);
}

int maximum(vector<int>& weights)
{
    int m = INT_MIN;
    for(int i = 0; i < weights.size(); i++)
    {
        m = max(m,weights[i]);
    }
    return(m);
}

int calc(vector<int>& weights, int n, int mid)
{
    int days = 1;
    int sum = 0;
    for(int i = 0; i < weights.size(); i++)
    {
        if(sum + weights[i] <= mid)
        {
            sum = sum+weights[i];
        }
        else
        {
            days++;
            sum=weights[i];
        }
    }
    return days; 
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int low = maximum(weights);
    int high = sum(weights);
    int n = weights.size();
    while(low <= high)
    {
        int mid = (low+high)/2;
        int ans = calc(weights, n, mid);
        if(ans <= d) //this is an answer
        {
            high = mid-1; //go on to find the least answer possible
        }
        else
        {
            low = mid+1;
        }
    }
    return(low);  //low will be pointing in the possible answer area
}