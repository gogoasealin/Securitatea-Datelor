#include<stdio.h>

char* alfabet = "abcdefghijklmnopqrstuvwxyz";

void Criptare(char text[], char key[])
{
	int i;
	strcat(key, text);
	for (i = 0; i < strlen(text); ++i)
	{
		int literaText = tolower(text[i]) - 'a';
		int literaCheie = tolower(key[i]) - 'a';
		printf("%c", alfabet[(literaText + literaCheie) % strlen(alfabet)]);
	}
}

void Decriptare(char text[], char key[])
{
	int i;
	int literaCheie;
	char c;
	for (i = 0; i < strlen(text); ++i)
	{
		int literaText = tolower(text[i]) - 'a';
		if (i < strlen(key)) {
			literaCheie = tolower(key[i]) - 'a';
		}
		else {
			literaCheie = tolower(c) - 'a';
		}

		c = alfabet[(literaText - literaCheie + strlen(alfabet)) % strlen(alfabet)];
		printf("%c", c);

	}
}

int main()
{
	int option;
	char key[100];
	char text[100];
	while (1)
	{
		printf("\nAlegeti optiunea dorita: \n");
		printf("1.Criptare \n");
		printf("2.Decriptare \n");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			printf("Introduceti mesajul decriptat: ");
			scanf_s(" %[^'\n']s", text, sizeof(text));
			printf("Introduceti cheia: ");
			scanf_s(" %[^'\n']s", key, sizeof(key));
			Criptare(text, key);
			break;
		case 2:
			printf("Introduceti mesajul criptat: ");
			scanf_s(" %[^'\n']s", text, sizeof(text));
			printf("Introduceti cheia: ");
			scanf_s(" %[^'\n']s", key, sizeof(key));
			Decriptare(text, key);
			break;
		default:
			printf("Va rugam alegeti una dintre optiunile afisate");
			break;
		}
	}
	return 0;
}