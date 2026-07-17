// class Solution {
// public:
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         int n = nums.size();
//         vector<int> temp;
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 temp.push_back(__gcd(nums[i],nums[j]));
//             }
//         }
//         sort(temp.begin(),temp.end());
//         vector<int> res(queries.size(),0);
//         for(int i = 0; i < queries.size(); i++){
//             res[i] = temp[queries[i]];
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1);
        for (int x : nums) freq[x]++;

        vector<long long> cnt(mx + 1);

        // cnt[g] = numbers divisible by g
        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g) {
                cnt[g] += freq[j];
            }
        }

        vector<long long> exact(mx + 1);

        // exact[g] = pairs with gcd exactly g
        for (int g = mx; g >= 1; g--) {
            long long c = cnt[g];
            exact[g] = c * (c - 1) / 2;

            for (int j = 2 * g; j <= mx; j += g) {
                exact[g] -= exact[j];
            }
        }

        vector<long long> pref(mx + 1);
        for (int g = 1; g <= mx; g++) {
            pref[g] = pref[g - 1] + exact[g];
        }

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(pref.begin(), pref.end(), q + 1)
                    - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};