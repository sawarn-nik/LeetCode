class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int cnt = 0;
        sort(reservedSeats.begin(), reservedSeats.end());

        int j = 0;

        for(int i = 1; i <= n; i++) {

            if(j >= reservedSeats.size() || reservedSeats[j][0] != i) {
                cnt += 2;
                continue;
            }

            bool first = true;
            bool second = true;
            bool third = true;

            while(j < reservedSeats.size() && reservedSeats[j][0] == i) {
                int seat = reservedSeats[j][1];

                if(seat >= 2 && seat <= 5)
                    first = false;

                if(seat >= 4 && seat <= 7)
                    second = false;

                if(seat >= 6 && seat <= 9)
                    third = false;

                j++;
            }

            if(first && third)
                cnt += 2;
            else if(first || second || third)
                cnt += 1;
        }

        return cnt;
    }
};