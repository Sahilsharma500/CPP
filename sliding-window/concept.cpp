// Description: Reference code for Sliding Window technique in C++
// Includes explanation and examples of both Shrinkable and Non-Shrinkable window templates

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
========================================
📘 Sliding Window Technique - C++ Cheatsheet
========================================

🔹 What is Sliding Window?
A technique used to maintain a window (subarray or substring) that satisfies some condition efficiently.
Typically uses two pointers: `start` and `end` to represent the window.

===========================
🔸 Template 1: Shrinkable Window
===========================
Use when the window can become invalid and needs to be shrunk until it becomes valid again.
*/

int shrinkable_example(vector<int>& nums, int k) {
    int start = 0, end = 0, sum = 0, maxLen = 0;

    while (end < nums.size()) {
        sum += nums[end];

        while (sum > k) {
            sum -= nums[start];
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
        end++;
    }
    return maxLen;
}

/*
==============================
🔸 Template 2: Non-Shrinkable Window
==============================
Use when you just need to shift the window instead of shrinking it repeatedly.
*/

int non_shrinkable_example(vector<int>& nums, int k) {
    int start = 0, end = 0, sum = 0, maxLen = 0;

    while (end < nums.size()) {
        sum += nums[end];

        if (sum > k) {
            sum -= nums[start];
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
        end++;
    }
    return maxLen;
}

/*
=====================================
🧪 Example: Longest Substring Without Repeating Characters
(Shrinkable Template)
=====================================
*/

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n == 0) return 0;

    int start = 0, end = 0;
    unordered_map<char, int> mp;
    int maxLen = 0;

    while (end < n) {
        char ch = s[end];
        mp[ch]++;

        while (mp[ch] > 1) {
            mp[s[start]]--;
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
        end++;
    }
    return maxLen;
}

/*
=================================================
🧪 Example: Frequency of Most Frequent Element (Shrinkable)
=================================================
*/

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long start = 0, sum = 0, maxLen = 0;

    for (int end = 0; end < nums.size(); ++end) {
        sum += nums[end];

        while ((end - start + 1LL) * nums[end] - sum > k) {
            sum -= nums[start];
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}

/*
========================================================
🧪 Example: Longest Subarray of 1's After Deleting One (Shrinkable)
========================================================
*/

int longestSubarray(vector<int>& nums) {
    int start = 0, end = 0, zeros = 0, maxLen = 0;

    while (end < nums.size()) {
        if (nums[end] == 0) zeros++;

        while (zeros > 1) {
            if (nums[start] == 0) zeros--;
            start++;
        }

        maxLen = max(maxLen, end - start);
        end++;
    }
    return maxLen;
}

/*
====================================
Add more problems as needed using these templates
====================================
*/

int main() {
    vector<int> nums = {1, 2, 4};
    int k = 5;
    cout << "Max Frequency: " << maxFrequency(nums, k) << endl;

    string s = "abcabcbb";
    cout << "Longest Substring Without Repeating Characters: " << lengthOfLongestSubstring(s) << endl;

    return 0;
}
