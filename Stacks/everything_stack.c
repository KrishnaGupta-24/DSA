#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};
int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct stack * ptr){
    if(ptr->top=-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *ptr,int val){
    ptr->top++;
    if (isfull(ptr)){
        printf("stack is overflow");
    }
    ptr->arr[ptr->top]=val;
}
int pop(struct stack * ptr){
    if(isempty(ptr)){
        printf("Stack Underflow");
    }
    int val=ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
void traversing(struct stack * ptr){
    while(ptr->top!=-1){
        printf("%d ",ptr->arr[ptr->top]);
        ptr->top--;
    }
}
int main(){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=5;
    sp->arr=(int *)malloc(sizeof(int)*sp->size);
    int val;
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    val=pop(sp);
    printf("\nvalue popped: %d \n",val);
    printf("\n all the elements from the stack\n");
    traversing(sp);

}