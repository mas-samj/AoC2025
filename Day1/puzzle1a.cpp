#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct Comb
{
    char dir;
    int notchs;
};

int main(){
    ifstream MyInputFile("input.txt");

    int inputArray[4762];
    
    int i = 0;
    string line;
    while(getline(MyInputFile, line))
    {
        string direction;
        int notch;

        direction = line.substr(0, 1);
        notch = stoi(line.substr(1));
        i++;
    }

    cout << i << endl;

    int pointer = 0;


}