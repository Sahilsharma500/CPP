/*
    ✅ Problem: Array Manipulation (HackerRank)

    🔍 Intuition:
    Naively updating ranges in the array leads to TLE for large inputs.
    So, we use a **Prefix Sum Optimization** technique:
    - For a query (a, b, k), instead of adding `k` to each index from a to b,
      we:
        - Add `k` at index `a`
        - Subtract `k` at index `b+1`
    - Then do a single prefix sum pass to compute the final values

    This reduces complexity from O(m*n) to O(n + m).

    🧠 Approach:
    - Create a difference array of size n+2 initialized to 0
    - For each query (a, b, k):
        - diff[a-1] += k
        - diff[b] -= k
    - Take prefix sum of this array and track the maximum value

    🛠️ Time Complexity:
    - O(m + n), where m is number of queries and n is the array size
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <functional>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Core logic
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> diff(n + 2, 0);  // using n+2 to avoid boundary issues

    for (const auto& q : queries) {
        int a = q[0];
        int b = q[1];
        long k = q[2];

        diff[a] += k;
        diff[b + 1] -= k;
    }

    long maxVal = 0, curr = 0;
    for (int i = 1; i <= n; ++i) {
        curr += diff[i];
        maxVal = max(maxVal, curr);
    }

    return maxVal;
}

// HackerRank I/O wrapper
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);
    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
    int n = stoi(first_multiple_input[0]);
    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        string query_line;
        getline(cin, query_line);
        vector<string> tokens = split(rtrim(query_line));
        for (int j = 0; j < 3; j++) {
            queries[i][j] = stoi(tokens[j]);
        }
    }

    long result = arrayManipulation(n, queries);
    fout << result << "\n";
    fout.close();

    return 0;
}

// Utility functions for HackerRank input
string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0, end;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}
