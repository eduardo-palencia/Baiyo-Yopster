#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char symbols[] = {'(', ')', '_', '.'};
char operators[] = {'+', '-', '/', '*', 'E'};
char numbers[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

string readFile() {

    string tempLine, str;

    fstream file;
    file.open("xd.txt");

    while (getline(file, tempLine))
        str.append(tempLine + "\n");
        
    return str;
}

void regex(string str) {

    int count = 0;
    char tempChar;
    string tempStr;
    vector<string> commentList;
    vector<char> operatorList;


    for(int i = 0; str.length() > i; i++) {

        //tempChar = str[i];
        //cout << tempChar;

      

      if(str[i] == '/') {

           if (str[i+1] == '/') {
            
                count = 0;

               while (str[i + count] != '\n') {
                   tempStr.push_back(str[i + count]);
                   count++;
               }
               commentList.push_back(tempStr);
           } 
           else {
               operatorList.push_back(str[i]);
           }
        }
    }

    for(int i = 0; i < commentList.size(); i++)
        cout << commentList[i] << endl;

    for(int i = 0; i < operatorList.size(); i++)
        cout << operatorList[i] << endl;

}

int main() {

    regex(readFile());

}