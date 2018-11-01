#include <stdio.h>
#include <ctype.h>

int main()
{
	int option;
	int key;
	char mesaj[100];
	int i;

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
			scanf_s(" %[^'\n']s", mesaj, sizeof(mesaj));
			printf("%s", mesaj);
			printf("Introduceti cheia de deplasare(pozitiva): ");
			scanf_s("%d", &key);
			for (i = 0; i < strlen(mesaj); ++i)
			{
				if (isupper(mesaj[i]))
				{
					if (mesaj[i] + key < 'Z') {
						printf("%c", mesaj[i] + key);
					}
					else if (mesaj[i] + key > 'Z') {
						printf("%c", (mesaj[i] + key) - 26);
					}
				}
				else {
					if (isdigit(mesaj[i]))
					{
						if ((mesaj[i] + key) <= '9')
						{
							printf("%c", mesaj[i] + key);
						}
						else {
							printf("%c", (mesaj[i] + key) - 10);
						}
					}
					else if (mesaj[i] + key < 'z') {
						printf("%c", mesaj[i] + key);
					}
					else if (mesaj[i] + key > 'z') {
						printf("%c", (mesaj[i] + key) - 26);
					}
				}
			}
			break;
		case 2:
			printf("Introduceti mesajul criptat: ");
			scanf_s(" %s", &mesaj, sizeof(mesaj));
			printf("Introduceti cheia de deplasare: ");
			scanf_s("%d", &key);
			for (i = 0; i < strlen(mesaj); ++i)
			{
				if (isupper(mesaj[i]))
				{
					if (mesaj[i] + key < 'A') {
						printf("%c", mesaj[i] - key);
					}
					else if (mesaj[i] + key > 'A') {
						printf("%c", (mesaj[i] - key) + 26);
					}
				}
				else {
					if (isdigit(mesaj[i]))
					{
						if ((mesaj[i] - key) >= '0')
						{
							printf("%c", mesaj[i] - key);
						}
						else {
							printf("%c", (mesaj[i] - key) + 10);
						}
					}
					else if (mesaj[i] + key > 'a') {
						printf("%c", mesaj[i] - key);
					}
					else if (mesaj[i] + key < 'A') {
						printf("%c", mesaj[i] - key);
					}
					else if (mesaj[i] + key < 'a') {
						printf("%c", (mesaj[i] - key) + 26);
					}

				}
			}
			break;
		default:
			printf("Va rugam alegeti una dintre optiunile afisate");
			break;
		}
	}
	return 0;
}