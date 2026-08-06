class Solution {
private:
    long long prod(string s){
        long long ans = 1;
        for(char c:s){
            ans *= (c-'0');
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        while(true){
            string s = to_string(n);
            if(prod(s)%t == 0){
                return n;
                break;
            }
            n++;
        }
        return INT_MAX;
    }
};