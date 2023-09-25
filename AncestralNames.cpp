
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

    int romanToInt(string roman){
        unordered_map<char, int> romanValue = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50}
        };

        int decimal = 0, prev = 0;
        for(int i = roman.size() - 1; i >= 0; i--){
            int value = romanValue[roman[i]];
            if(value < prev){
                decimal -= value;
            }
            else{
                decimal += value;
            }

            prev = value;
        }

        return decimal;
    }

    bool cmp(string &A, string &B){
        int i = 0, j = 0;
        while(A[i] != ' ')
                i++;
        while(B[j] != ' ')
            j++;
        string nameA = A.substr(0, i), nameB = B.substr(0, j);
        int valA = romanToInt(A.substr(i + 1)), valB = romanToInt(B.substr(j + 1));

        if(nameA == nameB)
            return valA < valB;

        return nameA < nameB;
    }

    vector<string> sortRoman(vector<string> names){
        sort(names.begin(), names.end(), cmp);
        return names;
    }


int main() {
    init_code();
    int n;
    cin >> n;
    vector<string> names(n);
    for(int i = 0; i < n; i++){
        string x, y;
        cin >> x >> y;
        names[i] = x + " " + y;
    }

    vector<string> sortedNames = sortRoman(names);
    for(int i = 0; i < sortedNames.size(); i++){
        cout << sortedNames[i] << endl;
    }

    return 0;
}
