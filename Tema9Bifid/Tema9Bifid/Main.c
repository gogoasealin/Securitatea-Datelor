#include<stdio.h>

char* alphabet = "abcdefghiklmnopqrstuvwxyz"; // without j

struct position {
	int x;
	int y;
};

void ShowMatrix(char matrix[100][100])
{
	int i, j;
	for (i = 0; i < 100; ++i)
	{
		for (j = 0; j < 100; ++j)
		{
			if (matrix[i][j] != '9') {
				printf("%c", matrix[i][j]);
			}
			else {
				break;
			}
		}
		printf("\n");
		if (matrix[i + 1][0] == '9') {
			break;
		}
	}
	printf("\n");
}

struct position CheckPosition(char letter, char matrixAlphabet[100][100])
{
	int i, j;
	struct position letterposition;

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (matrixAlphabet[i][j] == letter)
			{
				letterposition.x = i;
				letterposition.y = j;
				return letterposition;

			}
		}
	}
	struct position letterposition1;
	letterposition1.x = 7;
	letterposition1.y = 7;
	return letterposition1;
}

void AddMatrixLettersPosition(char matrixCipher[100][100], char matrixAlphabet[100][100], int keyLenght)
{
	int i;
	for (i = 0; i < keyLenght; ++i)
	{
		if (matrixCipher[0][i] == '9')
		{
			break;
		}
	    struct position pos = CheckPosition(matrixCipher[0][i], matrixAlphabet);

		matrixCipher[1][i] = pos.x + '0';
		matrixCipher[2][i] = pos.y + '0';
	}



	int k = -1, j = -1;
	int line ;
	int column;

	for (i = 0; i < keyLenght; ++i)
	{
		if (i % 5 == 0)
		{
			k += 1;
			j += 1;
		}
		if (i % 5 < 2)
		{
			line = matrixCipher[1][k] - '0';
			column = matrixCipher[1][k + 1] - '0';
			char var = matrixAlphabet[line][column];
			matrixCipher[3][i] = var;
			k += 2;
		}
		else if(i % 5 == 2){
			line = matrixCipher[1][i+2] - '0';
			column = matrixCipher[2][i-2] - '0';
			char var = matrixAlphabet[line][column];
			matrixCipher[3][i] = var;
		}
		else if(i % 5 > 2){
			line = matrixCipher[2][j + 1] - '0';
			column = matrixCipher[2][j + 2] - '0';
			char var = matrixAlphabet[line][column];
			matrixCipher[3][i] = var;
			j += 2;
		}
		else {
			printf("eroare");	
		}

	}
}

void DeleteDuplicateLetters(char text[])
{
	int i, j, k;
	int lungimeText = strlen(text);
	for (i = 0; i < lungimeText; ++i)
	{
		for (j = i + 1; text[j] != '\0'; ++j)
		{
			if (text[j] == text[i])
			{
				for (k = j; text[k] != '\0'; ++k)
				{
					if (text[k] == text[k + 1])//verifica literele identice consecutive ex: ghii
					{
						j -= 1;
					}
					text[k] = text[k + 1];
				}
			}
		}
	}
}

void AddMatrixAlphabet(char matrix[100][100], char key[])
{
	int i,j, k = 0;
	for (i = 0; i < 100; ++i)
	{
		for (j = 0; j < 5; j++) {
			matrix[i][j] = key[k];
			k++;
			if (k > strlen(key))
			{
				i = j = 100;
			}
		}
	}
}

void InitiateMatrix(char matrix[100][100])
{
	int i, j;
	for (i = 0; i < 100; ++i)
	{
		for (j = 0; j < 100; ++j)
		{
			matrix[i][j] = '9';
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

void Criptare(char text[], char key[])
{
	char matrixAlphabet[100][100];
	char newKey[100] = "";

	strcat(newKey, key);

	InitiateMatrix(matrixAlphabet);
	strcat(newKey, alphabet);
	DeleteDuplicateLetters(newKey);

	AddMatrixAlphabet(matrixAlphabet, newKey);
	ShowMatrix(matrixAlphabet);

	char matrixCipher[100][100];
	InitiateMatrix(matrixCipher);

	AddMatrixPassword(matrixCipher, text);
	AddMatrixLettersPosition(matrixCipher, matrixAlphabet, strlen(key));

	ShowMatrix(matrixCipher);

}

void DecryptionMatrixLetterPosition(char matrixCipher[100][100], char matrixAlphabet[100][100], int keyLenght)
{
	int i;
	int k = -1, j = -1;
	for (i = 0; i < keyLenght; ++i)
	{
		if (matrixCipher[0][i] == '9')
		{
			break;
		}
		struct position pos = CheckPosition(matrixCipher[0][i], matrixAlphabet);

		if (i % 5 == 0)
		{
			k += 1;
			j += 1;
		}
		if (i % 5 < 2)
		{
			matrixCipher[1][k] = pos.x + '0';
			matrixCipher[1][k+1] = pos.y + '0';

			k += 2;
		}
		else if (i % 5 == 2) {
			matrixCipher[1][i+2] = pos.x + '0';
			matrixCipher[2][i - 2] = pos.y + '0';
		}
		else if (i % 5 > 2) {
			matrixCipher[2][j + 1] = pos.x + '0';
			matrixCipher[2][j + 2] = pos.y + '0';
			j += 2;
		}
		else {
			printf("error");
		}	
	}
	int currentLine;
	int currentColumn;

	for (i = 0; i < keyLenght; ++i)
	{
		currentLine = matrixCipher[1][i] - '0';
		currentColumn = matrixCipher[2][i] - '0';
		char letter = matrixAlphabet[currentLine][currentColumn];
		matrixCipher[3][i] = letter;
	}
}

void Decriptare(char text[], char key[])
{
	char matrixAlphabet[100][100];
	char newKey[100] = "";

	strcat(newKey, key);

	InitiateMatrix(matrixAlphabet);
	strcat(newKey, alphabet);
	DeleteDuplicateLetters(newKey);

	AddMatrixAlphabet(matrixAlphabet, newKey);
	ShowMatrix(matrixAlphabet);

	char matrixCipher[100][100];
	InitiateMatrix(matrixCipher);

	AddMatrixPassword(matrixCipher, text);
	DecryptionMatrixLetterPosition(matrixCipher, matrixAlphabet, strlen(key));

	ShowMatrix(matrixCipher);

}

int main()
{
	int option;
	char key[100];
	char text[100];
	while (1)
	{
		printf("\nCifrul Bifid \n");
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