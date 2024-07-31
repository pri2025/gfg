class Solution {
public:
int org_w;

int fn(int i, int width, int h, vector<vector<int>>& books,vector<vector<int>> &dp) {
    // Base case: if we are at the last book
    if (i == books.size()) {
        return h;  // Return the current height as there's no more books to place
    }

    if(dp[i][width] != -1){
        return dp[i][width];
    }

    int maxh = max(h, books[i][1]);

    int sameshelf = INT_MAX;
    if (books[i][0] <= width) {
        sameshelf = fn(i + 1, width - books[i][0], maxh, books,dp);  // Place the book on the same shelf
    }

    int newshelf = h + fn(i + 1, org_w - books[i][0], books[i][1], books,dp);  // Place the book on a new shelf

    return dp[i][width] =  min(sameshelf, newshelf);  // Return the minimum height
}

int minHeightShelves(vector<vector<int>>& books, int w) {
    org_w = w;
    vector<vector<int>> dp(books.size(), vector<int>(w + 1, -1));
    return fn(0, w, 0, books,dp);
}
};