/*
 * Problem: "UVa 397 - Equation Elation"
 *  Author: "Jia_coding"
 * 
 *     Tag: 多項式
**/

#include <bits/stdc++.h>
using namespace std;

bool isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool calcMulDiv(vector<int> &num, vector<char> &op) {
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == '*' || op[i] == '/') {
            int a = num[i];
            int b = num[i+1];
            int res = (op[i] == '*') ? a * b : a / b;
            num[i] = res;
            num.erase(num.begin() + i + 1);
            op.erase(op.begin() + i);
            return true;
        }
    }
    return false;
}

bool calcAddSub(vector<int> &num, vector<char> &op) {
    if (op.empty()) return false;
    int a = num[0];
    int b = num[1];
    char c = op[0];
    int res = (c == '+') ? a + b : a - b;
    num[0] = res;
    num.erase(num.begin() + 1);
    op.erase(op.begin());
    return true;
}

string buildExpr(vector<int> &num, vector<char> &op, const string &var) {
    stringstream ss;
    ss << num[0];
    for (int i = 0; i < op.size(); i++) {
        ss << " " << op[i] << " " << num[i+1];
    }
    ss << " = " << var;
    return ss.str();
}

int main() {
    int space = 0;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        if (space++) cout << endl;
        
        string s = "";
        for (auto c : line) if (c != ' ') s += c;


        // 拆數字、運算符、變數
        vector<int> num;
        vector<char> op;
        string var = "";
        int sign = 1, n = 0;
        bool readingNum = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '=') {
                if (readingNum) {
                    num.push_back(sign*n);
                }
                var = s.substr(i+1);
                break;
            }
            
            if (isOp(s[i])) {
                if (readingNum) {
                    num.push_back(sign*n);
                    n = 0;
                    sign = 1;
                    readingNum = false;
                }
                if ((i == 0 || isOp(s[i-1])) && (s[i] == '+' || s[i] == '-')) {
                    sign = (s[i] == '+') ? 1 : -1;
                    continue;
                }
                op.push_back(s[i]);
            } 
            else if (isdigit(s[i])) {
                n = n*10 + (s[i]-'0');
                readingNum = true;
            }
        }
        if (readingNum) num.push_back(sign*n);

        vector<int> numCopy = num;
        vector<char> opCopy = op;
        cout << buildExpr(numCopy, opCopy, var) << endl;
        while (!opCopy.empty()) {
            if (!calcMulDiv(numCopy, opCopy)) {
                calcAddSub(numCopy, opCopy);
            }
            cout << buildExpr(numCopy, opCopy, var) << endl;
        }
    }
    return 0;
}
