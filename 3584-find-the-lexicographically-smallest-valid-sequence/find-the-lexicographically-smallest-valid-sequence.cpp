class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // exact[i]:
        // maximum number of characters from the END of word2
        // that can be matched exactly using word1[i...]
        vector<int> exact(n + 1, 0);

        // almost[i]:
        // maximum number of characters from the END of word2
        // that can be matched with at most one mismatch
        // using word1[i...]
        vector<int> almost(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Exact matching
            int e = exact[i + 1];

            exact[i] = e;

            if (e < m && word1[i] == word2[m - 1 - e]) {
                exact[i]++;
            }

            // At most one mismatch
            int a = almost[i + 1];

            // Option 1: skip word1[i]
            almost[i] = a;

            // Option 2: use word1[i] as an exact match
            if (a < m && word1[i] == word2[m - 1 - a]) {
                almost[i] = max(almost[i], a + 1);
            }

            // Option 3: use word1[i] as the one mismatch
            // The remaining characters must match exactly.
            if (e < m) {
                almost[i] = max(almost[i], e + 1);
            }
        }

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        for (int k = 0; k < m; k++) {

            int remaining = m - k - 1;
            bool found = false;

            while (pos < n) {

                if (usedMismatch) {

                    // No mismatch left.
                    // Current character MUST match.
                    if (word1[pos] == word2[k] &&
                        exact[pos + 1] >= remaining) {

                        ans.push_back(pos);
                        pos++;
                        found = true;
                        break;
                    }

                } else {

                    // Case 1:
                    // Current character matches.
                    // We may still use mismatch later.
                    if (word1[pos] == word2[k] &&
                        almost[pos + 1] >= remaining) {

                        ans.push_back(pos);
                        pos++;
                        found = true;
                        break;
                    }

                    // Case 2:
                    // Current character doesn't match.
                    // Use our one mismatch here.
                    if (word1[pos] != word2[k] &&
                        exact[pos + 1] >= remaining) {

                        ans.push_back(pos);
                        pos++;
                        usedMismatch = true;
                        found = true;
                        break;
                    }
                }

                pos++;
            }

            if (!found) {
                return {};
            }
        }

        return ans;
    }
};