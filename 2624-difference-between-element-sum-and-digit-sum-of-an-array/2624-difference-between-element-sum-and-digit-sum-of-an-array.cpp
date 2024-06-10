class Solution {
public:
    
    
    int d_sum = 0;
    int ele = 0;

    int fn(int num){
        int sum1 = 0;
        if(num<9){
            return num;
        }
        while(num >0){
            int d = num % 10;
            sum1 = sum1 + d;
            num = num / 10;
        }
        return sum1;
    }
    int differenceOfSum(vector<int>& nums) { 
        //1 15 6 3 
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            ele = ele + nums[i];
            d_sum = d_sum + fn(nums[i]);

        }  
        return abs(d_sum - ele);
    }
    
};