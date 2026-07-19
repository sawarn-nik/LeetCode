class Solution {
public:
    vector<int> fairCandySwap(vector<int>& as, vector<int>& bs) {
        int sas = 0,sbs = 0;
        vector<int> ans;
        for (int x : as) sas += x;
        for (int x : bs) sbs += x;
        for(auto it1:as){
            for(auto it2:bs){
                if(sas-it1+it2 == sbs-it2+it1) 
                {
                    ans.push_back(it1);
                    ans.push_back(it2);
                    break;
                }
            }
            if(ans.size() == 2) break;
        }
        return ans;
    }
};