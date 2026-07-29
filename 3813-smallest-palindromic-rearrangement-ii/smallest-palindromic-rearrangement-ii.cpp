// class Solution {
// public:
//     string smallestPalindrome(string s, int k) {
//         int n = s.size();
//         k--;
//         sort(s.begin(),s.begin()+n/2);

//         string temp = s.substr(0, n / 2);
//         while(k--){
//             if (!next_permutation(temp.begin(), temp.end()))
//                 return "";
//         }
//         string first = temp;
//         reverse(temp.begin(),temp.end());
//         if (n % 2 == 0)
//             return first + temp;
//         else
//             return first + s[n / 2] + temp;
//     }
// };
class Solution {
public:
    static const long long LIMIT = 1000001;

    long long comb(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res >= LIMIT) return LIMIT;
        }

        return res;
    }

    long long countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long ways = 1;

        for (int x : cnt) {
            if (x == 0) continue;

            ways *= comb(rem, x);
            if (ways >= LIMIT) ways = LIMIT;

            rem -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);

        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] & 1)
                mid.push_back('a' + i);
        }

        if (countWays(half) < k)
            return "";

        int len = 0;
        for (int x : half)
            len += x;

        string left;

        while ((int)left.size() < len) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};