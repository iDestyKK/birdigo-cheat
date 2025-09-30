CC     = g++
CFLAGS = -O3

all: cheat test

cheat: cheat.cpp trie.cpp
	$(CC) $(CFLAGS) -o $@ $^

test: test.cpp trie.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) cheat test
