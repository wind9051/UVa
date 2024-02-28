/*
 *
 * UVa 13303 - kewl Texting
 *
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> split_string(string& line, map<string, int>& word_id, vector<string>& id_word, int& id) {
    vector<int> v;
    
    string s;
    stringstream ss(line);

    v.push_back(0);

    while (ss >> s) {
        if (word_id.count(s) == 0) {
            word_id[s] = id;
            id_word[id] = s;
            v.push_back(id++);
        } 
        else {
            v.push_back(word_id[s]);
        }
    }

    v.push_back(1);

    return v;
}

bool compare(pair<int, pair<int, pair<int, string>>>& a, pair<int, pair<int, pair<int, string>>>& b) {
    if (a.first == b.first) {
        if (a.second.first == b.second.first)
            return a.second.second.second < b.second.second.second;
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}

int next_id(vector<pair<int, pair<int, pair<int, string>>>>& v) {
    pair<int, pair<int, pair<int, string>>> t = v[0];

    for (pair<int, pair<int, pair<int, string>>>& p : v)
        if (compare(p, t)) t = p;

    return t.second.second.first;
}


int main() {
    int n, id;
    string line, s;

    while (cin >> n) {
        cin.ignore();
        map<int, map<int, int>> connections;
        map<string, int> word_id;
        vector<string> id_word(1e5+5);
        vector<int> cnt(1e5+5, 0);
        
        id = 2;
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            vector<int> v = split_string(line, word_id, id_word, id);

            cnt[1]++;

            for (int j = 0; j < v.size()-1; j++) {
                cnt[v[j]]++;
                connections[v[j]][v[j + 1]]++;
            }
            //for (auto n : v) cout <<n<<" ";cout<<endl;
        }

        int actual = 0;
        string ans = "";
        bool found_cycle = false;
        vector<int> visited(1e5 + 2, 0);
        /*
        for (auto &p : connections[4]) {
            cout<<p.second<<" "<<cnt[p.first]<<" "<<p.first<<" "<<id_word[p.first]<<endl;
            2 2 5 day
            1 1 9 restaurant
            1 1 15 weather
            
            1 1 5 white
            1 2 8 big   
        }
        cout<<endl;
    */

        while (!found_cycle) {
            //nice day 2 day
            vector<pair<int, pair<int, pair<int, string>>>> v;
            visited[actual]++;

            for (auto& p : connections[actual]) {
                // nice(3)
                v.push_back({p.second, {cnt[p.first], {p.first, id_word[p.first]}}});
            }

            actual = next_id(v);

            if (visited[actual])
                found_cycle = true;
            else if (actual == 1)
                break;
            else {
                if (ans.size()) ans.push_back(' ');
                ans += id_word[actual];
            }
        }

        if (found_cycle) cout << "INFINITE" << endl;
        else cout << ans << endl;
    }

    return 0;
}
