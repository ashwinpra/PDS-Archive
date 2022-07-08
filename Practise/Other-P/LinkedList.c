/* We will make a linked list and perform the following functions: 
 1) print 
 2) search for a value in it 
 3) insert in element in start, end or somewhere in middle (based on some condition)
 4) delete an element 
 5) reverse a linked list
 */
#include<stdio.h>
#include<stdlib.h>


//this is a linked list element
struct node{
    int x;
    struct node* next;
};

void print(struct node *head){
    struct node* p = head;
    while(p != NULL){
        printf("%d ", p->x);
        p = p->next;
    }
}
//reads a linked list and returns head
struct node* read(int n){
    //we declare "head" as pointer to first element and preserve it 
    //later we assign a dummy variable to it and keep changing it
    struct node* head = NULL, *p, *prev;
    for(int i=0;i<n;i++){
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->x);
        p->next = NULL; //for now this is the last element so it points to nothing
        if(head == NULL) head = p; //runs only in first itr
        else prev->next = p; //previous one points to next one, in first itr there is no prev
        prev = p; // current one becomes previous, and moves on in next itr
    }
    return head;
}

struct node* search(struct node* head, int value){
    //searches for value in node and returns address of the node containing it
    //if not present, returns NULL (ie last value of p)
    struct node* p = head;
    while(p!=NULL){
        if(p->x == value) return p; 
        p = p->next;
    }
    return p; //will reach here if value not present, so returns NULL
}

struct node* insertBegin(struct node* head, int value){
    //insert in beginning
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->x = value;
    p ->next = head;
    return p; //p becomes new head
}

struct node* insertEnd(struct node* head, int value){
    //insert in end
    struct node* p;
    p = (struct node * )malloc(sizeof(struct node));
    p->x = value;
    p->next = NULL;
    struct node* r = head;
    if(head == NULL) return p; //in case it is empty linked list
    while(r->next != NULL){
        r = r->next;
    }
    r->next = p; //it is changed from NULL to p
    return head;
}   

struct node* insertAsc(struct node* head, int value){
    //insert in ascending order
        struct node* p;
        p = (struct node * )malloc(sizeof(struct node));
        p->x = value;
        p-> next = NULL; //for now we will assume this
        
        struct node* r = head;
        if(value <= head->x){
            //we insert in beginning
            return insertBegin(head,value);
        }
        while(r != NULL){
            if(r->x == p->x) {
                //in this case we will insert it to the right of r
                struct node* temp = r->next;
                r->next = p; 
                p->next = temp;
            }
            else if (r->x < p->x){
                if(r->next!=NULL && r->next->x > p->x){
                    //first case: it is somewhere in between
                    //we insert it between these 2
                    //r ka next becomes p
                    //p ka next becomes r ka next
                    struct node* temp = r->next;
                    r->next = p; 
                    p->next = temp;
                }
                else if(r->next == NULL){
                    //second case: it is at the end
                    r->next = p;
                    return head;
                }
                
            }
            r = r->next;
        }
        return head;
}

struct node* delete(struct node* head, int value){
    //we need the previous pointer to delete to the next one(one after the deleted)

    if(search(head,value)==NULL) {
        printf("Invalid value\n");
        return head;
    }
    else{
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

        
}

struct node* reverse(struct node* head){
    struct node* current = head;
    struct node *prev = NULL, *next = NULL;
  
        while (current != NULL) {
            // Store next
            next = current->next;
  
            // Reverse current node's pointer
            current->next = prev;
  
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        return prev;

}



int main() {
    int n;
    scanf("%d", &n);
    struct node* h = read(n);
    print(h);
    printf("\n");
    h=insertBegin(h,4);
    print(h);
    printf("\n");
    insertEnd(h,10);
    printf("\n");
    h=insertAsc(h,3);
    print(h);
    printf("\n");
    h=reverse(h);
    print(h);
    return 0;
}
