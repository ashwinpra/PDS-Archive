#include<stdio.h>
#include<stdlib.h>
struct node{
    int x;
    struct node *next;
};

struct node* read(int n){
    struct node* head = NULL, *prev, *p;
    for(int i=0; i<n; i++){
        p = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &p->x);
        if(head==NULL) head=p;
        else prev->next = p;
        prev = p;
    }
    return head;
}

void print(struct node *head){
    struct node* p = head;
    while(p != NULL){
        printf("%d ", p->x);
        p = p->next;
    }
}

void checkOrder(struct node *head){
    //check if LL is in increasing order, decreasing order, or none
    int inc=0,dec=0;
    struct node*p = head;
    while(p!=NULL){
        if(p->x < p->next->x) inc++;
        else if(p->x > p->next->x) dec++;
        else{
            printf("Neither increasing nor decreasing");
            return;
        }
    }
    if(inc==0){
        //was full decreasing
        printf("Decreasing linked list");
        return;
    }
    else if(dec==0){
        //was full increasing
        printf("Increasing linked list");
        return;
    }
    else{
            printf("Neither increasing nor decreasing");
            return;
        }
}

void maxAndMin(struct node* head, int *ma, int *mi){
    //iterate through like array and find
    int *m,*n;
    struct node* p = head;
    int max = -10000, min = 10000;
    while(p != NULL){
        if(max<p->x) max = p->x;
        if(min>p->x) min = p->x;
        p=p->next;
    }
    m = &max;
    n = &min;
}

struct node* insertBegin(struct node* head, int value){
    //insert in beginning
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->x = value;
    p ->next = head;
    return p; //p becomes new head
}

int search(struct node* head, int value){
    //searches for value in node and returns address of the node containing it
    //if not present, returns NULL (ie last value of p)
    struct node* p = head;
    while(p!=NULL){
        if(p->x == value) return 1; 
        p = p->next;
    }
    return 0; //will reach here if value not present, so returns NULL
}
struct node* delete(struct node* head, int value){
    //we need the previous pointer to delete to the next one(one after the deleted)

        struct node *p = head, *q;
        q=p;
        while(p!=NULL){
            if(p->x == value){
                if(p==head) head = p->next; //it is in the starting
                else q->next = p->next; //it is in the middle
                //we are assigning the previous node the pointer to the
                //node present after the deleted node
                p->next = NULL; //now p does not exist
                free(p); //we free it 
                return head;
            }
            else{
                q=p;
                p=p->next;
                //q is one element behind p, unless it is first itr
            }
        }

        
}

struct node* swap (struct node* a, struct node *b){
    struct node* temp = a->next;
    a->next = b->next;
    b->next = temp;
    return b;
}
struct node* sort(struct node* head, int n){
    //just switch the addresses i think 
    for(int i=0;i<n-1;i++){
        struct node* p = head;
        int j=0;
        while(j<n-i-1 && p->next!=NULL){
            if(p->x > p->next->x){
                int temp=p->x;
                p->x = p->next->x;
                p->next->x=temp;
        }
        p=p->next;
        j++;
        }
    }
    return head;
}

void un(struct node* head1, struct node* head2){
    //we will make a new linked list to store it 
    struct node* unionLL = NULL;
    int count=0;
    struct node* p = head1;
    /* Search every element of LLOne in LLTwo, 
    If found then add it to intersection List */
    while(p != NULL){
        if(search(head2, p->x)){
            unionLL = insertBegin(unionLL, p->x);
            count++;
            //printf("Inserting %d",head1->x);
        }
        else{
            count++;
            unionLL = insertBegin(unionLL, p->x);
        } 
        p = p->next;
    }
    struct node* q = head2;
    //traverse through head2 and if not there in unionLL then insert
    while(q != NULL){
        if(!(search(unionLL,q->x))) {
            count++;
            unionLL = insertBegin(unionLL,q->x);
        }
        q=q->next;
    }
    unionLL = sort(unionLL,count);
    print(unionLL);
}

void in(struct node* head1, struct node* head2){
    struct node *intersectionLL = NULL;
    struct node* p = head1;
    int count=0;
    /* Search every element of LLOne in LLTwo, 
    If found then add it to intersection List */
    while(p != NULL){
        if(search(head2, p->x)){
            intersectionLL = insertBegin(intersectionLL, p->x);
            count++;
            //printf("Inserting %d",head1->x);
        }
        p = p->next;
    }
    intersectionLL = sort(intersectionLL,count);
    print(intersectionLL);
    // return intersectionLL;
}




int main() {
    // int n;
    // scanf("%d", &n);
    // struct node* h = read(n);
    // checkOrder(h);
    // int max,min;
    // maxAndMin(h,&max,&min);
    // printf("Maximum is %d and minimum is %d",max,min);
    int m,n;
    scanf("%d %d", &m, &n);
    struct node* h1 = read(m);
    struct node* h2 = read(n);
    //struct node* h_union = un(h1,h2);
    //struct node* h_intersection = in(h1,h2);
    print(h1);
    printf("\n");
    print(h2);
    printf("\n");
    printf("Union is : ");
    un(h1,h2);
    printf("\nIntersection is : ");
    in(h1,h2);
    //print(h_intersection);


    return 0;
}
