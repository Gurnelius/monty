#include "monty.h"

buffer_t g_buffer;
/**
 * main - Program entry point
 * @argc: argument count
 * @argv: argument vectors, store arguments
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	char *line;
	FILE *monty_file;
	size_t line_size = 0;
	ssize_t read_result = 1;
	stack_t *monty_stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	g_buffer.file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_result > 0)
	{
		line = NULL;
		read_result = getline(&line, &line_size, monty_file);
		g_buffer.line = line;
		line_counter++;

		if (read_result > 0)
		{
			execute(line, &monty_stack, line_counter, monty_file);
		}
		free(line);
	}

	free_stack(monty_stack);
	fclose(monty_file);
	return (0);
}
