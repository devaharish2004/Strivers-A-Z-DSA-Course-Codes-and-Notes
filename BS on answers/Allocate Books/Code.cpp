int countOfStudents(vector<int>&arr, int mid, int n)
{
    int students = 1;
    int pages = 0;
    for(int i = 0; i < n; i++)
    {
        if(pages+arr[i] <= mid)
        {
            pages += arr[i];
        }
        else
        {
            students++;
            pages = arr[i];
        }
    }
    return(students);
}


int findPages(vector<int>& arr, int n, int m) 
{
    // Write your code here.n
    if(m > n) return(-1);
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high)
    {
        int mid = (low+high)/2;
        int count = countOfStudents(arr,mid,n);
        if(count > m)
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