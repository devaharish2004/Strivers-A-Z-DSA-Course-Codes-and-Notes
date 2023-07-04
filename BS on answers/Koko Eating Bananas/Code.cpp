#include <bits/stdc++.h>

int findmax(vector<int>v)
{
    int ans = INT_MIN;
    for(int i = 0; i < v.size(); i++)
    {
        ans = max(ans,v[i]);
    }
    return(ans);
}

int requiredTime(vector<int>v, int mid, int h)
{
    int count = 0;
    for(int i = 0; i < v.size(); i++)
    {
        count += (v[i]/mid);
        if(v[i]%mid!=0) count++;
        if(count > h)
        {
            return(0);
        }
    }
    return(1); //if count <= h
}


int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int maximum = findmax(v);
    int low = 1;
    int high = maximum;
    while(low <= high)
    {
        int mid = (low+high)/2;
        int ans = requiredTime(v, mid, h);
        if(ans == 0) //count > h 
        {
            low = mid+1;
        }
        else //count <= h
        {
            high = mid-1; //this might be an ans, but we need to find the minimum value
        }
    }
    return low;

}