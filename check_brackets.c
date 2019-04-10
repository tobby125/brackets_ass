#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;	
	
	fgets(input_buffer, max_line, stdin);	
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    //printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * stack = createStack(max_line); 
	int v = -1;
    for (int position = 0; position < input_len; position++) {
        char next = input_buffer[position];
        if (next == '(' || next == '[' || next == '{') {
			Bracket *bracket = malloc(sizeof(Bracket));
			int type;
			if(next == '(') {
				type = 0;
			}
			if(next == '[') {
				type = 1;
			}
			if(next == '{') {
				type = 2;
			}
			bracket->type = type;
			bracket->position = position;
			push(stack, *bracket);
        }

        if (next == ')' || next == ']' || next == '}') {
			int type;
			if(next == ')') {
				type = 0;
			}
			if(next == ']') {
				type = 1;
			}
			if(next == '}') {
				type = 2;
			}
			if(isEmpty(stack) || type != stack->array[stack->top].type) {
				v = position + 1;
				break;
			}
			else {
				pop(stack);
			}
		}
	}
	if(!isEmpty(stack) && v == -1) {
		v = stack->array[0].position + 1;
	}
	if(v == -1) {
		printf("Success\n");
	}
	else {
		printf("%d\n", v);
	}
    return 0;
}
