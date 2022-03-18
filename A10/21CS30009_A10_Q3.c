//Create a nested link list to store items of same price range together
//Price range varies from 0 to 500
#include<stdio.h>
#include<stdlib.h>

//Declaring inner node
struct node{
    int itemID, price;
    struct node* next;
};
//Declaring bucket
struct bucket{
    int range;
    struct node* hd; //has to only store the head, the rest can be accessed from it 
    struct bucket* next;
};


//Declaring required functions
void insert (struct bucket*, int, int); //to insert into bucket
struct node* insertInner(struct node*,int,int); //to insert into inner LL
void printTuple(struct bucket*); //prints the itemid and price of each bucket
int main() {
   
    //initialising head bucket
    struct bucket *h=NULL;
    //Declaring number of items and taking user input
    int n;
    printf("Enter number of items: "); 
    scanf("%d", &n);
    //Taking user input for ID and price of each item
    printf("Enter item ID and price of each item: \n");
    for(int i = 0; i < n; i++){
        int itemid, pr;
        scanf("%d %d", &itemid, &pr);
        //inserting each item using function
        insert(h, itemid, pr);
    }
    //printing the buckets one by one
    struct bucket* r = h;
    int j=1;
    while(r!=NULL){
        printf("Bucket %d: \n",j);
        int lower = (r->range ==500) ? 0: (r->range)-499;
        printf("Lower limit: %d\nUpper limit: %d\n",lower,(r->range));
        printf("Items: \n");
        printTuple(r);
        j++;
        r=r->next;
    }
    return 0;
}
//used same as that in Q1 with some modifications based on question
struct node* insertInner(struct node* head, int itemID, int price){
        struct node* p;
        p = (struct node * )malloc(sizeof(struct node));
        p->itemID = itemID;
        p->price = price;

        struct node* r = head;
        if(head==NULL){
            //this will happen only for first element
            head=p;
            return head;
        }
        if(p->price < head->price){
            //we insert in beginning if its empty or if its less
            p->next = head;
            return p; //p becomes new head, and is returned
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
                    //first case: r is not end node
                    //we insert it between r and r->next
                    //r->next becomes p
                    //p->next becomes original r->next
                    //p->prev becomes r
                    //old r->next ->prev becomes p
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
        return head;
}


void insert (struct bucket *head, int itemID, int price){
    //we will give each bucket an index which is range/500
    //then we will iterate from 1 to price/500 and create buckets if required
    int x = price/500;
    if(x%500!=0) price++; //to add 1 to x so that it represents index it belongs to
    if(x==1){
        //we can insert it directly in first bucket
        head->range = 500;
        head->hd = insertInner(head->hd, itemID, price);
        head->next = NULL;
    }
    else{
        struct bucket* r= head;
        for(int i=1; i<=x;i++){
            //to fill any buckets that may come before required bucket
            if(r->next==NULL && i!=x){
                //we will create new bucket and assign to it
                struct bucket* new;
                new=(struct bucket*)malloc(sizeof(struct bucket));
                new->range = r->range +500;
                new->hd = NULL;
                new->next=NULL;
                r->next=new;
            }
            //to be executed when we reach required bucket
            if(i==x){
                r->range = i*500;
                r->hd = insertInner(r->hd, itemID,price);
                r->next = NULL;
                break;
            }
            r=r->next;
        }

    }
    }

void printTuple (struct bucket* head){
    struct bucket* r= head;
    while(r!=NULL){
        struct node* p = r->hd;
        while(p!=NULL){
            printf("(%d, %d)\n",p->itemID,p->price);
            p=p->next;
        }
        r=r->next;
    }
}