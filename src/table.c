#include <stdio.h>
#include <stdlib.h>

int createTable(char tableName[])
{
	//  Tabela tem, nome
	//  Coluna
	//  Cada Coluna tem um tipo
	//  E Tem Primary Key

	char *newTableRepository = malloc(sizeof(char) * 51);
	sprintf(newTableRepository, "../db/%s.txt", tableName);
	FILE *file = fopen(newTableRepository, "wr+");
	if (file == NULL)
	{
		puts("ERROR: Couldn't create a new table.");
		return -1;
	}

	printf("Table created at: %s\n", newTableRepository);

	free(newTableRepository);

	fprintf(file, "%s", tableName);
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