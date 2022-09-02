#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    stack_t *stack = malloc(sizeof(stack_t *));
    /* declare a file pointer */
    FILE    *infile = NULL;
    char    *line = malloc(2000 * sizeof(char));
    size_t    len = 0;
    int    line_number = 0;
    char   *opcode = NULL;
    char   *n;
    ssize_t read;
 
    /* open an existing file for reading */
    infile = fopen("test", "r");
 
    /* quit if the file does not exist */
    if(infile == NULL)
        return 1;


    while ((read = getline(&line, &len, infile)) != -1)
	{
		line_number++;
		opcode = strtok(line, DELIMITERS);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			n = strtok(NULL, DELIMITERS);
			
            push(&stack, atoi(n));
		}
		else
			opcode_struct(opcode, &stack, line_number);
	}

    stack = malloc(sizeof(stack_t));
    push(&stack, 9);
    push(&stack, 8);
    pall(&stack, line_number);
    free_stack(&stack);
    free(line);
    fclose(infile);
    return(1);
}