/*Name: Gary Dhillon 
 * Date: Wednesday, October 15, 2014 
 * Assignment 2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct Stack{
    int top;
    int data[30];
};

typedef struct Stack Stack;

void push(Stack ** stack, int num);
int pop(Stack**stack);
double operation(int x, int y, char operation);

void push(Stack ** stack, int num){
    Stack *temp;
    temp = *stack;
    temp->top = temp->top + 1;
    temp->data[temp->top] = num;
}

int pop(Stack**stack){
    int num;
    Stack * temp;
    temp = *stack;
    
    if(temp->top >= 0){
        num = temp->data[temp->top];
        temp->top = temp->top -1;
    }
    else{
        printf("There is an error in the format of this postfix equation, the calculated value may not correct.\n");
        num = -1000;
    }
    
    return(num);
}

double operation(int x, int y, char operation){
    
    double value;
    
    if(operation == '+'){
        value = x + y;
    }
    else if(operation == '-'){
        value = x-y;
    }
    else if(operation == '*'){
        value = x*y;
    }
    else if(operation == '/'){
        value = x/y;
    }
    else{
        printf("Invalid operator detected, exiting program\n");
        value = -1000;
    }
    
    return(value);
}
    

int main(int argc, const char* argv[]){
    int i,j,w,x,y;
    double value;
    char z;
    Stack * stack = malloc(sizeof(Stack));
    stack->top = -1;
    
    for(i = 1; i<argc; i++){
        for(j = 0; argv[i][j] != '\0'; j++){
        
        
            z = argv[i][j];
            if(isdigit(z)){
                
                w = z - '0';
                push(&stack, w);
            }
            
            else{
                y = pop(&stack);
                x = pop(&stack);
                if(x!=-1000 && y!= -1000)/*Check for invalid operators or improper postfix form*/
                {
                    value = operation(x,y,z);
                }
                else{
                    return 0;
                }
                if(value!=-1000){
                    push(&stack, value);
                }
                else{
                    return 0;
                }
            }
        }
    }
    
    if(i == argc){
        value = pop(&stack);
        printf("The value for the expression is: %0.2f\n", value);
    }
    
    return 0;
}
            
        
