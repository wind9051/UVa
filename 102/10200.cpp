/*
 * Title:  "UVa10200 - prime time"
 * Author: "Jia_coding"
 * Date:   "2024/08/15"
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
vector<bool> Num(10005, 1);
void init() 
{
    for (int i = 2; i*i <= 10000; i++) 
    {
        if (Num[i]) 
        {
            prime.push_back(i);
            for (int j = i+i; j <= 10000; j+=i) 
            {
                Num[j] = 0;
            }
        }
    }    
}

vector<bool> primecnt(10005, 0);
void preprocess() 
{
    for (int i = 0; i <= 10000; i++) 
    {
        int num = i*i + i + 41;
        for (int j = 0; j < prime.size() && prime[j] * prime[j] <= num; j++) 
        {
            if (num % prime[j] == 0) 
            {
                primecnt[i] = 1;
                break;
            }    
        }
    }
}

int main() 
{
    init();
    preprocess();
    
    int a, b;
    while (cin >> a >> b) 
    {
        int cnt = 0;
        for (int i = a; i <= b; i++) 
        {
            if (primecnt[i]) cnt++;
        }
        printf("%.2f\n", 100 - float(cnt) / float(b-a+1) * 100);
    }
    
    return 0;
}
