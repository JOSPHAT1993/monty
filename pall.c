#include "monty.h"

/**
 * pall- print the values in a stack
 *
 * @stack:'stack variable'
 * @line_number:'int variable to print the line of error'
 *
 * Return:void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	UNUSED(line_number);

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
