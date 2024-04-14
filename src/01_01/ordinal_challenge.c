#include <stdio.h>

char *ordinal(int v)
{
	if (v == 11 || v == 12 || v == 13)
	{
		return ("th");
	}

	int length = snprintf(NULL, 0, "%d", v);
	char v_str[length + 1];
	sprintf(v_str, "%d", v);

	char last_digit = v_str[length - 1];

	if (last_digit == '1')
	{
		return "st";
	}

	if (last_digit == '2')
	{
		return "nd";
	}

	if (last_digit == '3')
	{
		return "rd";
	}

	return "th";
}

int main()
{
	int c;

	/* output a table of 100 numbers */
	for (c = 1; c <= 20; c++)
	{
		printf("%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\n",
					 c, ordinal(c),
					 c + 20, ordinal(c + 20),
					 c + 40, ordinal(c + 40),
					 c + 60, ordinal(c + 60),
					 c + 80, ordinal(c + 80));
	}

	return (0);
}
