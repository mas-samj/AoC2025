#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int posCalc(int result, bool dir, bool first, int& zeroPasses)
{
    if (dir == false) {  //right
        if (result > 99)
        {
            zeroPasses++;
            return posCalc(result - 100, false, false, zeroPasses);
        }
        else {
            return result;
        }    
    }
    if (dir == true) {  //left
        
        if (result < -100)
        {
            zeroPasses++;
            return posCalc(result + 100, true, false, zeroPasses);
        }
        else if (result < 0 && result > -100 && !first)
        {
            zeroPasses++;
            return result;
        }
        else if (result < 0 && result > -100 && first)
        {
            return result;
        }
        else {
            return result;
        }
    }
    return 0;
}

int main(){
    // ifstream MyInputFile("sample.txt");
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

        direction = line[0];
        notch = stoi(line.substr(1));


        if(direction == 'R') { //right
            if (prevPos + notch == 100) {
                dialPos = 0;
            }
            else {
                dialPos = (prevPos + notch > 99 ) ? posCalc(prevPos + notch, false, true, numPassZero) : prevPos + notch;
            }
            
        }
        else { //left
            if (prevPos - notch == -100)
                dialPos = 0;
            else {
                dialPos = (prevPos - notch < 0) ? posCalc(prevPos - notch, true, true,  numPassZero) : prevPos - notch;
                if (dialPos < 0)
                    dialPos += 100;
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
