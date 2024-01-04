#include "monty.h"
/**
 * push - Push an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "push" opcode appears.
 *
 * Description: This function pushes an integer value onto the stack.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Print all elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "pall" opcode appears.
 *
 * Description: This function prints all elements in the stack.
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

/**
 * pop - Remove the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "pop" opcode appears.
 *
 * Description: This function removes the top element from the stack.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - Swap the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "swap" opcode appears.
 *
 * Description: This function swaps the top two elements of the stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->next = temp->next;
	temp->next = *stack;

	temp->prev = NULL;
	(*stack)->prev = temp;

	*stack = temp;
}

#include "monty.h"
/**
 * is_integer - Check if a string is a valid integer.
 * @str: The input string to be checked.
 * Return: 1 if @str is a valid integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	if (!str || !*str || (*str != '-' && !isdigit(*str)))
		return (0);

	for (int i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
