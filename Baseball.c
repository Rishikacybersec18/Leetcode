#include<stdlib.h>

void push(int val,int* top,int stack[]){
    if(*top == 99999){
        return;
    }
    stack[++*top] = val;
}

void push_char(char x,int* top,int stack[]){
    if(*top == -1){
        return;
    }
    if(x == 'C'){
        (*top)--;
    }
    if(x == 'D'){
        int twice = stack[*top];
        stack[++(*top)] = twice * 2;
    }
    if(x == '+'){
        int temp = *top;
        int num1 = stack[temp--];
        int num2 = stack[temp];

        stack[++(*top)] = num1 + num2;
    }
}

int calPoints(char** operations, int operationsSize) {
    int stack[100000];
    int top =-1;
    int i = 0,sum=0;
    while(i < operationsSize){
        if(operations[i][0] == 'C' || operations[i][0] == 'D' || operations[i][0] == '+'){
            push_char(operations[i][0],&top,stack);
        }else{
            int num = atoi(operations[i]);
            push(num,&top,stack);
        }
        i++;
    }


    if (top == -1){
        return 0;
    }
    for (i=0;i<=top;i++){
        sum += stack[i];
    }
    return sum;
}