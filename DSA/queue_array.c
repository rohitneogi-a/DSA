#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
 void initializequeue(int *queue, int *front, int *rear){
     *front=-1;
     *rear=-1;
 }
 
 int isfull(int rear){
     return (rear == MAX_SIZE-1);
     
 }
 
 int isempty (int front , int rear){
     return (front == -1 && rear == -1);
 }
 
 void enqueue (int *queue , int *front, int *rear, int element){
     if(isfull(*rear)){
         printf("Queue is Full!\n");
         return;
     }
     if (isempty(*front, *rear)){
         *front = 0;
         *rear = 0;
         queue[*rear] = element;
     }
     else{
         (*rear)++;
         queue[*rear]= element;
     }
     printf("%d Enqueued!",element);
 }
 
 void dequeue(int *queue, int *front, int *rear){
     if(isempty(*front, *rear)){
         printf("Nothing to delete!\n");
         return;
     }
     int removedelement = queue[*front];
     if(*front==*rear){
         initializequeue(queue,front,rear);
     }
     else{
         (*front)++;
     }
     printf("%d dequeued!\n",removedelement);
 }
 
 int peek(int *queue, int front, int rear){
     if (isempty(front, rear)){
         printf("Nothing to Peek!");
         return -1;
     }
     return queue[front];
 }
 
 void display(int *queue, int front, int rear){
 	if (isempty(front, rear)){
 		printf("Nothing to display!\n");
 		return ; 
	 }
	 printf("Queue Elements::");
	 	for(int i = front; i <= rear; i++){
	 	printf("%d ", queue[i]);
	 }
	 printf("\n");
 }
 
 int main(){
 	int queue [MAX_SIZE];
 	int front, rear;
 	initializequeue(queue, &front, &rear);
 	
 	int choice, element;
 	
 	while(1){
 		printf("\nQueue Operation::\n");
 		printf("1.Enqueue\n");
 		printf("2.Dequeue\n");
 		printf("3.Peek\n");
 		printf("4.Display\n");
 		printf("5.Exit\n");
 		printf("Enter your choice: ");
 		scanf("%d", &choice);
 		
 		switch(choice){
 			case 1 :
 				printf("Enter element::");
 				scanf("%d", &element);
 				enqueue(queue, &front, &rear, element);
 				break;
 			case 2 :
 				dequeue(queue, &front, &rear);
 				break;
 			case 3:
 				element = peek(queue, front, rear);
 				if (element != -1){
 					printf("Front Element :: %d\n", element);
				 }
				 break;
			case 4:
				display(queue, front, rear);
				break;
			case 5:
				exit(0);
			default :
				printf("Invalid Choice!");
 				
		 }
	 }
	 return 0;
 }
