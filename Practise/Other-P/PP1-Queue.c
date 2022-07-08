#include<stdio.h>
#define max_size 100
/*
Implement a Priority Queue which maintains the items in an order (ascending/ descending) 
and has additional functions like remove_max and remove_min
*/
//we will make a queue like linear array
typedef struct{
    int x[max_size];
    int front,  rear;
}queue;

void printQueue(queue* q){
    for(int i=(q->front)+1;i<=q->rear;i++){
        printf("%d ",q->x[i]);
    }
}

void removeMax(queue *q){
    for(int i=(q->front)+1;i<=q->rear;i++){
        //first findmax, then remove
    }
}

int isFull (queue* q){
    //if full then q.rear = max_size-1
    if(q->rear >= max_size) return 1;
    else return 0;
}
int isEmpty (queue* q){
    if(q->front >= q->rear) return 1;
    else return 0;
}
int front (queue*q){
    return q->x[(q->front)+1];
}
void enqueue(queue* q, int e){
    //we add to end of queue
    (q->rear)++;
    q->x[q->rear] = e;
}

void dequeue(queue* q){
    //we remove from beginning of queue
    (q->front)++;
    //automatically old q->front becomes defunct
}

int main() {
    int n;
    scanf("%d",&n);
    queue q;
    q.front=0;
    q.rear=0;
    for(int i=0;i<n;i++){
        int j;
        scanf("%d",&j);
        enqueue(&q,j);    
    }
    printf("The queue is: ");
    printQueue(&q);
    printf("\n");
    return 0;
}
