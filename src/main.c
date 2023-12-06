#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "table.h"

int checkCommand(const char userInput[], const char command[])
{
	if (strncmp(userInput, command, strlen(command)) == 0)
		return 1;
	return 0;
}

void invalidInput()
{
	printf("Invalid input, please try again.\n");
}

int main()
{
	printf("Welcome to ITP-DB\n");
	char userInput[256];
	int option = 0;

	while (true)
	{
		fgets(userInput, 256, stdin);
		if (checkCommand(userInput, "create"))
		{
			printf("vai criar\n");
		}
		else if (checkCommand(userInput, "list"))
		{
			printf("{0} Go back to menu\n{1} List all tables\n{2} List a specific table\n");
			switch (option)
			{
			case 0:
				printf("Voltou\n");
				break;
			case 1:
				printf("Todas tabelas\n");
				break;
			case 2:
				printf("Tabela especifica\n");
				break;
			default:
				printf("Comando inválido\n");
			}

			if (option == 1)
			{
			}
			if (option == 2)
			{
			}
			else
			{
			}
		}
		else if (checkCommand(userInput, "line"))
		{
			printf("linha\n");
			return 0;
		}
		else if (checkCommand(userInput, "search"))
		{
			printf("procurar tabela\n");
			return 0;
		}
		else if (checkCommand(userInput, "line"))
		{
			printf("Comando inválido\n");
			return 0;
		}
		else if (checkCommand(userInput, "delete"))
		{
			printf("deletar\n");
			return 0;
		}
		else
		{
			invalidInput();
		}
	}
	printf("fora do while\n");
	return 0;
}