#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ifstream MyInputFile("input.txt");

    int dialPos = 50;

    int numZeros = 0;
    
    string line;
    while(getline(MyInputFile, line))
    {
        char direction;
        int notch;

        direction = line[0];
        notch = stoi(line.substr(1));


        int n = 0;
        while (n < notch) {
            if (direction == 'R')
                dialPos++;
            if (direction == 'L')
                dialPos--;
            if (dialPos == 100) {
                dialPos = 0;
            }
            if (dialPos == -1) {
                dialPos = 99;
            }
            if (dialPos == 0) {
                numZeros++;
            }
            n++;
        }
    } 
    cout << numZeros << endl;
}
