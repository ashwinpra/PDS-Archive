//Stack works on Last In First Out principle
/* Operators on stack:
    1) isFull
    2) isEmpty
    3) top
    4) push
    5) pop
*/
#include<stdio.h>
#define max_size 100

//this is element of stack
typedef struct{
    int x;
    char y;
    //could have any number of elements
}element;

//this is stack
typedef struct{
    element list[max_size];
    int top; //index of topmost element
}stack;

int isFull(stack *s){
    if(s->top >= max_size-1) return 1;
    else return 0;
}

int isEmpty(stack *s){
    if(s->top == -1) return 1;
    else return 0;
}

element top(stack* s){
    //returns element at top
    return s->list[s->top];
}

void push(stack *s, element e){
    //adds element to the top of Stack
    (s->top)++;
    s->list[s->top] = e;
}

void pop(stack *s){
    //removes element from top of Stack
    (s->top)--; //simply changes the topmost index so that previously topmost one is no longer accessible
}



int main() {
    // int n;
    // scanf("%d", &n);
    //initialisation of stack
    stack st;
    st.top=-1;

    // for(int i=0;i<n;i++){
    //     element e;
    //     scanf("%d", &e.x);
    //     push(&st,e);
    // }
    // printf("The stack is: ");
    // for(int i=0;i<n;i++){
    //     printf("%d ",st.list[i+2].x);
    // }
    // ****************************************************
    //Application: we can use for parentheses matching
    char s[100];
    printf("Enter a sequence of parentheses: ");
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='[') {
            element e;
            e.y = s[i];
            push(&st,e);
        }
        if(s[i]=='}' || s[i]==')' || s[i]==']'){
            if(isEmpty(&st)) {
                printf("Not well formed because mty"); 
                return 0;
            }
            else{
                char x=top(&st).y;
                if(x=='{' && s[i]=='}') pop(&st);
                else if(x=='(' && s[i] == ')') pop(&st);
                else if(x=='[' && x==']') pop(&st);
                else{
                    printf("Not well formed");
                    return 0;
                } 
               
            }
        }
    }
    if(isEmpty(&st)==0) printf("Not well formed");
    else printf("Well formed");

    return 0;
}
