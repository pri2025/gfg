class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        for(int i=n-1; i>=0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }

        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};


    //int num = digits[0];
        // for(int i=1; i<n; i++){
        //     int digit = digits[i];
        //     num = num * 10 + digit;
        // }
        // int new_num = num+1;
        // int count = 0;
        // int temp = new_num;
        // while(new_num > 0){
        //     new_num = new_num / 10;
        //     count++;
        // }

        // vector<int> res(count);
        // for(int i=count-1; i>=0; i--){
        //     res[i] = temp % 10;
        //     temp = temp/10;
        // }
