#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

//gets name of file from string and returns it
string get_filename(string filepath) {
	//returns everything starting from the last "."
	return filepath.substr(0, filepath.find_last_of("."));
}

//gets extension of file from string and returns it
string get_extension(string filepath) {
	//returns everything starting from the last "."
	return filepath.substr(filepath.find_last_of("."));
}

//Iterates through source code and finds each unique string in file, adding it to the map.
void tokenize_file(const string& source, set<string>& tokens) {
	ifstream fin(source);
	if (!fin.good()) {
		throw source;
	}
	string token;

	//iterate until #includes or using directives are passed, since >> operator skips whitespace
	for (fin >> token; token == "#define" || token == "#include" || token == "using"; fin >> token) {
		fin.ignore(__INT_MAX__, '\n');
	}

	while (fin >> token) {
		tokens.insert(token);
	}
}

//Generates required number of permutations of the word 'yeet'
set<string> generate_yeets(int num_yeets) {
	//we are using std::set because they ensure that words won't be repeated
	set<string> yeets;
	while (yeets.size() < num_yeets) {
		string s = "y";
		int rand_length = rand() % ((int)log2(num_yeets)) + 1;
		int t_count = rand() % (rand_length);
		int e_count = rand_length - t_count;
		//generates unique string and adds to set
		for (int i = 0; i < e_count; ++i) {
			if (rand() % 2 == 1) s += "e";
			else s += "E";
		}
		for (int i = 0; i < t_count; ++i) {
			if (rand() % 2 == 1) s += "t";
			else s += "T";
		}
		yeets.insert(s);
	}
	return yeets;
}

void yeetify_file(const string& source, map<string, string>& map) {
	//create ifstream and ofstrea
	ifstream fin;
	fin.open(source);
	ofstream fout;
	fout.open(get_filename(source) + "_yeetified" + get_extension(source));

	//keep any skipped lines identical to the way they were before
	string token;
	for (fin >> token; token == "#define" || token == "#include" || token == "using"; fin >> token) {
		string rest_of_line;
		getline(fin, rest_of_line);
		fout << token << " " << rest_of_line << endl;
	}
	fout << endl;

	//now that we're below any directives, create #define mapping from yeets to tokens so the code can actually compile
	for (auto pair : map) {
		//in reverse order since we want to go from yeet to token during compilation
		fout << "#define " << pair.second << " " << pair.first << endl;
	}
	fout << endl;

	//now that the #define exists, convert each token and put it in exactly the same place in the output file
	string line;
	while (getline(fin, line)) {
		stringstream line_stream(line);
		string text;
		while (line_stream >> text) {
			fout << map[text] << " ";
		}
		fout << endl; //allows line breaks to be maintained
	}
}

int main(int argc, char* argv[]) {
	//checks inputs and gathers user intent
	if (argc != 2) {
		cout << "Need exactly 1 argument to yeetify command" << endl;
		cout << "Usage: " << argv[0] << " FILENAME" << endl;
		return 1;
	}

	if (get_extension(argv[1]) != ".cpp" && get_extension(argv[1]) != ".c" && get_extension(argv[1]) != ".cc") {
		cout << "Invalid file extension " << get_extension(argv[1]) << endl;
		cout << "Usage: " << argv[0] << " FILENAME" << endl;
		return 1;
	}

	string path = string(argv[1]);
	set<string> tokens;
	//tokenize the file
	try {
		tokenize_file(path, tokens);
	}
	catch (string invalid_file_path) {
		cout << "Error reading file: " << invalid_file_path << endl;
		return 1;
	}

	//determines how many unique permutations of word will be needed
	int num_yeets = tokens.size();

	//gets generated words from generator function
	set<string> yeets = generate_yeets(num_yeets);

	//create map from token to word using iterators over each set
	map<string, string> yeet_map;
	int size = tokens.size(); //since we know that yeets and tokens must have same size
	auto token = tokens.begin();
	auto yeet = yeets.begin();
	for (int i = 0; i < size; ++i) { //run loop for each element in the tokens set
		yeet_map[*token] = *yeet;
		++token;
		++yeet;
	}

	//now that we have map, we can finally convert each token to its 'yeet' counterpart
	yeetify_file(path, yeet_map);
}