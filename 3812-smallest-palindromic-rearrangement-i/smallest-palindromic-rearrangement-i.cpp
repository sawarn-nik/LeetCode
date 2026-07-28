class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        sort(s.begin(),s.begin()+n/2);
        int i = 0, j = n-1;
        while(i <= j){
            s[j] = s[i];
            i++;
            j--;
        } 
        return s;
    }
};