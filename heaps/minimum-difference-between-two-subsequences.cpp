#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

/*
Approach:
We divide the array into 3 equal parts: left, middle, and right.
We want to pick k elements from the first 2k elements with the smallest sum (using max heap),
and pick k elements from the last 2k elements with the largest sum (using min heap).
Then we calculate the minimum possible difference of those two sums.
*/

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;

        // max heap for left part
        priority_queue<int> pq1;
        vector<long long> left(n, 0);
        long long sum = 0;

        for(int i = 0; i < 2 * k; i++) {
            sum += nums[i];
            pq1.push(nums[i]);

            if(pq1.size() > k) {
                sum -= pq1.top();
                pq1.pop();
            }
            if(pq1.size() == k) {
                left[i] = sum;
            }
        }

        // min heap for right part
        priority_queue<int, vector<int>, greater<int>> pq2;
        vector<long long> right(n, 0);
        sum = 0;

        for(int i = n - 1; i >= k; i--) {
            sum += nums[i];
            pq2.push(nums[i]);

            if(pq2.size() > k) {
                sum -= pq2.top();
                pq2.pop();
            }
            if(pq2.size() == k) {
                right[i] = sum;
            }
        }

        long long ans = LLONG_MAX;
        for(int i = k - 1; i < 2 * k; i++) {
            ans = min(ans, left[i] - right[i + 1]);
        }

        return ans;
    }
};
