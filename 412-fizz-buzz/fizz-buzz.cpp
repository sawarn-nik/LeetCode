class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ress;
        for(int i = 1; i <= n; i++){
            if((i) % 3 == 0 && (i) % 5 == 0){
                ress.push_back("FizzBuzz");
            }
            else if((i) % 3 == 0 && (i) % 5 != 0){
                ress.push_back("Fizz");
            }
            else if((i) % 3 != 0 && (i) % 5 == 0){
                ress.push_back("Buzz");
            }
            else{
                ress.push_back(to_string(i));
            }
        }
        return ress;
    }
};