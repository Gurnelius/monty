#include "monty.h"

/**
 * execute - execute the monty instruction
 * @line: line containing instruction
 * @line_number: byte code line number
 * @file: monty file pointer
 *
 * Return: 0 always
 */
int execute(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
	unsigned int i;
	char *opcode;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	opcode = strtok(line, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);

	g_buffer.arg = strtok(NULL, " \n\t");

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (0);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	fclose(file);
	free(line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
