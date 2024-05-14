//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Brute force - generate all subarrays - O(N*N), SC : ~ O(1) as we store only 3 elements O(3) in the map/set which takes logN ~ log3 ~ O(1) time.
//Better approach - sliding window, left + right pointers, using another while loop for left
//TC : O(2N), SC : O(3) ~ O(1)
//Optimal Solution : TC : O(N), SC : O(3) ~ O(1)
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        map<int,int> mp;
        while(right < N) {
            mp[fruits[right]]++;
            //if the subarray is not possible, then try to reduce it first to a possible subarray and check
            if(mp.size() > 2) {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            if(mp.size() <= 2) {
                //valid subarray, try to update the maxLen
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends