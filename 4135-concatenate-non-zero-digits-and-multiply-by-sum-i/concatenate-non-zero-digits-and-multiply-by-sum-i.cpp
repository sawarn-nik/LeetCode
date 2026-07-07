class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res = 0;
        long long x = 0;
        long long sum = 0;
        stack<long long> st;
        while(n){
            if(n%10){
                sum+=n%10;
                st.push(n%10);
            }
            n/=10;
        }
        while(!st.empty()){
            x+=st.top();
            x*=10;
            st.pop();
        }
        x/=10;
        res = x*sum;
        return res;
    }
};