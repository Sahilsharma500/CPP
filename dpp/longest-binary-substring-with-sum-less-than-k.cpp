#include <iostream>
#include <string>
using namespace std;

/*
────────────────────────────────────────────────────────────────────────────
🔷 Longest Binary Subsequence Less Than or Equal to K
────────────────────────────────────────────────────────────────────────────

📌 Problem:
Given a binary string `s` and an integer `k`, return the length of the longest subsequence 
(subsequence means you can skip characters) of `s` such that the value of that subsequence 
in binary is less than or equal to `k`.

🧠 Intuition:
We're allowed to skip bits, so we need to **maximize the number of selected characters**
such that their binary value is <= k.

Key Observations:
1. **'0's cost nothing** (adding '0' doesn’t increase binary value much), so we always include them.
2. For **'1's**, we only include them if the resulting binary value is still ≤ k.
3. We traverse from **right to left** (least significant bit to most) because adding bits from the right 
   has the least impact on the number’s value.

Why NOT DP?
- DP is overkill here because:
  - The input size is small (≤ 10⁵), but `k` can be very large (up to 10⁹).
  - A DP solution considering all subsequences would be **exponential** or **require memoization**
    over complex state (index + current number built so far).
  - Greedy from the right is much faster and fits the problem constraints tightly.

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)

*/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int len = 0;          // Count of characters in result
        long long power = 1;  // Binary place value, starting from LSB (1)

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // Always include '0' as it doesn't increase value significantly
                len++;
            } else if (power <= k) {
                // Include '1' only if its value contribution doesn't exceed k
                len++;
                k -= power;
            }

            // Only double power if next bit doesn't immediately overflow
            if (power <= k)
                power <<= 1;
        }

        return len;
    }
};

/* Optional main for testing
int main() {
    Solution sol;
    string s = "1001010";
    int k = 5;
    cout << "Longest subsequence length ≤ k: " << sol.longestSubsequence(s, k) << endl;
    return 0;
}
*/
