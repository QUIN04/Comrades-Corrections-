#include<stdio.h>
#include<stdlib.h>
#define size 10
void enqueue();
void dequeue();
void display();
void exit();
int main()
{
int front =-1;
int rear =-1;
int arr[size];
int choice;
printf("1.Enqueue\n");
printf("2. dequeue\n");
printf("3. display\n");
printf("4.exit\n");
scanf("%d",&choice);
switch(choice)
{
	case 1:
		enqueue();
		break;
		case 2:
			dequeue();
			break;
			case 3:
				display();
				break;
				case 4:
					exit(0);
					default:
						printf("wrong choice\n");

}
void display()
{
	int i;
	if(front ==-1)
	print("Queue overflow\n");
	else
	printf("the elements in the queue are..");
	for(i=front;i>=0;i--)
	printf("%d",arr[i]);
}
void enqueue()
{
	if(front ==rear)
	printf("Queue overflow");
	else
	{

	int x;
	printf("enter the element to enqueue in the queue\n");
	scanf("%d",&x);
	arr[front]=x;
	front = front +1;
}
void dequeue()
{
if(front==-1)
printf("the queue is empty\n");
int x = arr[front];
printf("dequeuing %d from the array",x);
front =front-1;
}
}
}
