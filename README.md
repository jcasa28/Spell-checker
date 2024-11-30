# Spell Checker

This project implements a simple spell checker that detects misspelled words in a text and suggests possible corrections. It uses a hashset to store a dictionary of words and applies different correction strategies like replacing characters, swapping adjacent characters, and erasing characters.

## Files

- `spell_checker.c`: The main program for checking and correcting spelling errors.
- `hashset.c`: Implementation of a hashset data structure for storing the dictionary.
- `words.txt`: A text file containing a list of words (dictionary).
- `Makefile`: A Makefile to build and run the program.

### Steps to Run the Program

1. **Clone or Download the Repository**:
   Make sure you have the following files in the same directory:
   - `spell_checker.c`
   - `hashset_pa4.c`
   - `words.txt`
   - `makefile`

2. **Build the Program**:
   Open your terminal and navigate to the directory where the files are located. Then, use the following command to build the program:

   ```bash
   make

This will compile spell_checker.c and hashset.c and create an executable called spell_checker.
	
3.	**Run the Spell Checker**:
You can run the program by using the following command:

```./spell_checker [-r] [-s] [-e]```

The program accepts flags that control how it attempts to correct misspelled words:
   - `-r`: Enable replacing characters (replaces each character with an alternative character in the alphabet).
   - `-s`: Enable swapping adjacent characters (swaps adjacent characters to find a possible word).
   - `-e`: Enable erasing characters (removes a character at a time to check if it becomes a valid word).

Example:
```./spell_checker -r -s -e
./spell_checker -r
./spell_checker -s
./spell_checker -e
./spell_checker -r -s 
```
This will read input from stdin, check for misspelled words, and print possible corrections.

**Input Format**

• The program reads from stdin (standard input).
• It checks each word in the input line for spelling errors based on the dictionary file (words.txt).
• Misspelled words will be printed along with their possible corrections in CSV format.

```Ths is an exmple of a sentnce with erors.```

**Output Format**

For each misspelled word, the output will be displayed in the following format:
```word, Ln, Col, Possible Corrections```

Where:
  - `word` is the misspelled word.
  - `Ln` is the line number.
  - `Col`: is the column number.
  - `Possible Corrections`: are suggestions for correcting the misspelled word.

**Example output**:
```word, Ln, Col, Possible Corrections
(Ths), 1, 1, This, 
(exmple), 1, 7, example, 
(sentnce), 1, 14, sentence, 
(erors), 1, 24, errors, 
```
**Notes**

  - The program uses a simple hashset implementation to store and search for words in the dictionary (words.txt).
  - The correction strategies are applied only if the corresponding flags (-r, -s, -e) are set:
  - `-r`:replaces each character with alternatives in the alphabet.
  - `-s`: swaps adjacent characters.
  - `-e`: erases characters from the word.
