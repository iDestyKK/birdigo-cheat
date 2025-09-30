#include <iostream>
#include <string>

#include <stdio.h>

#include "trie.hpp"

using namespace std;

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("usage: %s dict.txt\n", argv[0]);
		return 1;
	}

	trie dict;
	string line;
	bool result;
	dict.open(argv[1]);

	// Prompt the user to get words
	while (cout << "STR> " && getline(cin, line)) {
		result = dict.is_valid(line.c_str());

		if (result == true)
			cout << "is valid word" << endl;
		else
			cout << "not valid word" << endl;
	}

	return 0;
}
