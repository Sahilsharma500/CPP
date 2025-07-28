#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

/*
------------------------------------
🥄 Problem Intuition:
------------------------------------
Given:
- A string `s` representing a recipe using ingredients 'B' (Bread), 'S' (Sausage), and 'C' (Cheese).
- Initial quantities of each ingredient (b1, b2, b3).
- Prices per unit of each ingredient (p1, p2, p3).
- Total amount of money `r`.

Goal:
- Find the maximum number of sandwiches (or products) we can make from the recipe, even if we run out of ingredients and have to buy more.

Key Insight:
- We can binary search the **maximum number of sandwiches** possible.
- For each possible number `mid`, we check if we can afford the missing ingredients within budget.

------------------------------------
*/

int main() {
    // Read the recipe string: consists of 'B', 'S', and 'C'
    string s;
    cin >> s;

    // Read initial quantities of B, S, and C
    ll b1, b2, b3;
    cin >> b1 >> b2 >> b3;

    // Read prices of B, S, and C
    ll p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    // Read the total money available
    ll r;
    cin >> r;

    // Set the binary search range (we assume a max of 1e13 sandwiches can be made)
    ll start = 0;
    ll end = 1e13;

    // Count the required number of each ingredient per sandwich from the recipe
    ll a = 0, b = 0, c = 0;  // a = B count, b = S count, c = C count
    for (char& ch : s) {
        if (ch == 'B') a++;
        else if (ch == 'S') b++;
        else c++;  // 'C'
    }

    ll ans = 0;

    // Binary search to find the maximum number of sandwiches we can make
    while (start <= end) {
        ll mid = start + (end - start) / 2;  // number of sandwiches we are testing

        // Calculate how much of each ingredient is required for `mid` sandwiches
        ll r1 = max(a * mid - b1, 0LL);  // required extra Bread
        ll r2 = max(b * mid - b2, 0LL);  // required extra Sausage
        ll r3 = max(c * mid - b3, 0LL);  // required extra Cheese

        // Total price to buy missing ingredients
        ll price = r1 * p1 + r2 * p2 + r3 * p3;

        // Check if we can afford this with current money
        if (price <= r) {
            ans = mid;          // Update answer, we might be able to make more
            start = mid + 1;    // Try to find a bigger possible value
        } else {
            end = mid - 1;      // Try a smaller number
        }
    }

    // Print the final answer: max number of sandwiches
    cout << ans << endl;
    return 0;
}
