#include <iostream>
 
using namespace std;
 
int main() {
 
    string line;
    
    while(cin >> line){
        int parem = 0;
        int correct = true;
        
        for (char c : line){
            if (c == '('){
                parem++;
            }else if (c == ')'){
                parem--;
            }
            if (parem < 0){
                correct = false;
            }
        }
        if (parem == 0 and correct){
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }
 
    return 0;
}