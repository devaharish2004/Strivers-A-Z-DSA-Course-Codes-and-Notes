#include <vector>
using namespace std;

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    //the question can be analyzed as finding the longest subarray with atmost k zeros
    //sliding window + two pointer O(2N) better approach
    int maxlen = 0;
    int left = 0;
    int right = 0;
    int zeros = 0;
    while(right < n) {
        if(arr[right] == 0) {
            zeros++;
        }
        //trim down the left until the condition zeros <= k is met
        while(zeros > k) {
            if(arr[left] == 0) zeros--;
            left++;
        }
        int len = right-left+1;
        maxlen = max(maxlen, len);
        right++;
    }

    return maxlen;

}
