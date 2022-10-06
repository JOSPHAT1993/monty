#include "monty.h"

/**
 * push-function to add a value to a stack
 *
 * @stack:'Stack variable for head'
 * @line_number:'integer variable for position of element'
 *
 * Return:1 for success
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;
	char *push_arg = strtok(NULL, "\n \t");
	int value;

	if (!is_int(push_arg))
	{
		fprintf(stdout, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(push_arg);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = NULL;

	if (*stack == NULL)
	{
		*stack = new;
	}
	else if (SQ)
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->next = temp;
	}
}

