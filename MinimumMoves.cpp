
#include<bits/stdc++.h>

using namespace std;
void init_code()
    {
      #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    // online submission
    #endif
    }

    int reqMoves(int i, int j, vector<vector<int>> &grid, int k, vector<vector<int>> &dp, vector<vector<bool>> &visited){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1 || visited[i][j])
            return 1e9;

        if(i == n - 1 && j == m - 1)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        visited[i][j] = true;

        int res = 1e9;

        for(int x = 1; x <= k; x++){
            
                res = min(res, 1 + reqMoves(i + x, j, grid, k, dp, visited));
            
                res = min(res, 1 + reqMoves(i - x, j, grid, k, dp, visited));
            
                res = min(res, 1 + reqMoves(i, j + x, grid, k, dp, visited));
           
                res = min(res, 1 + reqMoves(i, j - x, grid, k, dp, visited));
             
        }
        
        visited[i][j] = false;

        return dp[i][j] = res;
    }

    int minimumMoves(vector<vector<int>> grid, int k){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = reqMoves(0, 0, grid, k, dp, visited);
        
        return (ans == 1e9) ? -1 : ans;
    }


int main() {
    init_code();
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int k;
    cin >> k;
    cout << minimumMoves(grid, k);

    return 0;
}
