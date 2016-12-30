#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

vector<string> explode(string str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}

int main(){

	ifstream file("/Library/WebServer/Documents/test.txt");
        if(file.is_open()){
                cout << "test.txt opened" << endl;
        }else{
                cout << "test.txt doesn't open" << endl;
        }
        vector<string> words;
        vector<string> sentances;

        string full_appended;
        string line;
        if (file.is_open())
        {
                 while ( getline (file,line) )
                {
                        full_appended += line;
                }
                file.close();
        }

       words = explode(full_appended,' ');
       sentances = explode(full_appended,'.');
       
       int numwords_single = 0;
       for (auto i: words){
		if (i.length() == 1)
			numwords_single++;
	}
	
	ofstream o_file("/Library/WebServer/Documents/tutor_results.txt");
        if(o_file.is_open()){
                cout << "tutor_results.txt opened" << endl;
        }else{
                cout << "tutor_results.txt doesn't open" << endl;
        }

	if (words.size()/numwords_single > 4){	
		o_file << "Need to Improve Handwriting" << endl;
	}else if(words.size()/numwords_single > 5){
		o_file << "Can Improve Handwriting" <<endl;
	}
	
	for (int i = 0;i < 9;i++){
		
	}
		



	
	return 0;
}

