#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
    	
	
    ll n, K;
    cin >> n >> K;
    
    vector<pair<ll, ll>> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].first >> segs[i].second;
    }
    
    // 1. 按左端点排序
    sort(segs.begin(), segs.end());
    
    priority_queue<ll, vector<ll>, greater<ll>> pq; // 小根堆，存右端点
    ll ans = 1;
    
    for (auto seg : segs) {
        // 2. 移除所有右端点 < l 的区间，它们不再重叠
        while (!pq.empty() && pq.top() < seg.first) {
            pq.pop();
        }
        
        // 3. 当前重叠区间数 = pq.size()
        ll available = K - pq.size();
        if (available <= 0) {
            ans = 0;
            break;
        }
        
        // 4. 累乘方案数
        ans = (ans * available) % MOD;
        
        // 5. 当前区间变为活跃状态
        pq.push(seg.second);
    }
    
    cout << ans << "\n";
}
    return 0;
}
