#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_TEST_CASES 10


void printFormated(int num){
	if (num < 1000){
		printf("%10d:%15d\n", num, num);
		return;
	}

	int num_print = num;
	char num_str[20] = "";

	char trio[4];
	char *temp;
	while (num > 1000){
		
		temp = strdup(num_str);

		if (num % 1000 == 0){
			sprintf(trio, "%s", "000");
		} else {
			sprintf(trio, "%d", num%1000);
		}
		

		strcpy(num_str, ",");
		strcat(num_str, trio);

		strcat(num_str, temp);
		free(temp);

		num /= 1000;
	}
	
	temp = strdup(num_str);
	sprintf(num_str, "%d", num);
	strcat(num_str, temp);
	free(temp);

	printf("%10d:%15s\n", num_print, num_str);
}




int main()
{
	int values[NUM_TEST_CASES] = {
		123, 1899, 48266, 123456, 9876543,
		10100100, 5, 500000, 99000111, 83
	};

	for (int i = 0; i < NUM_TEST_CASES; i++){
		printFormated(values[i]);
	}

	return(0);
}
