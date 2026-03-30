#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

// 存储当前找到的最优解
vector<LL> best;
// 当前搜索路径
vector<LL> path;
// 输入的分子和分母
LL a, b;
// 是否找到解
bool found;

// 求最大公约数
LL gcd(LL x, LL y) {
    return y == 0 ? x : gcd(y, x % y);
}

// 获取满足 1/d ≤ x/y 的最小分母 d
LL getMin(LL x, LL y) {
    // ceil(y/x)
    return (y + x - 1) / x;
}

// 检查当前解是否比最优解更好
// 检查当前解是否比最优解更好
bool isBetter(const vector<LL>& current, const vector<LL>& result) {
    if (result.empty()) return true;
    // 比较最后一项分母，越小越好（因为分数值越大）
    if (current.size() < result.size()) return true;
    if (current.size() > result.size()) return false;
    
    if (current.back() < result.back()) return true;
    if (current.back() > result.back()) return false;

    // 最后一项相同，比较项数，越少越好
    

    // 项数相同，比较字典序（前面的分母越小越好）
    for (size_t i = 0; i < current.size(); i++) {
        if (current[i] < result[i]) return true;
        if (current[i] > result[i]) return false;
    }
    return false; // 完全相等
}

// 迭代加深搜索
// depth: 剩余需要搜索的深度
// minDen: 当前可选择的最小分母
// x: 当前剩余的分子
// y: 当前剩余的分母
bool dfs(int depth, LL minDen, LL x, LL y) {
    // 如果已经凑完，直接记录解
    if (x == 0) {
        if (isBetter(path, best)) {
            best = path;
            found = true;
            return true;
        }
        return false;
    }

    // 剩余深度为0但还没凑完，失败
    if (depth == 0) return false;

    // 剪枝：剩余分数必须能用剩余深度表示
    // 最大可能和：剩余depth项都取当前最小分母 1/minDen
    // 如果 x/y > depth * (1/minDen) 则不可能
    if (x * minDen > y * depth) return false;

    bool ok = false;
    // 计算当前可选择的最小分母
    LL from = max(minDen, getMin(x, y));

    // 计算最大分母：保证即使后面所有项都和当前一样大，总和也不超过 x/y
    // 即 depth * (1/d) ≥ x/y  =>  d ≤ depth * y / x
    LL to = depth * y / x;

    for (LL i = from; i <= to; i++) {
        // 计算减去1/i后的剩余分数
        LL nx = x * i - y;
        // nx 必须非负，否则非法（理论上不会发生，因为 i >= getMin）
        if (nx < 0) continue;

        LL ny = y * i;
        LL g = gcd(nx, ny);
        nx /= g;
        ny /= g;

        path.push_back(i);
        if (dfs(depth - 1, i + 1, nx, ny)) {
            ok = true;
        }
        path.pop_back();
    }

    return ok;
}

int main() {
    cout << "请输入分子a和分母b (0 < a < b < 1000): ";
    cin >> a >> b;

    if (a <= 0 || b <= 0 || a >= b || b >= 1000) {
        cout << "输入不满足条件！" << endl;
        return 1;
    }

    // 先化简分数
    LL g = gcd(a, b);
    a /= g;
    b /= g;

    cout << "化简后: " << a << "/" << b << endl;

    found = false;
    best.clear();

    // 迭代加深搜索，深度上限设大一些（例如100）
    for (int depth = 1; depth <= 100; depth++) {
        path.clear();
        if (dfs(depth, 2, a, b)) {
            break;
        }
    }

    if (found) {
        cout << a << "/" << b << " = ";
        for (size_t i = 0; i < best.size(); i++) {
            if (i > 0) cout << " + ";
            cout << "1/" << best[i];
        }
        cout << endl;

        // 验证结果
        cout << "验证: ";
        LL sumX = 0, sumY = 1;
        for (LL den : best) {
            sumX = sumX * den + sumY;
            sumY = sumY * den;
            LL g = gcd(sumX, sumY);
            sumX /= g;
            sumY /= g;
        }
        if (sumX == a && sumY == b) {
            cout << "正确" << endl;
        } else {
            cout << "错误，计算得到: " << sumX << "/" << sumY << endl;
        }
    } else {
        cout << "在深度100内未找到解，可能需增加深度上限" << endl;
    }

    return 0;
}
