#include<stdio.h>

char* alfabet = "abcdefghijklmnopqrstuvwxyz";

void ChangeMatrixColumn(char matrix[100][100], int firstColumn, int secondColumn, int keyLenght)
{
	int i = 0;
	while (matrix[i][secondColumn] != '0')
	{
		char temp;
		temp = matrix[i][secondColumn];
		matrix[i][secondColumn] = matrix[i][firstColumn];
		matrix[i][firstColumn] = temp;
		i++;
	}
}


void AddMatrixText(char matrix[100][100], char text[], int keyLenght)
{
	int i, j, k = 0;
	for (i = 1; i < 100; ++i)
	{
		for (j = 0; j < keyLenght; ++j)
		{
			if (k < strlen(text)) {
				matrix[i][j] = text[k];
				k++;
			}
			else {
				matrix[i][j] = ' ';
			}
		}
		if (k == strlen(text))
		{
			break;
		}
	}
}

void AddMatrixPassword(char matrix[100][100], char key[])
{
	int i;
	for (i = 0; i < 100; ++i)
	{
		if (i < strlen(key)) {
			matrix[0][i] = key[i];
		}
		else {
			break;
		}
	}
}

void ShowMatrix(char matrix[100][100], int keyLenght)
{
	int i, j;
	for (i = 0; i < 100; ++i)
	{
		for (j = 0; j < keyLenght; ++j)
		{
			if (matrix[i][j] != '0') {
				printf("%c", matrix[i][j]);
			}
			else {
				break;
			}
		}
		printf("\n");
		if (matrix[i + 1][0] == '0') {
			break;
		}
	}
	printf("\n");
}

void InitiateMatrix(char matrix[100][100])
{
	int i, j;
	for (i = 0; i < 100; ++i)
	{
		for (j = 0; j < 100; ++j)
		{
			matrix[i][j] = '0';
		}
	}
}

void Criptare(char text[], char key[])
{
	int i, j, k = 0;
	char matrix[100][100];
	
	InitiateMatrix(matrix);

	AddMatrixPassword(matrix, key);

	AddMatrixText(matrix, text, strlen(key));

	ShowMatrix(matrix, strlen(key));
	
	for (i = 0; i < strlen(alfabet); ++i)
	{
		for (j = 0; j < strlen(key); ++j) {
			if (alfabet[i] == matrix[0][j]) {
				ChangeMatrixColumn(matrix, j, k, strlen(key));
				k++;
			}
		}
	}

	ShowMatrix(matrix, strlen(key));

}

void Decriptare(char text[], char key[])
{
	int i, j, k = 0;
	char matrix[100][100];

	InitiateMatrix(matrix);

	AddMatrixPassword(matrix, key);

	for (i = 0; i < strlen(alfabet); ++i)
	{
		for (j = 0; j < strlen(key); ++j) {
			if (alfabet[i] == matrix[0][j]) {
				ChangeMatrixColumn(matrix, j, k, strlen(key));
				k++;
			}
		}
	}

	AddMatrixText(matrix, text, strlen(key));
	
	ShowMatrix(matrix, strlen(key));

	k = 0;
	for (i = 0; i < strlen(key); ++i)
	{
		for (j = 0; j < strlen(key); ++j) {
			if (key[i] == matrix[0][j]) {
				ChangeMatrixColumn(matrix, j, k, strlen(key));
				k++;
				break;
			}
		}
	}

	ShowMatrix(matrix, strlen(key));

}

int main()
{
	int option;
	char key[100];
	char text[100];
	while (1)
	{
		printf("\nCifrul Column Transposition: \n");
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