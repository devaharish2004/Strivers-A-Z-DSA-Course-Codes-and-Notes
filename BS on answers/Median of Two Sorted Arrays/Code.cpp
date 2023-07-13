#include <bits/stdc++.h>

double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
    //TC : O(log(min(a,b)))
    if(a.size() > b.size()) return(median(b,a)); //to reduce the search space to min (a,b) - without this also the code runs but the search space is larger.
	int n1 = a.size();
	int n2 = b.size();
	int low = 0;
	int high = n1;
	while(low <= high)
	{
		int cut1 = (low + high)/2;
		int cut2 = (n1+n2+1)/2 - cut1;
		
		int left1 = cut1 == 0 ? INT_MIN : a[cut1-1];
		int left2 = cut2 == 0 ? INT_MIN : b[cut2-1];
		int right1 = cut1 == n1 ? INT_MAX : a[cut1];
		int right2 = cut2 == n2 ? INT_MAX : b[cut2];

		if(left1 <= right2 && left2 <= right1)
		{
			if((n1+n2)%2==0)
			return (max(left1,left2)+min(right1,right2))/2.0;
			else return max(left1,left2);
		}
		else if(left1 > right2)
		{
			high = cut1 - 1;
		}
		else
		{
			low = cut1 + 1;
		}
	}
	return 0.0;
}
