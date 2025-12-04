#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int posCalc(int result, bool dir, int& zeroPasses)
{
    if (dir == false) {  //right
        if (result > 99)
        {
            zeroPasses++;
            return posCalc(result - 100, false, zeroPasses);
        }
        else {
            return result;
        }    
    }
    if (dir == true) {  //left
        if (result < 0)
        {
            zeroPasses++;
            return posCalc(result + 100, true, zeroPasses);
        }
        else {
            return result;
        }
    }
    return 0;
}

int main(){
    ifstream MyInputFile("input.txt");

    int dialPos = 50;

    int numPassZero = 0;
    int zeroCount = 0;
    
    string line;
    while(getline(MyInputFile, line))
    {
        char direction;
        int notch;

        int prevPos = dialPos;

        direction = line.substr(0, 1).c_str()[0];
        notch = stoi(line.substr(1));


        if(direction == 'R') { //right
            if (prevPos + notch == 100) {
                dialPos = 0;
            }
            // else if (prevPos == 0 && notch < 100)
            //     dialPos = prevPos + notch;
            // else if ((prevPos + notch) < 200 && (prevPos + notch) > 100) {
            //     numPassZero++;
            //     dialPos = (prevPos + notch) - 100;
            // }
            else {
                dialPos = (prevPos + notch > 99 ) ? posCalc(prevPos + notch, false, numPassZero) : prevPos + notch;
            }
            
        }
        else { //left
            if (prevPos - notch == -100)
                dialPos = 0;
            // else if (prevPos == 0 && notch < 100) {
            //     dialPos = prevPos - notch + 100;
            // }
            // else if ((prevPos - notch > -100) && (prevPos - notch < 0))
            // {
            //     numPassZero++;
            //     dialPos = (prevPos - notch) + 100;
            // }
            else {
                dialPos = (prevPos - notch < 0 && prevPos - notch < -99) ? posCalc(prevPos - notch, true, numPassZero) : prevPos - notch + 100;
            }
            
        }

        if (dialPos == 0)
        {
            zeroCount++;
            numPassZero++;
        }
        cout << "prev pos: " << prevPos << " dir: " << direction << " notchs: " << notch << " new pos: " << dialPos << " zero passes: " << numPassZero<< endl;
    }
 
    cout << " zero passes: " << numPassZero << endl;
    cout << " zero count: " << zeroCount << endl;
}