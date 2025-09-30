#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class trie {
	public:
		trie();
		trie(char *);

		bool open(char *);
		void clear();
		void insert(const char *);
		bool is_valid(const char *);
		map<char, trie> &get_letters();
		bool is_word();

	private:
		map<char, trie> letters;
		bool final_letter;
};
