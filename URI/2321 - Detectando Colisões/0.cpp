#include <bits/stdc++.h>

using namespace std;

// Funcao que procura na palavra, determinada letra
bool check_point(int px, int py, int rect[4]){
    int rx1 = rect[0], ry1 = rect[1], rx2 = rect[2], ry2 = rect[3];

    if (rx1 <= px && px <= rx2){
        if (ry1 <= py && py <= ry2){
            return true;
        }
    }
    return false;
}

int main(){
    int rect1[4];
    int rect2[4];

    for (int i = 0 ; i < 4; ++i)
        cin >> rect1[i];

    for (int i = 0 ; i < 4; ++i)
        cin >> rect2[i];

    for (int i = rect1[0]; i < rect1[2]; ++i){
        if (check_point(i, rect1[1], rect2) || check_point(i, rect1[3], rect2)){
            cout << 1 << endl;
            return 0;
        }
    }

    for (int i = rect1[1]; i < rect1[3]; ++i){
        if (check_point(i, rect1[0], rect2) || check_point(i, rect1[2], rect2)){
            cout << 1 << endl;
            return 0;
        }
    }

    for (int i = rect2[0]; i < rect2[2]; ++i){
        if (check_point(i, rect2[1], rect1) || check_point(i, rect2[3], rect1)){
            cout << 1 << endl;
            return 0;
        }
    }

    for (int i = rect2[1]; i < rect2[3]; ++i){
        if (check_point(i, rect2[0], rect1) || check_point(i, rect2[2], rect1)){
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}