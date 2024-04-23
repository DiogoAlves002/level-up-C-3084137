#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PSIZE 20
#define RSIZE 15


int isInArray(int r, int* arr, int size){
	for (int i = 0; i < size; i++){
		if (arr[i] == r){
			return 1;
		}
	}

	return 0;
}

void removeFirstInArray(int *arr, int size){
	for (int i = 1; i < size; i++){
		arr[i - 1] = arr[i];
	}

	arr[size - 1] = -1;
}


int main()
{
	char *playlist[PSIZE] = {
		"Like a Rolling Stone", "Satisfaction", "Imagine",
		"What's Going On", "Respect", "Good Vibrations",
		"Johnny B. Goode", "Hey Jude", "What'd I Say",
		"Smells Like Teen Spirit", "My Generation",
		"Yesterday", "Blowin' in the Wind", "Purple Haze",
		"London Calling", "I Want to Hold Your Hand",
		"Maybellene", "Hound Dog", "Let It Be",
		"A Change Is Gonna Come"
	};
	int frequency[PSIZE];
	int x,r,count;

	/* initialize */
	srand( (unsigned)time(NULL) );
	for(x=0;x<PSIZE;x++){
		frequency[x] = 0;
	}

	int recent[RSIZE];
	for (int i = 0; i < RSIZE; i++){
		recent[i] = -1;
	}


	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	r = -1;
	while(count<100)
	{

		while (isInArray(r, recent, RSIZE)){
			r = rand() % PSIZE;		/* random value */
		} 

		removeFirstInArray(recent, RSIZE);
		recent[RSIZE - 1] = r;

		
		printf("%3d: Now Playing '%s'\n",
				count+1,
				playlist[r]
			  );
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for(x=0;x<PSIZE;x++)
		printf("%s: %d\n",playlist[x],frequency[x]);

	return(0);
}
