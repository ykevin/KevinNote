#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>

using namespace std;

void initalize_exclusion_set(set<string> &exs)
{	
	static string _excluded_words [25] = {"the", "and", "but", "that","then", "are", "been",
										  "can", "a", "could", "did", "for", "of", 
										  "had", "have", "him", "his", "her", "its", "is",
										  "were", "which", "when", "with", "would"

	};

	exs.insert(_excluded_words, _excluded_words + 25);
}

void process_file(map<string, int> &word_count, const set<string> &exclude_set, ifstream &in_file)
{
	string word;
	while(in_file >> word) {
		if(exclude_set.count(word))
			continue;
		word_count[word]++;
	}
}

void user_query(map<string, int> &word_map) 
{
	string search_word;
	cout << "Please enter a word to search: q to quit !";
	cin >> search_word;
	while(search_word.size() && search_word != "q"){
		map<string, int>::const_iterator it;
		if((it = word_map.find(search_word)) != word_map.end())
			cout << " Found! " << it->first << " occurs " << it->second << " times." << endl;
		else
			cout << search_word << "was not found!" << endl;
		cout << "\nAnother search ?(q to quit) ";
		cin >> search_word;
	}
}

void display_word_count(map<string, int>&word_map, ofstream &os)
{
	map<string, int>::const_iterator iter = word_map.begin(), end_it = word_map.end();
	while(iter != end_it){
		os << iter->first << "{" << iter->second << "}" << endl;
		++iter;
	}
	os << endl;
}

int main(void)
{
	ifstream in_file("input.txt");
	ofstream out_file("output.txt");

	if(!in_file || !out_file) {
		cerr << "unable open file!" << endl;
		return -1;
	}

	set<string> exclude_set;
	initalize_exclusion_set(exclude_set);
	
	map<string, int> word_count;
	process_file(word_count, exclude_set, in_file);
	user_query(word_count);
	display_word_count(word_count, out_file);

	return 0;
}
