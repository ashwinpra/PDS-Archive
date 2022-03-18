/* Creating a linked list where head is in the middle and we 
can go either left or right based on user input 
head node contains two pointers left and right, whereas all others 
contain either one of two
left =>1 , right =>0 (direction)
*/
#include<stdio.h>
#include<stdlib.h>

//Creating node structure
struct node{
    int data;
    struct node *left, *right;
};

//Declaring required functions
struct node* insertLeft(struct node*, int);
struct node* insertRight(struct node*, int);
void print(struct node*, int); 

int main() {
    int data=0, direction;
    //initializing head
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->left = NULL;
    head->right = NULL;
    while(data!=-1){
        printf("Enter data: ");
        scanf("%d",&data);
        if(data == -1) break; //terminating condition
        else{
            printf("Enter direction: ");
            scanf("%d",&direction);
            if(direction ==1) head=insertLeft(head, data);
            else if(direction ==0) head=insertRight(head, data);
        }
    }
    printf("Left linked list:  ");
    print(head,1);
    printf("Right linked list: ");
    print(head,0);
    return 0;
}

struct node* insertRight(struct node* head, int d){
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = d;
    p->left = NULL; //this is true for all,as we need to keep right pointer only
    p->right = NULL;
    //insert in end
    struct node* r = head;
    //if(head == NULL) return p; //in case it is empty linked list
    while(r->right != NULL){
        r = r->right; //to reach the last element on the right in case it is not empty
    }
    r->right = p; //new right becomes p
    return head;
}

struct node* insertLeft(struct node* head, int d){
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = d;
    p->left = NULL; 
    p->right = NULL;//this is true for all,as we need to keep left pointer only
    struct node* r = head;
    while(r->left != NULL){
        r = r->left; //to reach the last element on the left in case it is not empty
    }
    r->left = p; //new right becomes p
    return head;
}

void print(struct node* head, int dir){

    if(dir==1){
        //print left LL
        struct node* r = head;
        while(r!=NULL){
            if(r->left == NULL){
                if(r->data !=0)printf("%d-> NULL\n",r->data);
                else printf("NULL");
            }
            else {
                if(r->data !=0) printf("%d-> ",r->data);
            }
            r=r->left;
        }
    }
    else if(dir==0){
        //print right LL
        struct node* r = head;
        while(r!=NULL){
            if(r->right == NULL){
                if(r->data !=0)printf("%d-> NULL\n",r->data);
                else printf("NULL");
            }
            else {
                if(r->data !=0) printf("%d-> ",r->data);
            }
            r=r->right;
        }
    }
}