class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int n = s.size();
        int cnt = 0;

        while (i < n && s[i] == '0')
            i++;

        int j = i;

        int bestL = -1;
        int bestR = -1;
        int bestLen = INT_MAX;

        while (j < n) {

            if (s[j] == '1')
                cnt++;

            if (cnt == k) {

                // Remove leading zeroes
                while (i < j && s[i] == '0')
                    i++;

                int len = j - i + 1;

                if (len < bestLen) {
                    bestLen = len;
                    bestL = i;
                    bestR = j;
                }
                else if (len == bestLen) {
                    // Compare only when lengths are equal
                    if (s.compare(i, len, s, bestL, bestLen) < 0) {
                        bestL = i;
                        bestR = j;
                    }
                }

                // Remove first 1
                i++;
                cnt--;
            }

            j++;
        }

        if (bestL == -1)
            return "";

        return s.substr(bestL, bestLen);
    }
};