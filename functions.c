#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **sk, int c)
{
    if(*sk == NULL)
    {
        printf("invalid stack\n");
    }else
    {
        stack_t *newlayer = malloc(sizeof(stack_t));
        if(newlayer == NULL)
        {
            printf("stack overflow\n");
        }

        newlayer->n = c;
        newlayer->prev = NULL;
        newlayer->next = *sk;
        *sk = newlayer;
    }
}

void pall(stack_t **sk, unsigned int line_number)
{
    stack_t *node;

    node = *sk;
    if(node == NULL)
    {
        printf("L%d error in line", line_number);
    }
    while(node->next != NULL)
    {
        printf("%i\n", node->n);
        node = node->next;
    } 
}