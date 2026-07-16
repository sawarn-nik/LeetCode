class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n,0);
        mx[0] = nums[0];
        for(int i = 1; i < n; i++){
            mx[i] = max(nums[i],mx[i-1]);
        }
        vector<int> pxg(n,0);
        for(int i = 0; i < n; i++){
            pxg[i] = __gcd(nums[i],mx[i]);
        }

        sort(pxg.begin(),pxg.end());
        int i = 0, j = n-1;
        long long sum = 0;
        while(i < j){
            sum += __gcd(pxg[i],pxg[j]);
            i++;j--;
        }
        return sum;
    }
};