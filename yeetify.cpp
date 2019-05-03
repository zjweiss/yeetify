#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//Iterates through source code and finds each unique string in file, adding it to the map.
void tokenize_file(const string &source, vector<string> &tokens){
    ifstream fin(source+".cpp");
    if(!fin.good()){
        throw source;
    }
    string token;

    //iterate until #includes or using directives are passed, since >> operator skips whitespace
    for(fin >> token; token == "#define" || token == "using"; fin >> token){
        fin.ignore(__INT_MAX__, '\n');
    }

    while(fin >> token){
        tokens.push_back(token);
    }
}

int main(int argc, char* argv[]){

    //checks inputs and gathers user intent
    if(argc != 2){
        cout << "Usage: ./yeetify.exe FILENAME_NO_EXTENSION" << endl;
        return 1;
    }


    string filename = string(argv[1]);

    vector<string> tokens;
    map<string, string> yeet_map;
    //tokenize the file
    try{
        tokenize_file(filename, tokens);
    }
    catch(string s){
        cout << "Error reading file: " << s << ".cpp" << endl;
        return 1;
    }
    //determines how many unique permutations of word will be needed
    int num_yeets = tokens.size();
    cout << num_yeets << endl;
}