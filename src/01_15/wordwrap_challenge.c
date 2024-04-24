#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 
#include <string.h>

#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40



void printWrap(char *text, int width){

	size_t len = strlen(text);

	char *text_ptr = text;
	char *text_start = text_ptr;
	
	char *word;
	word = (char *)malloc(20 * sizeof(char));
	int word_size = 0;

	int line_size = 0; // used to count the caracters so far

	while (text_ptr - text_start < len){
		word[word_size++] = *text_ptr;

		if (*text_ptr == ' ' || *text_ptr == '\n'){
			word[word_size] = '\0';

			
			if (line_size + word_size - 1 > width ){
				printf("\n");
				line_size = 0;
			}

			if (word[word_size - 1] == '\n'){
				line_size = 0;
			}

			printf("%s", word);
			line_size += word_size;

			word_size = 0;
			
		} 

		
		text_ptr++;
	} 
	printf("\n");
	free(word);
}

int isNumber(char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return 0;
    }
    return 1;
}


int main(int argc, char *argv[])
{
	/* Shakespear's 18th Sonnet */
	static char *text = "Shall I compare thee to a summer's day? \
Thou art more lovely and more temperate:\n\
Rough winds do shake the darling buds of May, \
And summer's lease hath all too short a date;\n\
Sometime too hot the eye of heaven shines, \
And often is his gold complexion dimm'd;\n\
And every fair from fair sometime declines, \
By chance or nature's changing course untrimm'd;\n\
But thy eternal summer shall not fade, \
Nor lose possession of that fair thou ow'st;\n\
Nor shall death brag thou wander'st in his shade, \
When in eternal lines to time thou grow'st:\n\
So long as men can breathe or eyes can see, \
So long lives this, and this gives life to thee.";

	int width = W_DEFAULT;

	if (argc == 2){
		if (! isNumber(argv[1])){
			printf("[ERROR] the argument must be an integer");
			return -1;
		}

		width = atoi(argv[1]);
	}


	printWrap(text, width);

	return(0);
}
