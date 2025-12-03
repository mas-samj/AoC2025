#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ifstream MyInputFile("input.txt");

    int dialPos = 0;

    int numZeros = 0;
    
    string line;
    while(getline(MyInputFile, line))
    {
        char direction;
        int notch;

        int prevPos = dialPos;

        direction = line.substr(0, 1).c_str()[0];
        notch = stoi(line.substr(1));

        if(direction == 'R') {
            dialPos = (prevPos + notch >= 100) ? (prevPos + notch) - 100 : prevPos + notch;
        }
        else {
            dialPos = (prevPos - notch < 0) ? (prevPos - notch) + 100 : prevPos - notch;
        }

        if (dialPos == 0)
        {
            numZeros++;
        }

        cout << "prev pos: " << prevPos << " dir: " << direction << " notchs: " << notch << " new pos: " << dialPos << endl;
    } 
    cout << numZeros << endl;
}