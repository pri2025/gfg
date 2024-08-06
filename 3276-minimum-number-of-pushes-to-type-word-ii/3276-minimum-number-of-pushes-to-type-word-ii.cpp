class Solution {
public:
bool static cmp(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}

int minimumPushes(const string& word) {
    // Step 1: Count frequencies
    map<char, int> freq;
    for (char c : word) {
        freq[c]++;
    }

    // Step 2: Extract key-value pairs into a vector
    vector<pair<char, int>> vec(freq.begin(), freq.end());

    // Step 3: Sort the vector by frequency in descending order
    sort(vec.begin(), vec.end(), cmp);

    // Step 4: Calculate the minimum number of pushes
    int push = 0;
    int indx = 0;

    while (indx < vec.size()) {
        if (indx < 8) {
            push += vec[indx].second;
        }
        else if (indx < 16) {
            push += 2 * vec[indx].second;
        }
        else if (indx < 24) {
            push += 3 * vec[indx].second;
        }
        else {
            push += 4 * vec[indx].second;
        }
        indx++;
    }

    return push;
}
    // bool static cmp(pair<char,int> a, pair<char,int> b){
    //     return a.second > b.second;
    // }
    // int minimumPushes(string word) {
    //     map<char,int> freq;
    //     for(auto it: word){
    //         freq[it]++;
    //     }

    //     vector<pair<char,int>> vec(freq.begin(),freq.end());
    //     sort(vec.begin(), vec.end(),cmp);
    //     int push = 0;
    //     int indx = 0;

    //     while(indx < word.length()){
    //         if(indx <8){
    //             push += vec[indx].second;
    //         }
    //         else if(indx <16){
    //             push += 2*vec[indx].second;
    //         }
    //         else if(indx < 24){
    //             push += 3*vec[indx].second;
    //         }
    //         else{
    //             push += 4*vec[indx].second;
    //         }
    //         indx++;

    //     }
    //     return push;

    // }
};