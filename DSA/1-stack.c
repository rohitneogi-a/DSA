#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct stack {
    int data [MAX_SIZE];
    int top;
};
void initializestack(struct stack* stack){
    stack->top =-1;
    return;
}

int isfull(struct stack* stack){
    return stack->top == MAX_SIZE -1;
}
int isempty(struct stack* stack){
    return stack -> top == -1;
}

void push(struct stack* stack, int element){
    if (isfull(stack)){
        printf("Element Can't push!");
        return;
    }
    stack->data[++stack->top]=element;
    printf("%d is pushed!\n",element);
}

void pop(struct stack* stack){
    if (isempty(stack)){
        printf("Stack is Empty!\n");
        return;
    }
    printf("%d is popped from stack!\n",stack->data[stack->top]);
    stack->top--;
}

int peek(struct stack* stack){
    if (isempty(stack)){
        printf("Stack is empty! Nothing to display.");
        return -1;
    }
    return stack->data[stack->top]; 
}

void display(struct stack* stack){
    if (isempty (stack)){
        printf("Stack is empty!");
        return;
    }
    for(int i =stack->top; i>=0; i--){
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main(){
    struct stack stack;
    initializestack(&stack);
    
    int choice, element;
    
    while(1) {
        printf("Stack Operations:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1 :
                printf("Enter Element to Push:");
                scanf("%d",&element);
                push(&stack, element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                int topelement = peek(&stack);
                if (topelement != -1){
                    printf("Top element: %d\n",topelement);
                }
                break;
            case 4 :
                display(&stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid Choice!");
            
        }
    }
    return 0;
}
