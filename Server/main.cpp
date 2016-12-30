#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

typedef struct{
	string word;
	int count;
}w_data;

vector<string> explode(string str, const char& ch);
void print_s_vector(vector <string> str_vec);
bool compareByLength(const w_data &a, const w_data &b);

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
	
	//print_s_vector(words);
	//print_s_vector(sentances);	
	cout << "Word Occurances" << endl;
	vector<w_data> word_occurances;
	for (int i = 0;i < words.size();i++){
		if(word_occurances.size() == 0){
			w_data w;
			w.count = 0;
			w.word = words[0];
			word_occurances.push_back(w);
		}
		int count = 0;
		for( int j = 0;j < word_occurances.size();j++){
			cout << "comparing word " << word_occurances[j].word <<endl;
			if (word_occurances[j].word == words[i]){
				word_occurances[j].count++;
				count++;
			}
		}
		if(count == 0){
			w_data w;
			w.count = 0;
			w.word = words[i];
			word_occurances.push_back(w);
		}
	}

	for (int i = 0;i < word_occurances.size();i++){
		if (word_occurances[i].word == "a" ||word_occurances[i].word == "the" ||word_occurances[i].word == "an" || word_occurances[i].word == "is")
			word_occurances.erase(word_occurances.begin() + 1);
	}

	print_s_vector(sentances);
	sort(word_occurances.begin(), word_occurances.end(), compareByLength);
	cout << "scoring" << endl;
	vector<int> scores;
	for (int i = 0;i < sentances.size();i++){
		string s = sentances[i];
		int count = 0;
		for (int j = 0;j < 3;j++){
			size_t nPos = s.find(word_occurances[j].word, 0); // fist occurrence
			while(nPos != string::npos)
   			{
        			count++;
        			nPos = s.find(word_occurances[j].word, nPos+1);
			}
		}	
		scores.push_back(count);
	}	cout << "Final Sentances" <<endl;
	vector<string> final_sentances;
	for(auto i: scores){
		cout << i <<endl;
	}
	for (int k = 0;k < 3;k++){
		auto largest  = max_element(begin(scores),end(scores));
		int index = distance(begin(scores),largest);
       		final_sentances.push_back(sentances[index]);	
		sentances.erase(sentances.begin()+index);
		//scores.erase(scores.begin(),+index);
	}
	cout << final_sentances.size() << endl;
	print_s_vector(final_sentances);
	fstream o_file("/Library/WebServer/Documents/output.txt");
	if (o_file.is_open()){
		cout << "Opened output.txt" <<endl;
	}else{
		cout << "Unable to open output.txt" << endl;
	}
//	o_file << "humpty dumps" <<endl;
	o_file << final_sentances[0] <<endl;
	o_file << final_sentances[1] <<endl;
	o_file << final_sentances[2] <<endl;
	o_file.close();

	cout << "Finished" <<endl;
	return 0;
}

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

void print_s_vector(vector <string> str_vec){
	for (auto i:str_vec){
		cout << i << endl;
	}
}

bool compareByLength(const w_data &a, const w_data &b)
{
    return a.count < b.count;
}
