class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        long long sum = 0;
        long long prod = 1;
        string nn = to_string(n);
        for(int i = 0; i < nn.size(); i++){
            sum += nn[i]-'0';
            prod *= nn[i]-'0';
        }
        sum += prod;
        if(temp%sum == 0){
            return true;
        }
        return false;
    }
};