class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& i) {
        sort(i.begin(), i.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int cnt = i.size();
        int end = i[0][1];
        if(cnt == 1) return cnt;
        for(int ind = 1; ind < i.size(); ind++){
            if(i[ind][1] <= end){
                cnt--;
            }
            else{
                end = i[ind][1];
            }
        }
        return cnt;
    }
};