#include "monty.h"

/**
 * get_opcode-function to get opcode
 *
 * @str:'String variable'
 *
 * Return:The opcode
 */
char *get_opcode(char *str)
{
	char *opcode;

	opcode = strtok(str, "\n\t");

	return (opcode);
}
