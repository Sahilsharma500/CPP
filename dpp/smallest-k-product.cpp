#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Intuition:
-----------
We are given two sorted arrays `nums1` and `nums2`, and we need to find the k-th smallest product
that can be formed by multiplying one element from `nums1` and one from `nums2`.

Brute force would take O(N*M) time and store all products, which is too slow for large arrays.

Instead, we use **binary search on the answer** (i.e., possible product values):
- The smallest possible product is -1e10 (roughly -1e5 * 1e5)
- The largest is +1e10

For each candidate product (mid), we count how many products are ≤ mid using a helper function
called `findCountSmallest()`.

This is a variation of the **"k-th smallest pair"** problem with a twist: we must consider signs 
since products with negative and positive numbers behave differently.

Approach:
-----------
1. Binary search on the product value range [-1e10, 1e10]
2. For each `mid`, count how many products ≤ mid
3. Narrow the search based on whether that count is ≥ or < k

Time Complexity: O((N+M) * log(2e10))  
Space Complexity: O(1)
*/

class Solution {
public:
    // Helper to count how many pairs have product ≤ midProduct
    long long findCountSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct) {
        long long productsCount = 0;
        int n = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            // Case 1: nums1[i] >= 0 → use upper bound binary search
            if (nums1[i] >= 0) {
                int l = 0;
                int r = n - 1;
                int m = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    long long product = 1LL * nums1[i] * nums2[mid];
                    if (product <= midProduct) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                // m is the last index where product <= midProduct
                productsCount += (m + 1);
            } 
            // Case 2: nums1[i] < 0 → reverse binary search
            else {
                int l = 0;
                int r = n - 1;
                int m = n;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    long long product = 1LL * nums1[i] * nums2[mid];
                    if (product <= midProduct) {
                        m = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                // n - m elements where product <= midProduct
                productsCount += (n - m);
            }
        }

        return productsCount;
    }

    // Main function using binary search on product value
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;
        long long l = -1e10; // Lower bound of product values
        long long r = 1e10;  // Upper bound of product values

        // Binary search for the k-th smallest product
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long long countSmallest = findCountSmallest(nums1, nums2, mid);

            // If count of products <= mid is ≥ k, move left
            if (countSmallest >= k) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};
