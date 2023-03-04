#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct process
{
    int pid;
    int arrival_time;
    int burst_time;
} Process;

typedef struct queuenode *QueueNode;

struct queuenode
{
    Process p;
    QueueNode next;
};

typedef struct
{
    QueueNode front;
    QueueNode rear;
    int size;
} Queue;

Queue createQueue()
{
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;
    return q;
}

bool empty(Queue q)
{
    return q.front == NULL;
}

Queue enqueue(Process p, Queue q)
{
    QueueNode q1;
    q1 = (QueueNode)malloc(sizeof(struct queuenode));
    q1->p = p;
    q1->next = NULL;
    if (q.rear != NULL)
        q.rear->next = q1;
    else
        q.front = q1;
    q.rear = q1;
    q.size = q.size + 1;
    return q;
}

Queue dequeue(Queue q)
{
    QueueNode q1;
    q1 = q.front;
    q.front = q.front->next;
    q.size = q.size - 1;
    free(q1);
    return q;
}

Process front(Queue q)
{
    return q.front->p;
}

void printQueue(Queue q)
{
    QueueNode q1;
    q1 = q.front;
    while (q1 != NULL)
    {
        printf("%d ", q1->p.pid);
        q1 = q1->next;
    }
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File not found");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    Process p;
    fscanf(fp, "%d %d %d", &p.pid, &p.arrival_time, &p.burst_time);
    int time = 0;
    Queue q = createQueue();
    q = enqueue(p, q);
    Process p2;
    fscanf(fp, "%d %d %d", &p2.pid, &p2.arrival_time, &p2.burst_time);
    int time = 0;
    while (!empty(q) && n != 0)
    {
       
        if(p2.arrival_time == time)
        {
            q = enqueue(p2, q);
            n--;
            fscanf(fp, "%d %d %d", &p2.pid, &p2.arrival_time, &p2.burst_time);
        }

        Process p3 = front(q);
        p.burst_time--;
        time++;
    }
}