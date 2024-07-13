class Solution {
public:
    void fn(int index,int target,vector<int>& arr,vector<vector<int>> &res,vector<int> &ans){
        if(index == arr.size()){
            if(target == 0){
                res.push_back(ans);
            }
            return;
        }

        if( arr[index] <= target){
            ans.push_back(arr[index]);
            fn(index,target-arr[index],arr,res,ans);
            ans.pop_back();
        }

        fn(index+1, target, arr,res,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        int index = 0;
        fn(index, target,arr,res,ans);

        return res;
    }
};