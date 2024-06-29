class Solution {
public:
    stack<int> st; queue<int> q;
    int countStudents(vector<int>& stud, vector<int>& sw) {
        int c1 = 0, c2= 0;
        for(int i =0; i < stud.size(); i++){
            //q.push(stud[i]);
            if(stud[i] == 1)
            c1++;//1
            else c2++;//0
        }

        for(int i = sw.size()-1 ; i >= 0; i--){
            st.push(sw[i]);
        }
        for(int i : sw){
            if(i == 0 && c2 == 0){
                return c1;
            }
            if(i == 1 && c1 == 0){
                return c2;
            }
            if(i == 0){
                c2--;
            }
            else{
                c1--;
            }
        }

        return 0;
        
    }

    //     int cnt = stud.size();
    //     int a = 0;
    //     while(!q.empty() && a < q.size()){
    //         if(st.top() == q.front()){
    //             st.pop();
    //             q.pop();
    //             cnt--;
    //             a=0;
    //         }
    //         else{
    //             int x = q.front();
    //             q.pop();
    //             q.push(x);
    //             a++;
    //         }
    //     }
    //     return cnt;
    // }
    
};