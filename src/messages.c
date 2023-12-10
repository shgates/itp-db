#include <stdio.h>

void helpMessage()
{
	printf("%12s", "\n List of commands:");

	puts("");

	printf("%12s: ", "help");

	puts("Show help message,");

	printf("%12s: ", "leave");

	puts("Exit the program,");

	printf("%12s: ", "credits");

	puts("Show the credits,");

	puts("");

	printf("%12s: ", "create");

	puts("Create a table, line or column,");

	printf("%12s: ", "list");

	puts("List all the tables or a specific one,");

	printf("%12s: ", "search");

	puts("Search for data inside of a choosen column table.");

	printf("%12s: ", "edit");

	puts("Edit a line inside of a choosen table,");

	printf("%12s: ", "delete");

	puts("delete a line of a choosen table,");

	printf("%12s: ", "remove");

	puts("Delete a table from the database.");
}

void finishMessage()
{
	printf("Exiting itp-db\n");
}

void menuMessage()
{
	puts("Your at menu, use 'help' to see the list of commands");
}

void invalidInputMessage()
{
	printf("Invalid input, please try again.\n");
}
