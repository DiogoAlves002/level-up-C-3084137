#include <stdio.h>
#include <string.h>

void center_text(int width, char *text)
{
	int text_len = strlen(text);

	if (text_len >= width - 2) // check if there's enough room for padding
	{
		printf("%s\n", text);
	}
	else
	{
		int padd = (width - text_len) / 2;
		printf("%*s", padd, ""); // pads an enpty string
		printf("%s\n", text);		 // puts the text after
	}
}

int main()
{
	/* some sample text to center */
	char *title[] = {
			"March Sales",
			"My First Project",
			"Centering output is so much fun!",
			"This title is very long, just to see whether the code can handle such a long title"};
	int x;

	/* output each of the strings, centered */
	for (x = 0; x < 4; x++)
	{
		/* assume the screen width to be 80 characters */
		center_text(80, title[x]);
	}

	return (0);
}
