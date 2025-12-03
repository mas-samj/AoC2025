#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int posCalc(int result, bool dir)
{
    if (dir == false) {  //right
        if ((result - 100) > 99)
            return posCalc(result - 100, false);
        else
            return result - 100;
    }
    if (dir == true) {  //left
        if ((result + 100) < 0)
            return posCalc(result + 100, true);
        else
            return result + 100;
    }
    return 0;
}

int main(){
    ifstream MyInputFile("sample.txt");

    uint dialPos = 50;

    ushort numZeros = 0;
    
    string line;
    while(getline(MyInputFile, line))
    {
        char direction;
        int notch;

        int prevPos = dialPos;

        direction = line.substr(0, 1).c_str()[0];
        notch = stoi(line.substr(1));

        if(direction == 'R') { //right
            dialPos = (prevPos + notch >= 100) ? posCalc(prevPos + notch, false) : prevPos + notch;
        }
        else { //left
            dialPos = (prevPos - notch < 0) ? posCalc(prevPos - notch, true) : prevPos - notch;
        }

        if (dialPos == 0)
        {
            numZeros++;
        }
        // cout << "prev pos: " << prevPos << " dir: " << direction << " notchs: " << notch << " new pos: " << dialPos << endl;
    } 
    cout << numZeros << endl;
}