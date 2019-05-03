#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//Iterates through source code and finds each unique string in file, adding it to the map.
void tokenize_file(const string &source, vector<string> &tokens){
    ifstream fin(source+".cpp");
    string token;
    while(fin >> token){
        tokens.push_back(token);
    }
}

int main(int argc, char* argv[]){

    //checks inputs and gathers user intent
    if(argc != 2){
        cout << "Usage: ./yeetify.exe FILENAME_NO_EXTENSION" << endl;
    }
    string filename = string(argv[1]);

    vector<string> tokens;
    map<string, string> yeet_map;
    //tokenize the file
    tokenize_file(filename, tokens);

    int num_yeets = tokens.size();
    cout << num_yeets << endl;
}