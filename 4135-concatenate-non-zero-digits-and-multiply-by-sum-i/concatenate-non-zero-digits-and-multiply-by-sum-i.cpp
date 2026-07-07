class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res = 0;
        long long x = 0;
        long long sum = 0;
        string tem = to_string(n);
        for(int i = 0; i < tem.length(); i++){
            if(tem[i] == '0') continue;
            x += tem[i] - '0';
            x*=10;
            sum += tem[i]-'0';
        }
        x/=10;
        res = x*sum;
        return res;
    }
};