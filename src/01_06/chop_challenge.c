#include <stdio.h>
#include <stdlib.h>

int strLen(char *s){
	int s_len = 0;
	char s_c = 'a';

	while (s_c != '\0'){
		s_c = s[s_len++];
	}
	s_len--; // not counting the null terminator

	return s_len;
}


char *left(char *s,int len)
{
	char *ret;

	ret = (char*)malloc(sizeof(s[0] * len + 1));

	for (int i = 0; i < len; i++){
		ret[i] = s[i];
	}

	ret[len] = '\0';
	return ret;
}

char *right(char *s,int len)
{
	char *ret;

	ret = (char*)malloc(sizeof(s[0] * len + 1));


	// get string length
	int s_len = strLen(s);


	int idx = 0;
	for (int i = s_len - len; i < s_len; i++){
		ret[idx++] = s[i];
	}

	ret[len] = '\0';
	return ret;
}

/* 
	assuming offset + len < strLen(s)
  	(for simplicity)
*/
char *mid(char *s,int offset, int len)
{
	
	char *ret;

	ret = (char*)malloc(sizeof(s[0] * len + 1));

	int idx = 0;
	for (int i = offset - 1; i < offset + len; i++){
		ret[idx++] = s[i];
	}

	ret[len] = '\0';
	return ret;

}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16,left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,13,11));


	return(0);
}
