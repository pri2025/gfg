class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> a;
        // int l = 0;
        // int r= 0;
        // int c = 0;
        
        for(int i =0; i<s.length(); i++){
            if(s[i] == '('){
                left.push(i);
            }
            else if(s[i] == ')'){
                if(!left.empty()){
                    left.pop();
                }
                else if(!a.empty()){
                    a.pop();
                }
                else{
                    return false;
                }
            }
            else{//star
                a.push(i);
            }
        }

        while(!left.empty()){
            if(a.empty() || a.top() < left.top()){
                return false;
            }
            left.pop();
            a.pop();
        }
        return true;
    }
};

    // for(char i : s){
    //         if(i == '('){
    //             left++;
    //         }
    //         else if(i == ')'){
    //             right++;
    //         }
    //         else{
    //             a++;
    //         }
    //     }

    //     if(left == right){
    //         return true;
    //     }
    //     else if(left < right){
    //         while( a>0 && left < right){
    //             left++; a--;
    //         }
    //         if(left == right){
    //             return true;
    //         }
    //     }
    //     else if(right < left){
    //         while(right < left && a>0){
    //             right++;
    //             a--;
    //         }
    //         if(left == right){
    //             return true;
    //         }
    //     }
    //     else 
    //     return false;

 