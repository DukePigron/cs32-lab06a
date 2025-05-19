// WordCount.cpp

#include "WordCount.h"
#include <cctype>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int count = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		if(!table[i].empty()){
			for(size_t j = 0; j < table[i].size(); j++)
				count+=table[i].at(j).second;
		}
	}
	return count;
}

int WordCount::getNumUniqueWords() const {
	int count = 0;
	std::vector<std::string> words;

	for(size_t i = 0; i < CAPACITY; i++){
		if(!table[i].empty()){
			count+=table[i].size();
		}
	}
	return count;
}

int WordCount::getWordCount(std::string word) const {
	word = makeValidWord(word);
	size_t h = hash(word);

	if(table[h].empty())
		return 0;

	int count = 0;
	for(size_t i = 0; i < table[h].size(); i++){
		if(table[h].at(i).first == word)
			count = table[h].at(i).second;
	}

	return count;
}
	
int WordCount::incrWordCount(std::string word) {
	word = makeValidWord(word);
	size_t h = hash(word);

	for(size_t i = 0; i < table[h].size(); i++){
		if(table[h].at(i).first == word){
			table[h].at(i).second++;
			return table[h].at(i).second;
		}
	}

	std::pair<std::string, int> p(word, 1);
	table[h].push_back(p);

	return 1;
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
	size_t h = hash(word);

	for(size_t i = 0; i < table[h].size(); i++){
		if(table[h].at(i).first == word){
			table[h].at(i).second--;
			int value = table[h].at(i).second;

			if(value == 0)
				table[h].erase(table[h].begin() + i);

			return value;
		}
	}

	return -1;
}

bool WordCount::isWordChar(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

std::string WordCount::makeValidWord(std::string word) {
	for(size_t i = 0; i < word.length(); i++){
		char c = word[i];
		if(!isWordChar(c) && !(i != 0 && i != word.length()-1 && (c == '\'' || c == '-'))){
			word.erase(i, 1);
			i--;
		}
	}

	while(word[0] == '\'' || word[0] == '-')
		word.erase(0, 1);
	
	while(word[word.length()-1] == '\'' || word[word.length()-1] == '-')
		word.erase(word.length()-1, 1);

	for(char &c : word)
		c = std::tolower(c);

	return word;
}
