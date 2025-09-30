#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.hpp"

using namespace std;

// ----------------------------------------------------------------------------
// Helper Functions                                                        {{{1
// ----------------------------------------------------------------------------

unsigned int num_chars(const char *str, char target) {
	unsigned int i, len, t;

	len = strlen(str);
	t   = 0;

	for (i = 0; i < len; i++)
		t += (str[i] == target);

	return t;
}

// ----------------------------------------------------------------------------
// Recursion                                                               {{{1
// ----------------------------------------------------------------------------

void process_hand(trie dict, string hand, set<string> &words, string word) {
	unsigned int i, sz;
	char c, cc;
	map<char, trie> &letters = dict.get_letters();
	map<char, trie>::iterator ii;

	sz = hand.length();

	if (dict.is_word())
		words.insert(word);

	// If we have no more letters in our hand, we are done
	if (num_chars(hand.c_str(), ' ') == sz) {
		return;
	}

	// Go through every letter in the hand
	for (i = 0; i < sz; i++) {
		// Skip blanks
		if (hand[i] == ' ')
			continue;

		// Blank out the current letter
		c = hand[i];
		hand[i] = ' ';

		if (c == '*') {
			// Wildcards get special treatment
			for (cc = 'a'; cc <= 'z'; cc++) {
				ii = letters.find(cc);
				if (ii != letters.end()) {
					// NOTE: Could add "cc", but add wildcard to string instead
					process_hand(letters[cc], hand, words, word + c);
				}
			}
		}
		else {
			// Go to the next letter, if possible
			ii = letters.find(c);
			if (ii != letters.end()) {
				process_hand(letters[c], hand, words, word + c);
			}
		}

		// Revert
		hand[i] = c;
	}
}

void process_hand(trie dict, string hand, int limit = 0) {
	set<string> words;
	set<string>::iterator ii;

	process_hand(dict, hand, words, "");

	for (ii = words.begin(); ii != words.end(); ii++)
		if (limit == 0 || (*ii).length() == limit)
			cout << *ii << endl;
}

// ----------------------------------------------------------------------------
// Main Function                                                           {{{1
// ----------------------------------------------------------------------------

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("usage: %s dict.txt\n", argv[0]);
		return 1;
	}

	trie dict;
	string line, word;
	int limit;
	bool result;
	dict.open(argv[1]);

	// Prompt the user to get words
	while (cout << "STR> " && getline(cin, line)) {
		istringstream is(line);

		// Allow either "word" or "word size"
		is >> line;
		if (!(is >> limit))
			limit = 0;

		// Process hand and give possible words
		process_hand(dict, line, limit);
	}

	return 0;
}
