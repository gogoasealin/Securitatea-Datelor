#include<stdio.h>
#include <ctype.h>

int main()
{
	char input[100];
	printf("Introduceti string-ul: ");
	scanf_s("%[^'\n']s", input, sizeof(input));
	
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	int i, j;
	int count = 0;
	for (i = 0; i < strlen(alphabet); ++i) {
		for (j = 0; j < strlen(input); ++j) {
			if (alphabet[i] == tolower(input[j])) {
				count++;
			}
		}
		if (count > 0) {
			printf("Litera %c apare de %d ori \n", alphabet[i], count);
			count = 0;
		}
	}


	return 0;
}