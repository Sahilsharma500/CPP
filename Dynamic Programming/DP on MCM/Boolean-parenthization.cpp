#include <unordered_map>
#include <string>
using namespace std;

/*
───────────────────────────────────────────────────────────────
🔷 Boolean Parenthesization (Count the number of ways to evaluate to True)
───────────────────────────────────────────────────────────────

📌 Problem:
Given a boolean expression consisting of the characters `'T'`, `'F'`, `'&'`, `'|'`, `'^'`, 
you must count the **number of ways** to parenthesize the expression such that it evaluates to **True**.

🎯 Goal:
Return the number of ways to evaluate the expression as `True`.

🧠 Intuition:
This is a classic recursive problem with overlapping subproblems:
- We divide the string at every operator (`&`, `|`, `^`)
- For each division, we calculate:
   - Ways to make left True/False
   - Ways to make right True/False
- Use operator rules to combine those ways based on what the final result (`True` or `False`) should be.

💡 Optimization:
We use a **string-based memoization key** of the format `"i_j_T/F"` to cache results and avoid recomputation.

🧮 Time Complexity: O(n³)
🧮 Space Complexity: O(n² * 2) → due to memoization

*/

class Solution {
public:
    int countWays(string &s) {
        memo.clear();  // Clear memoization map before each run
        return count(s, 0, s.size() - 1, true);
    }

private:
    unordered_map<string, int> memo;

    // Recursive function to count ways to evaluate s[i..j] to isTrue
    int count(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;

        // Build key for memo
        string key = to_string(i) + "_" + to_string(j) + "_" + (isTrue ? "T" : "F");
        if (memo.find(key) != memo.end())
            return memo[key];

        // Base case: only one character
        if (i == j) {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        int ways = 0;

        // Try placing parentheses at each operator
        for (int k = i + 1; k <= j - 1; k += 2) {
            char op = s[k];

            // Count left and right side combinations
            int lt = count(s, i, k - 1, true);
            int lf = count(s, i, k - 1, false);
            int rt = count(s, k + 1, j, true);
            int rf = count(s, k + 1, j, false);

            // Use the operator to combine results based on isTrue
            if (op == '&') {
                if (isTrue)
                    ways += lt * rt;
                else
                    ways += lt * rf + lf * rt + lf * rf;
            } else if (op == '|') {
                if (isTrue)
                    ways += lt * rt + lt * rf + lf * rt;
                else
                    ways += lf * rf;
            } else if (op == '^') {
                if (isTrue)
                    ways += lt * rf + lf * rt;
                else
                    ways += lt * rt + lf * rf;
            }
        }

        // Memoize and return
        memo[key] = ways;
        return ways;
    }
};

/* Optional main for testing
int main() {
    Solution sol;
    string s = "T|F&T^T";
    cout << "Number of ways to evaluate to True: " << sol.countWays(s) << endl;
    return 0;
}
*/
