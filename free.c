#include "monty.h"
/**
* free_stack - frees a stack
* @top: pointer to top node of the stack
*
* Return: nothing
*/
void free_stack(stack_t *top)
{
	stack_t *current = top;

	while (top)
	{
		current = top->next;
		free(top);
		top = current;
	}
}
