
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

long long factorial(long long num){
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}
 

long long sumOfnCr(int n, int R, int L){
    long long r;
    long long res = 0;
 
    for (r = L; r <= R; r++)
        res += (factorial(n)
                / (factorial(r)
                   * factorial(n - r)));
 
    return res;
}

int countTeams(vector<int> skills, int minPlayers, int minLevel, int maxLevel){
    int n = 0;
    for(int x : skills){
        if( x >= minLevel && x <= maxLevel)
            n++;
    }

    int res = (1 << n)  - sumOfnCr(n, minPlayers - 1, 0);
    return res; 
}

int main() {
    init_code();
    int n;
    cin >> n;
    vector<int> skills(n);
    for(int i = 0; i < n; i++){
        cin >> skills[i];
    }
    int minPlayers, minLevel, maxLevel;
    cin >> minPlayers >> minLevel >> maxLevel;

    cout << countTeams(skills, minPlayers, minLevel, maxLevel);

    
    return 0;
}
