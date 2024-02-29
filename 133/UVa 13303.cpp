/*
 *
 *UVa 13303 - kewl Texting
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef map<string, int> MSI;

VI split_string(string &line, int &cnt, MSI &stoi, VS &itos) {
    VI v;
    
    v.push_back(0); //start
    
    string s;
    stringstream ss(line);
    while (ss >> s) {
        if (stoi.count(s)) v.push_back(stoi[s]);
        else {
            stoi[s] = cnt;
            itos[cnt] = s;
            v.push_back(cnt++);    
        }
    }
    
    v.push_back(1); //end
    
    return v;
}

bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b, VS &itos) {
    if (a.first == b.first) {
        if (a.second.first == b.second.first) {
            return itos[a.second.second] < itos[b.second.second];
        }
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}

int next_id(vector<pair<int, pair<int, int>>> &v, VS &itos) {
    pair<int, pair<int, int>> tmp = v[0];

    for (pair<int, pair<int, int>> &p : v) {
        if (cmp(p, tmp, itos)) tmp = p;
    }
    return tmp.second.second;
}

int main () {
    int n;
    while (cin >> n) {
        cin.ignore ();
        

        int id = 2;
        MSI stoi;
        VS itos(1e5+5);
        VI cnt(1e5+5, 0);
        map<int, map<int, int>> link;
        
        string line;
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            VI v  = split_string(line, id, stoi, itos);
            
            for (int j = 0; j < v.size(); j++) {
                cnt[v[j]]++;
                link[v[j]][v[j+1]]++;
            }
            //for (auto n : v) cout <<n<<" ";cout<<endl;
        }
        
        
        int start = 0;
        string ans = "";
        bool cycle = false;
        VI Vis(1e5+5, 0);
        while (!cycle) {
            
            Vis[start]++;
            vector<pair<int, pair<int, int>>> v;
            for (auto& p : link[start]) {
                v.push_back({p.second, {cnt[p.first], p.first}});
            }
            
            start = next_id(v, itos);
            
            if (Vis[start]) cycle = true;
            else if (start == 1) break;
            else {
                if (ans.size()) ans.push_back(' ');
                ans += itos[start];
            }
        }
        
        if (cycle) cout << "INFINITE" << endl;
        else cout << ans << endl;
    }
    return 0;
}
/*
    2 2 5 day
    1 1 9 restaurant
    1 1 15 weather
    
    1 1 5 white
    1 2 8 big   
*/
