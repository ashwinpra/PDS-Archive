//Creates a sorted doubly linked list and allows user to either insert element, print list, or find minimum distance
#include<stdio.h>
#include<stdlib.h>

//creating node structure
struct node{
    int data;
    struct node *prev,*next;
};

//Declaring required functions
struct node* read (int);//to read linked list elements from users and return head
struct node* getTail (struct node*); //to get tail of the LL
struct node* insert(struct node*, int); //to insert element
int minDist(struct node*, struct node*, int);//to find min distance as required
void print(struct node*);//to print the LL




int main() {
    int n;
    printf("Enter size of linked list: ");
    scanf("%d", &n);
    struct node *head, *tail;
    printf("Enter elements of linked list: ");
    head = read(n);
    tail = getTail(head);

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
        }
        else if(choice ==2){
            int y;
            printf("Enter value to check minimum search distance: ");
            scanf("%d", &y);
            int md = minDist(head,tail,y);
            printf("Minimum search distance is %d\n\n",md);
        }
        else if(choice ==3){
            printf("Linked list: ");
            print(head);
            printf("\n\n");
        }
        else if(choice ==4) return 0;
    }
    
   
    
  
    return 0;
}

struct node* read(int n){
    struct node *head = NULL;
    struct node *p, *pre;
    for(int i=0;i<n;i++){
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->prev=NULL;
        p->next = NULL; //for now this is the last element so it points to nothing
        if(head == NULL) {
            //runs only in first itr
            head = p;
        }
        else{
            //runs in all other iterations
            p->prev = pre; 
            pre->next = p; //previous one points to next one
        }
        pre = p; // current one becomes previous, and moves on in next itr
        
    }
    return head;
}

struct node* getTail(struct node *head){
    struct node* tail = NULL;
    struct node* p = head;
    while(p!=NULL){
        if(p->next == NULL) tail =p; //condition for last node
        p=p->next;
    }
    return tail;
}

struct node* insert(struct node* head, int value){
        struct node* p;
        p = (struct node * )malloc(sizeof(struct node));
        p->data = value;
        p-> next = NULL; //for now we will assume this
        
        struct node* r = head;
        if(p->data < head->data){
            //we insert in beginning
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
                    struct node* temp = r->next;
                    r->next = p; 
                    p->next = temp;
                }
                else if(r->next == NULL){
                    //second case: r is end node
                    //in this case now p becomes end node
                    r->next = p;
                    return head;
                }
                
            }
            r = r->next;
        }
}

int minDist(struct node* head, struct node* tail, int value){
    //first we will loop from head to value while maintaining counter
    //then tail to value while maintaining another counter, then compare and return
    struct node* q = head;
    int d1 = 0;
    while(q!=NULL){
        d1++;
        if(q->data == value) break;
        q=q->next;
    }
    struct node* r = tail;
    int d2=0;
    while(r!=NULL){
        d2++;
        if(r->data == value) break;
        r=r->prev;
    }
    return (d1<=d2) ? d1:d2; //returns minimum of the two
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
