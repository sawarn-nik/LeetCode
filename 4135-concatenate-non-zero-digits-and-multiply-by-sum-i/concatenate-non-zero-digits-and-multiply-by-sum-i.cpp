class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res = 0;
        string x = "";
        long long sum = 0;
        string tem = to_string(n);
        for(int i = 0; i < tem.length(); i++){
            if(tem[i] == '0') continue;
            x += tem[i];
            sum += tem[i]-'0';
        }
        if (x.empty())
            return 0;
        res = 1LL*stoi(x)*sum;
        return res;
    }
};