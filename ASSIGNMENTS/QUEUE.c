#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;
void insert(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("%d inserted into queue.\n", value);
}
void delete()
{
    int value;
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    value = queue[front];
    printf("%d deleted from queue.\n", value);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    
    delete();
    delete();

    display();
    insert(60);
    insert(70);

    display();
    insert(80);
    delete();
    delete();
    delete();
    delete();
    delete();
    delete();
    return 0;
}
/*
SAMPLE OUTPUT:
10 inserted into queue.
20 inserted into queue.
30 inserted into queue.
40 inserted into queue.
50 inserted into queue.
Queue elements: 10 20 30 40 50
10 deleted from queue.
20 deleted from queue.
Queue elements: 30 40 50
60 inserted into queue.
70 inserted into queue.
Queue elements: 30 40 50 60 70
Queue Overflow!
30 deleted from queue.
40 deleted from queue.
50 deleted from queue.
60 deleted from queue.
70 deleted from queue.
Queue Underflow!
*/
