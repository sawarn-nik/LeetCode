class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8) return n;

        int rem = n%8;
        int q = n/8;
        
        int res = 0;
        res += 8*(q*(q+1)/2);
        res += (q+1)*rem;
        return res;
    }
};