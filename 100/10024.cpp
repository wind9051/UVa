//UVA10024 Curling up the cube
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(6, vector<int>(6, 0));

char kind[11][4][6] = { {"10000","11110","10000"},
                        {"10000","11110","01000"},
                        {"10000","11110","00100"},
                        {"10000","11110","00010"},
                        {"01000","11110","01000"},
                        {"01000","11110","00100"},
                        {"11000","01110","01000"},
                        {"11000","01110","00100"},
                        {"11000","01110","00010"},
                        {"11000","01100","00110"},
                        {"11100","00111","00000"}};

void rotate() 
{
    vector<vector<int>> tmp(6, vector<int>(6, 0));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tmp[i][j] = G[5-j][i];
        }
    }
    G = tmp;
}

void upturn() 
{
    vector<vector<int>> tmp(6, vector<int>(6, 0));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tmp[i][j] = G[i][5-j];
        }
    }
    G = tmp;
}

int check() 
{
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 6; j++) 
        {
            
            for (int r = 0; r < 11; r++) 
            {
                bool flag = 1;
                int cnt = 1, p;
                for (p = 0; p < 3 && flag; p++)
                {
                    for (int q = 0; q < 5 && flag; q++) 
                    {
                        if(kind[r][p][q] == '0') continue;
                        if (i+p >= 6 || j+q >= 6 || G[i+p][j+q] != (kind[r][p][q]-'0')) 
                        {
                            //p = 10, q = 10;
                            //cout<<i<<" "<<p <<" "<<j<<" "<<q<<" "<<r<<endl;
                            //cout<<G[i+p][j+q] <<" -> "<< kind[r][p][q]-'0'<<endl;
                            flag = 0;
                        }
                        cnt++;
                    }
                }
                
                //if (p == 3) return 1;
                if (flag) return 1;
            }
        }
    }
    return 0;
}

bool find_grpah() 
{
    for (int i = 1; i <= 2; i++) 
    {
        for (int j = 1; j <= 4; j++) 
        {
            if (check()) return 1;
            rotate();
        }
        upturn();
    }
    return 0;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cin >> G[i][j];
            }
        }
            
        if (find_grpah()) printf("correct\n");
        else printf("incorrect\n");
        
        if (t) printf("\n");
    }
    return 0;
}
