class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> a;
        int l = 0, r= 0; // maintain a range, +1 for ( -1 for ), +1, 0 -1 for *
        for(char i : s){
            if(i == '('){
                l++;
                r++;
            }
            else if(i == ')'){
                l--;
                r--;
            }
            else{
                l--;
                r++;
            }
            if(l < 0) l = 0;// * ko ( consider nhi krenge
            if(r < 0) return false;
        } 
        return l == 0; 
    }  
};

//for(int i =0; i<s.length(); i++){ tc and sc O(n)
    //         if(s[i] == '('){
    //             left.push(i);
    //         }
    //         else if(s[i] == ')'){
    //             if(!left.empty()){
    //                 left.pop();
    //             }
    //             else if(!a.empty()){
    //                 a.pop();
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
    //         else{//star
    //             a.push(i);
    //         }
    //     }

    //     while(!left.empty()){
    //         if(a.empty() || a.top() < left.top()){
    //             return false;
    //         }
    //         left.pop();
    //         a.pop();
    //     }
    //     return true;
    // }