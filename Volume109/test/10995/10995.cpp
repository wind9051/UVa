#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>

using namespace std;

int timeToSec(const string& tmp) {
    int h, m, s;
    char colon;
    stringstream ss(tmp);
    ss >> h >> colon >> m >> colon >> s;
    return h * 3600 + m * 60 + s;
}

std::string secToTome(double sec) {
    int hours = static_cast<int>(sec);  // 取整數部分作為小時
    int minutes = static_cast<int>((sec - hours) * 60);  // 計算分鐘
    int seconds = static_cast<int>(((sec - hours) * 60 - minutes) * 60);  // 計算秒數

    // 格式化為 "hh:mm:ss" 的格式
    std::ostringstream timeStream;
    timeStream << std::setfill('0') << std::setw(2) << hours << ":"
               << std::setfill('0') << std::setw(2) << minutes << ":"
               << std::setfill('0') << std::setw(2) << seconds;
    
    return timeStream.str();
}

int main() {
    string line;
    while (getline(cin, line) && line != "-1") {

        stringstream ss(line);
        string tAC, tAM, tAD, tCD, tMD;
        ss >> tAC >> tAM >> tAD >> tCD >> tMD;

        int tAC_sec = timeToSec(tAC);
        int tAM_sec = timeToSec(tAM);
        int tAD_sec = timeToSec(tAD);
        int tCD_sec = timeToSec(tCD);
        int tMD_sec = timeToSec(tMD);

        //Xcd = Va (t3-t1) = Vc (t4-t1)
        //Xmd = Va (t3-t2) = Vm (t5-t2)
        //Xcm = (Va - Vm) * (t2 - t1)
        double Va = 1.0 / (tAD_sec - tAC_sec);
        double Vc = 1.0 / (tCD_sec - tAC_sec);
        double Vm = Va * (tAD_sec - tAM_sec) / (tMD_sec - tAM_sec);
        double Xam = (Va - Vm) * (tAM_sec - tAC_sec);
        int Tcm = round(Xam / (Vc - Vm) + tAC_sec);

        printf("%02d:%02d:%02d\n", Tcm/3600, Tcm%3600/60, Tcm%3600%60);
    }
    return 0;
}
