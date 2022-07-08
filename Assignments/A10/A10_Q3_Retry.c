#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node{
    int id;
    int price;
    struct node* next;
};
struct bucket{
    int range;
    struct node* list;
    struct bucket* next;
};
struct bucket* makeBuckets(struct bucket*);
void print_list(struct bucket*);
void insertItem(struct bucket*, int, int);
struct node* insertAsc(struct node*, int , int);

int main() {
    struct bucket* head = NULL;
    head = makeBuckets(head);
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);
    //Taking user input for ID and price of each item
    printf("Enter item ID and price of each item: \n");
    for(int i = 0; i < n; i++){
        int itemid, pr;
        scanf("%d %d", &itemid, &pr);
        //inserting each item using function
        insertItem(head, itemid, pr);
    }
    print_list(head);
    return 0;
}
struct node* insertAsc(struct node* head, int iid, int pr ){
    //insert in ascending order
    struct node* p = malloc(sizeof(struct node));
    p->id = iid;
    p->price = pr;
    p->next = NULL;

    if(head == NULL){
        head=p;
        return head;
    }

    struct node* r = head;
    if(p->price <= r->price){
        //we insert in beginning
        p->next = head;
        return p;
    }
    while(r != NULL){
        if(r->price == p->price) {
            //in this case we will insert it to the right of r
            struct node* temp = r->next;
            r->next = p;
            p->next = temp;
        }
        else if (r->price < p->price){
            if(r->next!=NULL && r->next->price > p->price){
                //first case: it is somewhere in between
                //we insert it between these 2
                //r -> next becomes p
                //p -> next becomes og r -> next
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

struct bucket* makeBuckets(struct bucket* head){
    struct bucket* current = head;
    for(int i = 0; i < 10;i++){
        struct bucket* new = (struct bucket*)malloc(sizeof(struct bucket));
        new->range = 500*(i+1);
        new->list = NULL;
        new->next = NULL;

        if(current==NULL){
            head = new;
            current = new;
        }
        else{
            current->next = new;
            current = new;
        }
    }
    return head;
}
void print_list(struct bucket* head){
    if(head==NULL) printf("Bucket is empty\n");
    struct bucket* p = head;
    while(p!=NULL){
        struct node* r = p->list;
        if(r!=NULL) {
            printf("Bucket %d:\n", (p->range) / 500);
            printf("Lower Limit: %d\n", p->range - 499);
            printf("Upper Limit: %d\n", p->range);
            printf("Items:\n");
        }
        while(r!=NULL){
            printf("(%d, %d)\n",r->id, r->price);
            r=r->next;
        }
        p=p->next;
    }
}

void insertItem(struct bucket* head, int iid , int pr){
    int ceilPrice = (pr/500);
    if(pr%500!=0) ceilPrice++;
    struct bucket *p = head;
    while(ceilPrice != (p->range)/500){
        p=p->next;
    }

    struct node* new = malloc(sizeof(struct node));
    p->list = insertAsc(p->list, iid, pr);
}

