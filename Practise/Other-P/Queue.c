//Queue works on First In First Out principle
/* Operators on queue: 
    1) isempty
    2) isfull
    3) front
    4) enqueue
    5) dequeue
    could be of these forms: 
    1) linear array with front and rear element index
    2) linked list with front and rear element address, 
        and functions to insert in front and delete from rear
    3) circular array with front and rear same initially (0), 
        and changes based on addition/deletion of elements
*/
#include<stdio.h>
#include<stdlib.h>
#define max_size 100

typedef struct {
    int key;
} element;
//circular queue
typedef struct {
    element list[max_size]; 
    int front, rear;
    //front+1 index is the first one that contains value, and rear is the index that contains last value
} cqueue;

int isFull (cqueue* q){
    //if full then q.rear = max_size-1
    if(q->front == (q->rear+1)%max_size) return 1;
    else return 0;
}

int isEmpty (cqueue* q){
    if(q->front == q->rear) return 1;
    else return 0;
}

element front(cqueue* q){
    //we do % so that it keeps going round, ie, 0 after 99
    return q->list[(q->front+1)%max_size];
}

void enqueue(cqueue* q, element e){
    //we add to end of queue
    q->rear = (q->rear+1)%max_size;
    q->list[q->rear] = e;
}

void dequeue(cqueue* q){
    //we remove from beginning of queue
    q->front = (q->front+1)%max_size;
    //automatically old q->front becomes defunct
}


int main() {
    cqueue cq;
    cq.front=0;
    cq.rear=0;

    return 0;
}
