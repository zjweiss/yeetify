#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

//Iterates through source code and finds each unique string in file, adding it to the map.
void tokenize_file(const string &source, set<string> &tokens){
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
        tokens.insert(token);
    }
}

//Generates required number of permutations of the word 'yeet' 
set<string> generate_yeets(int num_yeets){
    //we are using std::set because they ensure that words won't be repeated
    set<string> yeets;
    while(yeets.size() < num_yeets){
        string s = "y";
        int e_count = rand() % (num_yeets / 2);
        int t_count = (num_yeets / 2) - e_count;
        //generates unique string and adds to set
        for(int i = 0; i < e_count; ++i){
            if(rand() % 2 == 1) s += "e";
            else s += "E";
        }
        for(int i = 0; i < t_count; ++i){
            if(rand() % 2 == 1) s += "t";
            else s+= "T";        
        }
        yeets.insert(s);
        cout << s << endl;
    }
    return yeets;
}

int main(int argc, char* argv[]){

    //checks inputs and gathers user intent
    if(argc != 2){
        cout << "Usage: ./yeetify.exe FILENAME_NO_EXTENSION" << endl;
        return 1;
    }


    string filename = string(argv[1]);

    set<string> tokens;
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
    int num_yeets = tokens.size(); //since capitalization
    cout << num_yeets << endl;

    set<string> yeets = generate_yeets(num_yeets);
}