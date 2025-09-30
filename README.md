# Cheating at Birdigo with C++

Provides CLI applications to cheat at Birdigo. You can check if a word is valid
via `test`, or "solve" your hand for all possible combinations of words with
`cheat`.

For more information, as well as a web implementation, see my blog post on it:
* https://blog.claranguyen.me/post/2025/09/30/birdigo-cheat/

# Compilation

Simply type `make` and the supplied makefile will do the work for you.

# Usage

## test

Tests whether a word is valid or not. To run, supply the `words_alpha.txt` file
as the only argument via:

```bash
UNIX> ./test words_alpha.txt
```

Then it will prompt you to input text. Type in the desired word and see if it's
valid to Birdigo or not.

### Example

```
UNIX> ./test words_alpha.txt
STR> bird
is valid word
STR> birj
not valid word
```

## cheat

Solves your hand. To run, supply the `words_alpha.txt` file as the only argument
via:

```bash
UNIX> ./cheat words_alpha.txt
```

Then it will prompt you to input text. Type in your hand and it will give you
every possible valid word. You can even give it wildcards. You can also specify
word length. The prompt it accepts is `word length`. If you leave `length`
blank, it will print out all possible words regardless.

### Example

```
STR> test
e
es
est
et
s
se
set
sett
st
ste
stet
t
te
test
tet
tets
ts
tst
tt
STR> test 4
sett
stet
test
tets
```
