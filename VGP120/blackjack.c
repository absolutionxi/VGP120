#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <Windows.h>

int game();

int main()
{
	game();
	printf("File created. GO READ IT.\n");
	
	system("Pause");
	return 0;
}


int game()
{
	FILE *input;
	FILE *output;
	fopen_s(&input, "input.txt", "r");
	fopen_s(&output, "output.txt", "w");
	while (!feof(input))
	{
		int option = 0;
		int tenpts = 0;
		int sum = 0;
		fscanf_s(input, "%d", &option);
		char cards = '0';
		int i = 0;
		int quit = 0;

		if (feof(input))
		{
			fprintf(output, "EOF, closing. \n");
			return 0;
		}

		if (input == -99)
		{

			fprintf(output, "shutting down");
			return 0;
		}
		
		while (i < option && !feof(input))
		{
			fscanf_s(input, " %c", &cards, 1);
			if (feof(input))
			{
				fprintf(output, "EOF. Goodbye! \n");
				return 0;
			}
			else if (cards == 't' || cards == 'j' || cards == 'k' ||  cards == 'q')
			
			{
				sum += 10;
			}
			else if (cards - '0' > 1 && cards - '0' < 10)
			{
				sum += cards - '0';
			}
			else if (cards == 'a')
			{
				if (sum >= 20)
				{
					sum += 1;
				}
				else
				{
					sum += 11;
					tenpts++;
				}
			}
			else if (sum > 21)
			{
				return 0;

			}
			else if (cards - '0' == -99)
			{
				fprintf(output, "EOF. Goodbye! \n");
			}
			else
			{
				quit = 1;
			}
			i++;
		}
		while (sum >= 22 && tenpts > 0)
		{
			tenpts -= 1;
			sum -= 10;
		}
		if (sum >= 22 && quit == 0)
		{
			fprintf(output,"BUST\n");
		}
		if (quit == 1)
		{
			fprintf(output, "Error\n");
		}
		if (sum <= 21 && !feof(input) && quit == 0)
		{
			fprintf(output, "%d\n", sum);
		}
		if (feof(input))
		{
			fprintf(output, "EOF. Goodbye! \n");
		}
	}
	return 0;
}
