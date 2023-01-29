#include <stdio.h>

int arr[5];
int head = -1;
int tail = -1;

void enqueue();
void dequeue();
void display();
void peek();       
    
int main()
{
	int choice;
	
	while(1){
	    printf("Enter your choice\n");
    	scanf("%d\n",&choice);
    	
    	switch(choice){
    	    case 1: enqueue();
    	        break;
    	      
    	    case 2: dequeue();
    	        break;
    	        
    	    case 3: display();
    	        break;
    	        
    	    case 4: peek();
    	        break;
    	        
    	    default: printf("Wrong entry\n");
    	        break;
    	}
}
	return 0;
}


void enqueue(){
    int a;
    
    printf("Enter a number: ");
	scanf("%d\n",&a);
	
    if(head > tail) printf("Error\n");
    else if(tail > 5) printf("Overflow\n");
    else{
          tail++;
          arr[tail] = a;
    }
    
    for(int i = head; i < tail; i++)
        printf("%d\n",arr[i]);
}

void dequeue(){
    if(head >= tail) printf("Underflow\n");
    else {
        head++;
        printf("Pop: %d\n", arr[head - 1]);
    }
}

void display(){
    int i;
    
    printf("Queue: ");
    for(i = head; i < tail; i++)
        printf("%d ",arr[i]);
        
    printf("\n");
}

void peek(){
    printf("Peek: %d\n",arr[head]);
}