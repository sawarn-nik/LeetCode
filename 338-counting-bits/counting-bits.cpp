class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        if(n == 0) return ans;
        int t = 0;
        while ((1 << t) <= n) {
            ans[1 << t] = 1;
            t++;
        }
        int st = 2;
        for(int i = 3; i <= n; i++){
            if(ans[i] == 1){
                st = i;
                continue;
            }
            ans[i] = ans[st]+ans[i-st];
        }
        return ans;
    }
};