/*
 * Problem: "UVa 10172 - The Lonesome Cargo Distributor"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬(Simulation), 資料結構(Data Structure), 堆疊(Stack), 佇列(Queue)
**/

#include <bits/stdc++.h>
using namespace std;

void print_Q(vector<queue<int>> V) {
    for (int i = 0; i < V.size(); i++) {
        printf("%d : ", i+1);
        queue<int> Q = V[i];
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            cout<<x+1<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void print_S(stack<int> S) {
    while (!S.empty()) {
            int x = S.top(); S.pop();
            cout<<x+1<<endl;
    }
    cout<<endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        stack<int> Car;
        vector<queue<int>> Station;

        int N, S, Q, Qi;
        cin >> N >> S >> Q;
        for (int i = 0; i < N; i++) {
            queue<int> Q;
            cin >> Qi;
            for (int j = 0, X; j < Qi; j++) {
                cin >> X;
                Q.push(X-1);
            }
            Station.push_back(Q);
        }
        
        bool flag = 1;
        int cur = 0, cnt = 0;
        while (flag) {
            //卸貨
            while (!Car.empty() && ((Car.top() == cur) || (Station[cur].size() < Q))) {
                int x = Car.top();
                Car.pop();
                
                if (x != cur) Station[cur].push(x);
                cnt++;
            }
            
            /*
            cout<<"Step: "<<cur+1<<" 卸貨"<<endl;
            print_S(Car);
            print_Q(Station);
            */
            
            //裝貨
            while (!Station[cur].empty() && (Car.size() < S)) {
                int x = Station[cur].front(); 
                Station[cur].pop();
                
                Car.push(x);
                cnt++;
            }
            
            /*
            cout<<"Step: "<<cur+1<<" 裝貨"<<endl;
            print_S(Car);
            print_Q(Station);
            */
            
            //判斷空
            flag = 0;
            for (int i = 0; i < N; i++) {
                if (Station[i].size()) {
                  flag = 1;
                  break;
                }
            }
            if (Car.size()) flag = 1;
            
            //移動
            if (flag) {
                cur = (cur + 1) % N;
                cnt += 2;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}