int power(int el, int n, int m)
{
  long long ans = 1;
  for(int i = 1; i <= n; i++)
  {
    ans = ans * el;
    if(ans > m) return(2);
  }
  if(ans == m) return(1);
  return(0);
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low = 0;
  int high = m;
  while (low <= high)
  {
    int mid = (low+high)/2;
    long long x = power(mid,n,m);
    if(x == 1)
    {
      return(mid);
    } 
    else if (x == 2) 
    {
      high = mid - 1;
    } 
    else
    {
      low = mid + 1;
    }
  }
  return(-1);
}