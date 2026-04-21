/*
 * Problem: "UVa 12100 - Printer Queue"
 *  Author: "Jia_coding"
 * 
 *     Tag: Queue, 優先佇列
**/

#include<bits/stdc++.h>
using namespace std;

struct node {
    int k, idx;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        queue<node> q;
        priority_queue<int> pq;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            q.push({x, i});
            pq.push(x);
        }

        int sum = 0;
        while (!pq.empty()) {
            int maxk = pq.top(); pq.pop();
            while(q.front().k != maxk)  {
                node cur = q.front();
                q.pop(),q.push(cur);
            }

            node printed = q.front(); q.pop();
            
            sum++;
            if (printed.idx == m) {
                printf("%d\n", sum);
                break;
            }
        }
    }
    return 0;
}
