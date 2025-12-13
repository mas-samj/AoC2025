#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> stringParser(string line, char delimiter)
{
    vector<string> ranges;

    int charcount = line.length();
    int prevIndex = charcount - 1;

    for(int i = charcount - 1; i >= 0; i--)
    {
        if (line[i] == delimiter) {
            string range = line.substr(i + 1, prevIndex - i);

            if (range[range.length() - 1] == ',') {
                range = range.substr(0 , range.length() - 1);
            }

            ranges.push_back(range);
            prevIndex = i;
        }
        else if (i == 0) {
            ranges.push_back(line.substr(0, prevIndex));
        }
    }
    return ranges;
}

bool checkForPatterns(string lower, string upper)
{
    return false;
}

int main(){

    ifstream MyInputFile("input.txt");

    vector<string> ranges;

    string line;
    while(getline(MyInputFile, line)) {
       ranges = stringParser(line, ',');
    } 
    for (int i = 0; i < ranges.size(); i++)
    {
        string range = ranges[i];
        vector<string> splitRange = stringParser(range, '-');

        // int lowerBound;
        // int upperBound;
        // if (splitRange.size() >= 2)
        // {
        //     lowerBound = stoi(splitRange[1]);
        //     upperBound = stoi(splitRange[0]);
        // }
    }  
}
