class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int l = 0,i = 0, j = 0,n = s.size();

        while(j < n){
                while(i<j && mp[s[j]]>=2){
                    mp[s[i]]--;
                    i++;
                }
                mp[s[j]]++;
                l = max(l,j-i+1);
                j++;
            }
        

        return l;
    }
};