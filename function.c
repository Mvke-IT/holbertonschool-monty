#include "monty.h"
/**
 * add - Add the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "add" opcode appears.
 *
 * Description: This function adds the top two elements of the stack.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	(*stack)->n = sum;

	free(temp);
}

/**
 * pint - Print the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "pint" opcode appears.
 *
 * Description: This function prints the value at the top of the stack.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * nop - Do nothing.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "nop" opcode appears.
 *
 * Description: This function does nothing and is used as a placeholder opcode.
 * It's a no-operation (nop).
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}