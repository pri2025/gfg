class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        int flag1 = 0;
        int flag2 = 0;
        for(int i= 0; i<a.size()-1 ; i++){
            if(a[i] < a[i+1]){
                flag1 = 1;
            }
            else if(a[i] > a[i+1]){
                flag2 = 1;
            }

        }
        if(flag1 == 1 && flag2 == 1){
            return false;
        }
        else{
            return true;
        }
        return -1;
    }
};