/*
 * caesar-decode-helper - Timon Esser
 * -> hilfsprogramm zur entschlüsselung der caesar-verschlüsselung
 * -> gibt alle möglichen decodierten wörter aus
 * -> ermittelt die wahrscheinlichkeit der ergebnisse mittels dictionary vergleichs
 * */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string input, currC, tmpstring;
int ilength;
string abc = "abcdefghijklmnopqrstuvwxyz";

int findme (string);
int main(int argc, char **argv)
{
    
    cout << "Geben sie die caesar verschluesselte Zeichenkette ein: ";
    cin >> input;
    ilength = input.length();
    cout << "\n Folgende Wortkombinationen sind moeglich: \n" << endl;
    for (int h=0; h<=25; h++){
        
        tmpstring = "";
        for (int i=0; i<ilength;i++){
            size_t found = abc.find(input[i]);
            currC = abc[found];
            found = (found + h) % 26;
            tmpstring = tmpstring + abc [found];
            
         }
        
        cout << tmpstring << "\t Verschiebewert: " << h << "\t Wahrscheinlichkeit: " << findme(tmpstring) <<endl;
    }
    cout << endl;
    return 0;
}

int findme (string input) {
    string cLine;
    int founds =0;
    ifstream MyReadFile("ddictionary.txt");
    
    while (getline (MyReadFile, cLine)) {
  // Output the text from the file
        if (input.find(cLine) != string::npos) {
        founds++;
    } 
}

MyReadFile.close();
return founds;
}
