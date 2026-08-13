class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> n(101,0);
        for (auto it:h){
            n[it]++;
        }
        int j = 1,mm = 0;
        for(int i = 0; i < h.size(); i++){
            while(n[j] == 0){
                j++;
            }
            if(h[i] != j){
                mm++;
            }
            n[j]--;
        }
        return mm;
    }
};