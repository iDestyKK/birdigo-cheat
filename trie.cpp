#include "trie.hpp"

trie::trie() {
	final_letter = false;
}

trie::trie(char *filename) {
	final_letter = false;
	open(filename);
}

bool trie::open(char *filename) {
	ifstream fp;
	string line;

	// Clear dictionary first
	clear();

	// Open file
	fp.open(filename);
	while (getline(fp, line)) {
		insert(line.c_str());
	}
	fp.close();

	return true;
}

void trie::clear() {
	map<char, trie>::iterator ii;

	// Recursively clear
	for (ii = letters.begin(); ii != letters.end(); ii++) {
		ii->second.clear();
	}

	// Remove all letters in the dictionary
	letters.clear();
}

void trie::insert(const char *str) {
	map<char, trie>::iterator ii;
	char l;

	l = tolower(str[0]);
	ii = letters.find(l);

	if (ii == letters.end())
		letters.insert(make_pair(l, trie()));


	if (str[1] == 0) {
		// Mark as final letter in a word
		letters[l].final_letter = true;
	}
	else {
		// Continue recursion only if not last letter
		letters[l].insert(&(str[1]));
	}
}

bool trie::is_valid(const char *str) {
	map<char, trie>::iterator ii;
	char l;

	l = tolower(str[0]);

	// Reached the end of the word, no more recursion necessary
	if (l == 0)
		return final_letter;

	ii = letters.find(l);

	if (ii == letters.end())
		// No match found indicates a valid word is impossible
		return false;
	else
		// Try next letter
		return letters[l].is_valid(&(str[1]));
}

map<char, trie> &trie::get_letters() {
	return letters;
}

bool trie::is_word() {
	return final_letter;
}
