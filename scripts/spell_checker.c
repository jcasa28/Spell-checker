#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hash.h"
#define MAX_WORD_LEN 60
#define MAX_LINE_LEN 1000
#define REPLACE 1
#define SWAP 2
#define ERASE 4



void print_possible_correction(char* misspelled_word, int flags,hashset dict){

    char corrections[MAX_WORD_LEN * 10]="";

	if(flags & REPLACE){
		/*..
		replace each character with an alternative character in the 
		alphabet to find out whether you can fix the misspelled_word!
		**/ 
        for (int i = 0; i < strlen(misspelled_word); i++) {
            char original_char = misspelled_word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == original_char) continue;
                
                misspelled_word[i] = ch;
                if (search(dict, misspelled_word)) {
                    strcat(corrections, misspelled_word);
                    strcat(corrections, ",");
                }
            }
            misspelled_word[i] = original_char;
        }
	
    }

	
	if(flags & SWAP){
		/*..
		swap each character with its neighbor to find out whether 
		you can fix the misspelled_word!
		**/ 
        for (int i = 0; i <=strlen(misspelled_word) - 1; i++) {
            char temp = misspelled_word[i];
            misspelled_word[i] = misspelled_word[i + 1];
            misspelled_word[i + 1] = temp;

            if (search(dict, misspelled_word)) {
                strcat(corrections, misspelled_word);
                strcat(corrections, ",");
            }
            
            temp = misspelled_word[i];
            misspelled_word[i] = misspelled_word[i + 1];
            misspelled_word[i + 1] = temp;
        }
        
	}
    if (flags & ERASE) {

        for (int i = 0; i <=strlen(misspelled_word); i++) {
            char erased_char = misspelled_word[i];
            memmove(misspelled_word + i, misspelled_word + i + 1, strlen(misspelled_word) - i);

            if (search(dict, misspelled_word)) {
                strcat(corrections, misspelled_word);
                strcat(corrections, ",");
            }
            memmove(misspelled_word + i + 1, misspelled_word + i, strlen(misspelled_word) - i + 1);
            misspelled_word[i] = erased_char;
            
        }
        
        //remove trailing comma
        if (strlen(corrections) > 0 && corrections[strlen(corrections) - 1] == ',') {
            corrections[strlen(corrections) - 1] = '\0';
        }

    }
    //print possible corrections in CSV format
    if (strlen(corrections) > 0) {
        printf(", %s", corrections);
    }
}

int main(int argc, char* argv[]){



	int flags = 0;
	char* dictionary_filename = "words.txt";
	hashset set = set_init();
	for(int i = 1; i < argc;i++){
		if(argv[i][0] != '-')
			exit(1);
		if(!strcmp(argv[i], "-d")){
			if(i+1 == argc)
				exit(3);
			dictionary_filename = argv[++i];
			continue;
		}
		for(int j = 1; j < strlen(argv[i]);j++){
			switch(argv[i][j]){
				case 'e': flags |= ERASE;break;
				case 's': flags |= SWAP; break;
				case 'r': flags |= REPLACE; break;
				default: exit(2);
			}
		}
	}
	FILE* words_file = fopen(dictionary_filename, "r");
	char buffer[MAX_WORD_LEN];
	while(fgets(buffer, MAX_WORD_LEN, words_file)){
		int len = strlen(buffer);
		if(buffer[len-1] == '\n')
			buffer[len-1] = '\0';
		//printf("next line: %s\n", buffer);
		insert(&set, buffer);
	}
	fclose(words_file);
   
 
    char *line[MAX_LINE_LEN];
	int line_number=0;
    // hashset new_set=set_init();
    //  for(int i=0;i<line_number;i++){
	while(fgets(line,MAX_LINE_LEN,stdin)){
		//parsing a single line
        line_number++;
   
    
		//tokenize line
        char *word = strtok(line, " \t\n.,;!?()[]{}\"");
        
        
		//get every word
       
        // for (int line_n=0;line_n<=line_number;line_n++){
        while (word != NULL) {
         
            int col=1;
            col += strlen(word)+1;
            //search for the word in the set...
        	if(!search(set, word)){

                // insert(&new_set,word);
                printf("word, Ln, Col, Possible Corrections\n");
                printf("(%s), %d, %d",word, line_number,col);
                // print all poossible corrections for a misspelled word...
                print_possible_correction(strdup(word), flags, set);
                printf("\n");


            } 
            
            word = strtok(NULL, " \t\n.,;!?()[]{}\"'");//next word
            
        }
    }
    
    
     
	
}
