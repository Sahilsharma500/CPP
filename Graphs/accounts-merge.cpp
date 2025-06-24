/*
Problem: Accounts Merge

Intuition:
This is a classic Union-Find (Disjoint Set Union - DSU) problem.
Each account contains a person's name and list of email addresses. If two accounts share an email,
they belong to the same person and should be merged.

Approach:
1. Assign each email an index based on the account it first appears in.
2. Use Union-Find to merge accounts that share at least one common email.
3. After building the union structure, group emails by their root parent.
4. For each group, sort emails and attach the corresponding name (from the original account).
5. Return all merged accounts.

Time Complexity:
- Let N be the total number of emails across all accounts.
- DSU operations (find/union) are nearly O(1) due to path compression.
- Sorting each email group costs O(M log M), where M is the size of that group.
Overall: O(N * α(N) + M log M)

Space Complexity: O(N), for maps and DSU parent array.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Find with path compression
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    // Union emails based on accounts
    void getDisjointSet(unordered_map<string, int>& emailToIndex, vector<int>& parent, vector<vector<string>>& accounts) {
        int n = accounts.size();

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                // If email is new, map it to this account index
                if (emailToIndex.find(email) == emailToIndex.end()) {
                    emailToIndex[email] = i;
                } else {
                    // Union the current account with the one this email was first seen in
                    int u = findParent(parent, i);
                    int v = findParent(parent, emailToIndex[email]);
                    if (u != v) {
                        parent[u] = v; // Union
                    }
                }
            }
        }
    }

    // Construct final merged accounts using grouped emails
    void constructResult(unordered_map<string, int>& emailToIndex, vector<int>& parent, vector<vector<string>>& accounts, vector<vector<string>>& result) {
        unordered_map<int, vector<string>> mergedEmails;

        // Group emails by their representative parent account index
        for (auto& entry : emailToIndex) {
            string email = entry.first;
            int rootIndex = findParent(parent, entry.second);
            mergedEmails[rootIndex].push_back(email);
        }

        // Create final merged account format
        for (auto& entry : mergedEmails) {
            int idx = entry.first;
            vector<string> emails = entry.second;
            sort(emails.begin(), emails.end()); // Optional: sort for consistency

            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[idx][0]); // Add the name
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());

            result.push_back(mergedAccount);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);

        // Initially, each account is its own parent
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<string, int> emailToIndex;

        // Build DSU structure
        getDisjointSet(emailToIndex, parent, accounts);

        // Collect final results
        vector<vector<string>> result;
        constructResult(emailToIndex, parent, accounts, result);

        return result;
    }
};
