#include "monty.h"
#include <stdio.h>
/**
 * main-main entry file
 *
 * @argc:'line arguments'
 * @argv:'Array of arguments'
 *
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	FILE *file_inp;
	unsigned int line_number = 0;
	char *line = NULL;
	stack_t *top = NULL;
	instruction_t *instruction = NULL;
	size_t glsize;

	if (argc != 2)
	{
		fprintf(stdout, "USAGE: main file\n");
		exit(EXIT_FAILURE);
	}
	file_inp = fopen(argv[1], "r");
	if (file_inp == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &glsize, file_inp) != -1)
	{
		line_number++;
		instruction = parse_line(line);

		if (!(instruction->opcode) || instruction->opcode[0] == '#')
		{
			free(instruction);
			if (line)
				free(line);
			line = NULL;
			continue;
		}
		if (instruction->f)
			instruction->f(&top, line_number);
		else
		{
			fprintf(stdout, "L%d: unknown instruction %s\n",
				line_number, instruction->opcode);
			if (line)
				free(line);
			if (top)
				free_stack(top);
			free(instruction);
			fclose(file_inp);
			exit(EXIT_FAILURE);
		}

		if (line)
			free(line);
		line = NULL;
		free(instruction);
	}

	if (line)
		free(line);
	free_stack(top);
	fclose(file_inp);
	return (0);
}
