#include<bits/stdc++.h>
class Solution {
public:
//     bool static comparePairs(const pair<char, int>& a, const pair<char, int>& b) {
//     return a.second > b.second; // Sort in descending order based on frequency
// }
    string frequencySort(string s) {
        vector<pair<int,char>> hash('z'+1,{0,0});

        for(char i: s){
            hash[i] = {hash[i].first+1,i};
        }

        sort(hash.begin(), hash.end());

        string res= "";
        for(auto p : hash){
            res = string(p.first, p.second) + res;
        }

        return res;
    }
};
//map<char,int> mp;
        // for(char i : s){
        //     mp[i]++;
        // }
        // vector<pair<char,int>> v(mp.begin(), mp.end()); //aise bhi kr skte
        // // for(auto& it:mp){
        // //     v.push_back(it);
        // // }

        // sort(v.begin(), v.end(), comparePairs);

        // string ans = "";
        // for(auto& it : v){
        //     while(it.second > 0){
        //         ans = ans+it.first;
        //         it.second--;
        //     }
        // }
        // return ans;