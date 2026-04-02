#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<string> strips(k);
    for (int i = 0; i < k; i++) {
        cin >> strips[i];
    }
    
    vector<vector<bool>> col_chars(n, vector<bool>(26, false));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < k; i++) {
            col_chars[j][strips[i][j] - 'a'] = true;
        }
    }
    
    vector<int> divisors;
    for (int d = 1; d <= n; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
        }
    }
    sort(divisors.begin(), divisors.end());
    
    for (int d : divisors) {
        bool possible = true;
        vector<int> chosen(d, -1); 
        
        for (int i = 0; i < d; i++) { 
            vector<bool> intersect(26, true);
            for (int j = i; j < n; j += d) {
                for (int c = 0; c < 26; c++) {
                    if (!col_chars[j][c]) {
                        intersect[c] = false;
                    }
                }
            }
            
            int selected = -1;
            for (int c = 0; c < 26; c++) {
                if (intersect[c]) {
                    selected = c;
                    break;
                }
            }
            
            if (selected == -1) {
                possible = false;
                break;
            }
            chosen[i] = selected;
        }
        
        if (possible) {
            string ans(n, ' ');
            for (int i = 0; i < n; i++) {
                ans[i] = 'a' + chosen[i % d];
            }
            cout << ans << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
