/*
------------------------------------------
🧠 Problem Intuition: Word Ladder (LeetCode)
------------------------------------------
You're given a `beginWord`, an `endWord`, and a list of allowed words (`wordList`).
You can change only **one letter at a time**, and each intermediate word must be in `wordList`.

Goal:
- Find the **shortest transformation sequence length** from `beginWord` to `endWord`.
- If no such sequence exists, return 0.

Approach:
- Use **BFS (Breadth-First Search)** to explore all possible word transformations level by level.
- At each level, we try changing each character of the current word to all possible letters (a-z).
- We return the level (or depth) where we reach the `endWord`.

Why BFS?
- Because we need the **shortest** path, and BFS always explores all words of a given "depth" before going deeper.

Time Complexity:
- O(N * 26 * L), where N = size of wordList, L = word length

*/

#include<iostream>
#include<unordered_set>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to a set for faster lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If endWord is not in wordList, transformation is not possible
        if (wordSet.count(endWord) == 0) return 0;

        // Queue for BFS: each element holds the current word and the current level (steps)
        queue<pair<string, int>> q;
        q.push({beginWord, 1});  // Start from the beginWord with level 1

        while (!q.empty()) {
            auto [word, len] = q.front();  // Current word and number of transformations so far
            q.pop();

            // Try changing each character of the word
            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                // Try replacing the i-th character with every letter from 'a' to 'z'
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;

                    // If we reach the endWord, return the number of steps + 1
                    if (temp == endWord) return len + 1;

                    // If this transformed word is in the wordList and not visited yet
                    if (wordSet.count(temp)) {
                        q.push({temp, len + 1});  // Add it to the queue for next level
                        wordSet.erase(temp);      // Mark it as visited by removing from the set
                    }
                }
            }
        }

        // If no transformation sequence found
        return 0;
    }
};
