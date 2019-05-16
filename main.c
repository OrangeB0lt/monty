#include "monty.h"
/**
 * main - main function for monty interpreter
 *
 * Return: 0 on success or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	char *lineptr = NULL, opcode[6], wrong[1024];
	ssize_t read;
	size_t len;
	stack_t *stack = NULL;
	int matches;
	unsigned int line_number = 0;

	/* if too many or too few arguments to monty exit fail */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globes.fm = fopen(argv[1], "r"); /* not freed must close file */
	/* if file cant open then exit fail */
	if (globes.fm == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(globes.fm);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&lineptr, &len, globes.fm)) != -1)
	{
		line_number++;
		matches = sscanf(lineptr, "%s%d%1s", opcode, &globes.data, wrong);
		if (matches != 2 && strcmp(opcode, "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(globes.fm);
			exit(EXIT_FAILURE);
		}
		if (opcode != NULL && opcode[0] != '#')
			opcomp(&stack, line_number, opcode);
		free(lineptr);
		lineptr = NULL;
	}
	fclose(globes.fm);
	/* malloc failure */
	/* if (errno == something)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		}*/
	return (0);
}
