#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "table.h"
#include "messages.h"

int checkCommand(const char userInput[], const char command[])
{
	if (strncmp(userInput, command, strlen(command)) == 0)
		return 1;
	return 0;
}

int main()
{

	printf("Welcome to ITP-DB\n");
	char userInput[256];
	int option = 0;

	while (true)
	{
	input:
		fgets(userInput, 256, stdin);

		if (userInput[0] == '\n')
			goto input;

		userInput[strlen(userInput) - 1] = '\0';

		if (checkCommand(userInput, "help"))
		{
			helpMessage();
		}
		else if (checkCommand(userInput, "leave"))
		{
			finishMessage();
			break;
		}
		else if (checkCommand(userInput, "create"))
		{
		createOption:

			printf("\n{0} Go back to menu\n{1} create a new table\n{2} create a line in a existing table\n");
			scanf(" %d", &option);
			switch (option)
			{
			case 0:
				menuMessage();
				goto input;

			case 1:
				printf("Type the name of the new table\n-> ");
				scanf(" %s", userInput);
				createTable(userInput);
				break;
			case 2:
				printf("Criar linha na tabela\n");
				break;
			default:
				printf("Invalid option, please try again\n");
				goto createOption;
			}
			printf("Type the name of the new table\n-> ");
			scanf(" %s", userInput);
			createTable(userInput);
		}
		else if (checkCommand(userInput, "list"))
		{
		listOption:
			printf("{0} Go back to menu\n{1} List all tables\n{2} List a specific table\n");
			scanf(" %d", &option);
			switch (option)
			{
			case 0:

				menuMessage();
				goto input;

			case 1:
				// listTables();
				printf("Todas tabelas\n");
				break;
			case 2:
				// listTables();
				// printf("Type the name of the table to list all values\n»»» ");
				// scanf(" %s", userInput);
				// listValues(userInput);
				printf("Tabela especifica\n");
				break;
			default:
				printf("Invalid option, please try again\n");
				goto listOption;
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
		else if (checkCommand(userInput, "delete"))
		{
			printf("deletar\n");
			return 0;
		}
		else
		{
			invalidInputMessage();
		}
	}

	return 0;
}