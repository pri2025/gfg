class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;
        map<int,int> mp;

        for(int num : nums2){
            while(!st.empty() && st.top() < num){
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }

        for(int num : nums1){
            res.push_back(mp[num]);
        }

        return res;
    
    }
};

//for(int i=0; i<nums1.size(); i++){
        //     int flag = 0;
        //     for(int j= 0; j<nums2.size(); j++){
        //         if(nums1[i] == nums2[j]){
        //             for(int k = j; k < nums2.size(); k++){
        //                 if(nums2[k] > nums2[j]){
        //                     flag = 1;
        //                     res.push_back(nums2[k]);
        //                     break;
        //                 }
        //             }
        //             if(flag ==0){
        //                 res.push_back(-1);
        //             }
        //         }
        //     }
        // }
        // return res;