class Solution {
public:
    stack<int> st; queue<int> q;
    int countStudents(vector<int>& stud, vector<int>& sw) {
        for(int i =0; i < stud.size(); i++){
            q.push(stud[i]);
        }

        for(int i = sw.size()-1 ; i >= 0; i--){
            st.push(sw[i]);
        }
        
        int cnt = stud.size();
        int a = 0;
        while(!q.empty() && a < q.size()){
            if(st.top() == q.front()){
                st.pop();
                q.pop();
                cnt--;
                a=0;
            }
            else{
                int x = q.front();
                q.pop();
                q.push(x);
                a++;
            }
        }
        return cnt;
    }
    
};