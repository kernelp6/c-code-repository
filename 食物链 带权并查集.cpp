#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 50010;

int parent[MAXN];    // 存储父节点
int relation[MAXN];  // 存储与根节点的关系：0-同类，1-吃根，2-被根吃

// 初始化
void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        relation[i] = 0;
    }
}

// 查找根节点，带路径压缩
int find(int x) {
    if (parent[x] != x) {
        int temp = parent[x];  // 记录原来的父节点
        parent[x] = find(parent[x]);  // 递归查找，路径压缩
        // 更新与新的根节点的关系
        // 原来的关系是对temp的，现在temp的关系已经更新为对根节点的
        // 所以x对根的关系 = (x对temp的关系 + temp对根的关系) % 3
        relation[x] = (relation[x] + relation[temp]) % 3;
    }
    return parent[x];
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    init(n);
    
    int false_count = 0;
    
    while (k--) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        
        // 条件2：X或Y比N大
        if (x > n || y > n) {
            false_count++;
            continue;
        }
        
        // 条件3：X吃X
        if (d == 2 && x == y) {
            false_count++;
            continue;
        }
        
        int fx = find(x);
        int fy = find(y);
        
        if (fx == fy) {
            // 已经在同一集合中，可以判断真假
            if (d == 1) {
                // 说X和Y是同类，需要验证relation[x] == relation[y]
                if (relation[x] != relation[y]) {
                    false_count++;
                }
            } else { // d == 2
                // 说X吃Y，需要验证 (relation[x] - relation[y] + 3) % 3 == 1
                if ((relation[x] - relation[y] +3) % 3 != 1) {
                    false_count++;
                }
            }
        } else {
            // 不在同一集合中，合并，这句话是真话
            parent[fx] = fy;
            // 设置relation[fx]的值
            // 推导：x -> fx 的关系是 relation[x]
            //       y -> fy 的关系是 relation[y]
            //       我们希望 x -> y 的关系是 (d-1) [0表示同类，1表示x吃y]
            // 公式：relation[fx] = ((d-1) + 3 - relation[x] + relation[y]) % 3
            relation[fx] = ((d - 1) + 3 - relation[x] + relation[y]) % 3;
        }
    }
    
    printf("%d\n", false_count);
    
    return 0;
}
