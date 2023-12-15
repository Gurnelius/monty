#include "monty.h"

/**
 * push - push node to stack
 * @stack: pointer to stack
 * @line_number: byte code line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	if (g_buffer.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(g_buffer.file);
		free(g_buffer.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(g_buffer.arg);
	if (value == 0 && g_buffer.arg[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(g_buffer.file);
		free(g_buffer.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* Allocate memory for a new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(g_buffer.file);
		free(g_buffer.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* Set the value for the new node */
	new_node->n = value;
	/* Link the new node to the existing stack */
	new_node->next = *stack;
	new_node->prev = NULL;
	/* Update the previous pointer of the existing stack, if it's not NULL */
	if (*stack != NULL)
		(*stack)->prev = new_node;
	/* Update the stack pointer to the new node */
	*stack = new_node;
}

/**
 * pall - print all the data
 * stored in the stack
 *
 * @stack: pointer to the stack
 * @line_number: byte code line number
 *
 * return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
