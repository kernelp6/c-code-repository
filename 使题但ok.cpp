#include <bits/stdc++.h>
using namespace std;

int parent[10000];
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) parent[pa] = pb;
}

struct Person {
    int id, father, mother;
    vector<int> children;
    int houses;
    double area;
};

struct Family {
    int minId, count, totalHouses;
    double totalArea;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 初始化并查集（编号0-9999）
    for (int i = 0; i < 10000; i++) parent[i] = i;
    
    int N;
    cin >> N;
    
    // 记录每个编号的房产信息
    map<int, int> houses;
    map<int, double> area;
    set<int> ids; // 所有出现过的人的编号
    
    
    for (int i = 0; i < N; i++) {
        int id, father, mother, k;
        cin >> id >> father >> mother >> k;
        
        ids.insert(id);
        
        // 与父母合并
        if (father != -1) {
            ids.insert(father);
            unite(id, father);
        }
        if (mother != -1) {
            ids.insert(mother);
            unite(id, mother);
        }
        
        vector<int> children(k);
        for (int j = 0; j < k; j++) {
            cin >> children[j];
            ids.insert(children[j]);
            unite(id, children[j]);
        }
        
        int h;
        double a;
        cin >> h >> a;
        houses[id] = h;
        area[id] = a;
    }
    
    // 统计每个家庭
    map<int, Family> families; // root -> Family
    
    for (int id : ids) {
        int root = find(id);
        if (families.find(root) == families.end()) {
            families[root] = {id, 0, 0, 0.0};
        }
        families[root].minId = min(families[root].minId, id);
        families[root].count++;
        families[root].totalHouses += houses[id]; // 没有房产的人默认0
        families[root].totalArea += area[id];
    }
    
    
    // 转为vector排序
    vector<Family> result;
    for (auto& [root, fam] : families) {
        result.push_back(fam);
    }
    
    sort(result.begin(), result.end(), [](const Family& a, const Family& b) {
        double avgA = a.totalArea / a.count;
        double avgB = b.totalArea / b.count;
        if (fabs(avgA - avgB) > 1e-9) return avgA > avgB; // 面积降序
        return a.minId < b.minId; // 编号升序
    });
    
    cout << result.size() << "\n";
    cout << fixed << setprecision(3);
    for (auto& fam : result) {
        cout << setw(4) << setfill('0') << fam.minId << " "
             << fam.count << " "
             << (double)fam.totalHouses / fam.count << " "
             << fam.totalArea / fam.count << "\n";
    }
    
    return 0;
}
