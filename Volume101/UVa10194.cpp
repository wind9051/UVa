/*
 * Problem: "UVa 10194 - Football (aka Soccer)"
 *  Author: "Jia_coding"
 * 
 *     Tag: 結構(Struct), 排序(Sort - cmp)
**/

#include <bits/stdc++.h>
using namespace std;

string tourName;

int N, G;

map<string, int> Hash;

struct Team {
    string name;
    int Win, Tie, Loss, All; //勝場, 平手, 輸場, 總場
    int PS, PL; //得分 失分
    int diff, Score; //淨勝, 積分

    Team() {
        name = "";
        Win = Tie = Loss = All = 0;
        PS = PL = 0;
        diff = Score = 0;
    }
};

bool cmp(Team & A, Team & B) {
    if (A.Score != B.Score) return A.Score > B.Score;
    if (A.Win != B.Win) return A.Win > B.Win;
    if (A.diff != B.diff) return A.diff > B.diff;
    if (A.PS != B.PS) return A.PS > B.PS;
    if (A.All != B.All) return A.All < B.All;

    string sA(A.name), sB(B.name);
    for (char & ch : sA) ch = tolower(ch);
    for (char & ch : sB) ch = tolower(ch);
    return sA < sB;
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        getline(cin, tourName);

        scanf("%d\n", &N);
        vector<Team> team(N);
        for (int i = 0; i < N; i++) {
            getline(cin, team[i].name);
            Hash[team[i].name] = i;
        }

        scanf("%d\n", &G);
        int g1, g2;
        string t1, t2, id1, id2;
        for (int i = 0; i < G; i++) {
            getline(cin, t1, '#');
            scanf("%d@%d#", &g1, &g2);
            getline(cin, t2);

            Team & A = team[Hash[t1]];
            Team & B = team[Hash[t2]];
            
            A.PS += g1; A.PL += g2;
            B.PS += g2; B.PL += g1;

            if (g1 == g2) { A.Tie++; B.Tie++; }
            else if (g1 < g2) { A.Loss++; B.Win++; }
            else { A.Win++; B.Loss++; }
        }

        for (int i = 0; i < N; i++) {
            Team & A = team[i];
            A.Score = 3 * A.Win + A.Tie;
            A.diff = A.PS - A.PL;
            A.All = A.Win + A.Tie + A.Loss;
        }
        
        sort(team.begin(), team.end(), cmp);
        
        printf("%s\n", tourName.c_str());
        for (int i = 0; i < N; i++) {
            Team & A = team[i];
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, A.name.c_str(), A.Score, A.All, A.Win, A.Tie, A.Loss, A.diff, A.PS, A.PL);
        }
        if (t) printf("\n");
    }
    return 0;
}