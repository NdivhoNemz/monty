#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the Monty file being processed
 */

void push(stack_t **stack, unsigned int line_number)
{
    int value;
    stack_t *new_node;

    if (!operand || !isdigit(*operand))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(operand);
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the Monty file being processed
 */

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
