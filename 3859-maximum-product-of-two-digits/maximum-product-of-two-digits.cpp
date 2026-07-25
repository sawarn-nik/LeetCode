class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int sz = s.size(); 
        sort(s.begin(),s.end());
        return (int)(s[sz-1]-'0')*(s[sz-2]-'0');
    }
};