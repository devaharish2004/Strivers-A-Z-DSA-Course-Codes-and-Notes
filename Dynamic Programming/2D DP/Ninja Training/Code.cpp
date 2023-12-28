
#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum points for the ninja training
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
  // If the result for this day and last activity is already calculated, return it
  if (dp[day][last] != -1) return dp[day][last];

  // Base case: When we reach the first day (day == 0)
  if (day == 0) {
    int maxi = 0;
    // Calculate the maximum points for the first day by choosing an activity
    // different from the last one
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    // Store the result in dp array and return it
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  // Iterate through the activities for the current day
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      // Calculate the points for the current activity and add it to the
      // maximum points obtained so far (recursively calculated)
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }

  // Store the result in dp array and return it
  return dp[day][last] = maxi;
}

// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points) {
  // Create a memoization table (dp) to store intermediate results
  vector<vector<int>> dp(n, vector<int>(4, -1));
  // Start the recursive calculation from the last day with no previous activity
  return f(n - 1, 3, points, dp);
}

int main() {
  // Define the points matrix
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};

  int n = points.size();  // Get the number of days
  // Call the ninjaTraining function to find the maximum points and print the result
  cout << ninjaTraining(n, points);
}
