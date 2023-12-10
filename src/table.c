#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Types
{
	char char_t[10];
	char int_t[10];
	char float_t[10];
	char double_t[10];
	char string_t[10];
	char bool_t[10];
};

struct Types types = {"char", "int", "float", "double", "string", "bool"};

int createTable(char tableName[])
{
	//  Tabela tem, nome
	//  Coluna
	//  Cada Coluna tem um tipo
	//  E Tem Primary Key

	char *newTableRepository = malloc(sizeof(char) * 70);
	sprintf(newTableRepository, "db/%s.txt", tableName);
	FILE *newTableFile = fopen(newTableRepository, "w");
	if (newTableFile == NULL)
	{
		puts("ERROR: Couldn't create a new table.");
		return -1;
	}

	printf("Table created at: %s\n", newTableRepository);

	free(newTableRepository);

	fprintf(newTableFile, "%s", tableName);

	char *tableColumnType = malloc(sizeof(char) * 51);
	char *tableColumnName = malloc(sizeof(char) * 51);

	printf("Type the name of the primary key column (id, for example)\n-> ");
	scanf("%s", tableColumnName);
	fprintf(newTableFile, "primary %s|", tableColumnName);

	int columnCount = 1;

	puts("Now, create the columns of the table:");

	while (true)
	{
		puts("Column type options: char, int, float, double, string and bool. Press '0' to finish");

	// Goto anchor used to repeat this next input
	columnTypeInput:

		printf("Write the column type [%d]\n-> ", columnCount);
		scanf(" %s", tableColumnType);

		if (tableColumnType[0] == '0')
		{
			puts("Table created successfully.");
			break;
		}

		// If it isn't a valid type, take input again
		if (strncmp(tableColumnType, types.char_t, strlen(types.char_t)) != 0 &&
			strncmp(tableColumnType, types.int_t, strlen(types.int_t)) != 0 &&
			strncmp(tableColumnType, types.float_t, strlen(types.float_t)) != 0 &&
			strncmp(tableColumnType, types.double_t, strlen(types.double_t)) != 0 &&
			strncmp(tableColumnType, types.string_t, strlen(types.string_t)) != 0 &&
			strncmp(tableColumnType, types.bool_t, strlen(types.bool_t)))
		{
			printf("Invalid type, try again\n");
			goto columnTypeInput;
		}

		printf("Write the column name [%d] or press 0 to go back\n-> ", columnCount);
		scanf(" %s", tableColumnName);

		if (tableColumnName[0] == '0')
		{
			printf("Canceled \'%s\' column.\n", tableColumnType);
			goto columnTypeInput;
		}

		// If the input isn't canceled by the user, register the column
		fprintf(newTableFile, "%s %s|", tableColumnType, tableColumnName);

		printf("Column %s (%s) inserted.\n", tableColumnName, tableColumnType);

		columnCount++;
	}

	free(tableColumnType);
	free(tableColumnName);

	fclose(newTableFile);

	return 1;
}

int listAllTables()
{
	return 0;
}

int createNewLine(char tableName[])
{
	return 0;
}