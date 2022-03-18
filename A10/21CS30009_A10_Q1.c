//Creates a sorted doubly linked list and allows user to either insert element, print list, or find minimum distance
#include<stdio.h>
#include<stdlib.h>

//creating node structure
struct node{
    int data;
    struct node *prev,*next;
};

//Declaring required functions
struct node* getTail (struct node*); //to get tail of the LL
struct node* insert(struct node*, int); //to insert element
int minDist(struct node*, struct node*, int);//to find min distance as required
void print(struct node*);//to print the LL




int main() {
    //Initialising head and tail of LL
    struct node* head = NULL, *tail = NULL;
    //running loop until user enters 4(to exit)
    int choice=0;
    while(choice!=4){
        printf("1. Insert an element\n");
        printf("2. Find minimum search distance\n");
        printf("3. Print linked list\n");
        printf("4. Exit\n");
        printf("Select your choice: ");
        scanf("%d", &choice);
        printf("\n");

        if(choice ==1){
            //insert
            int x; 
            printf("Enter value to be inserted: ");
            scanf("%d", &x);
            head = insert(head,x);
            tail = getTail(head); //there is a chance that tail has changed
        }
        else if(choice ==2){
            //find min search distance
            int y;
            printf("Enter value to check minimum search distance: ");
            scanf("%d", &y);
            int md = minDist(head,tail,y);
            printf("Minimum search distance is %d\n\n",md);
        }
        else if(choice ==3){
            //print linked list
            printf("Linked list: ");
            print(head);
            printf("\n\n");
        }
        else if(choice ==4) return 0; //exit
    }
    return 0;
}

struct node* getTail(struct node *head){
    struct node* tail = NULL;
    struct node* p = head;
    while(p!=NULL){
        if(p->next == NULL) tail =p; //condition for last node, which will be tail
        p=p->next;
    }
    return tail;
}

struct node* insert(struct node* head, int value){
        struct node* p;
        p = (struct node * )malloc(sizeof(struct node));
        p->data = value;
        p-> next = NULL; //for now we will assume this
        p->prev = NULL; //for now we will assume this
        
        struct node* r = head;
        if(head==NULL){
            //this will happen only for first element
            head=p;
            return head;
        }
        if(p->data < head->data){
            //we insert in beginning if its empty or if its less
            p->next = head;
            return p; //p becomes new head, and is returned
        }
        while(r != NULL){
            if(r->data == p->data) {
                //in this case we will return same
                return head;
            }

            else if (r->data < p->data){
                if(r->next!=NULL && r->next->data > p->data){
                    //first case: r is not end node
                    //we insert it between r and r->next
                    //r->next becomes p
                    //p->next becomes original r->next
                    //p->prev becomes r
                    //old r->next ->prev becomes p
                    struct node* temp = r->next;
                    r->next = p; 
                    p->next = temp;
                    p->prev = r;
                    temp->prev = p;
                }
                else if(r->next == NULL){
                    //second case: r is end node
                    //in this case now p becomes end node
                    r->next = p;
                    p->prev = r;
                    return head;
                }
                
            }
            r = r->next;
        }
}

int minDist(struct node* head, struct node* tail, int value){

    //first we will check if the value is even present in the linked list
    struct node* p = head;
    int flag=0;
    while(p!=NULL){
        if(value == p->data) flag++;
        p=p->next;
    }
    if(flag==0) return -1;

    else{
        //first we will loop from head to value while maintaining counter
        //then tail to value while maintaining another counter, then compare and return
        struct node* q = head;
        int d1 = 0;
        while(q!=NULL){
            //looping from head and incrementing d1 (distance from head)
            d1++;
            if(q->data == value) break; //when required value is encountered we break
            q=q->next;
        }
        struct node* r = tail;
        int d2=0;
        while(r!=NULL){
            //looping from tail and incrementing d2 (distance from tail)
            d2++;
            if(r->data == value) break; //when required value is encountered we break
            r=r->prev;
        }
        return (d1<=d2) ? d1:d2; //returns minimum of the two
    }
   
}


void print(struct node* head){
    //assigning looping variable as head
    if(head==NULL) printf("List empty");
    struct node* p = head;
    while(p != NULL){
        if(p->next==NULL) printf("%d", p->data); //last element doesnt need comma
        else printf("%d, ",p->data);
        p=p->next; //moving to next node
    }
}
