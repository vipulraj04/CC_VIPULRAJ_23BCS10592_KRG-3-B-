#include<bits/stdc++.h>
using namespace std;

//Search Patter(GFG) : KMP Algorithm
class Solution {
  public:
  
    // Function to build LPS array
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        
        int len = 0; 
        int i = 1;
        
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    vector<int> search(string &txt, string &pat) {
        vector<int> ans;
        
        int n = txt.size();
        int m = pat.size();
        
        vector<int> lps = buildLPS(pat);
        
        int i = 0; 
        int j = 0; 
        
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            
            if (j == m) {
                ans.push_back(i - j); 
                j = lps[j - 1];
            }
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return ans;
    }
};

//Unique Paths 2
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    if (grid[0][0] == 1) return 0;
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
    }
};
