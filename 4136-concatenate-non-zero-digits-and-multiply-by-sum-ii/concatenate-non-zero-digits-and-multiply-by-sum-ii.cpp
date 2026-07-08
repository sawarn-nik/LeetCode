class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> res;
        vector<long long> prefsum(n+1,0);
        vector<long long> prefnum(n+1,0);
        vector<long long> pow10(n + 1, 1);
        vector<int> cnt(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        
        for(int i = 0; i < n; i++){
            prefsum[i+1] = prefsum[i];
            prefnum[i+1] = prefnum[i];
            cnt[i+1] = cnt[i];

            if(s[i] != '0'){
                int d = s[i] - '0';
                prefsum[i+1] += d;
                cnt[i+1]++;
                prefnum[i + 1] =
                    (prefnum[i] * 10 + d) % MOD;
            }   
        }
        for(auto &it : queries){
            int l = it[0];
            int r = it[1];
            long long sum = prefsum[r+1]-prefsum[l];
            int len = cnt[r+1]-cnt[l];
            long long num = (prefnum[r+1]-prefnum[l]*pow10[len]%MOD + MOD) % MOD;
            
            res.push_back((num * (sum % MOD)) % MOD);
        }
        return res;
    }
};