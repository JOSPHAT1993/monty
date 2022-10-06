#include "monty.h"

/**
 * free_stack-function to free a stack
 *
 * @head:'head variable of the stack'
 *
 * Return:Empty stack
 */
void free_stack(stack_t *head)
{
	stack_t *next;

	if (!head)
		return;
	next = head;
	while (next)
	{
		head = next;
		next = head->next;
		free(head);
	}
}
