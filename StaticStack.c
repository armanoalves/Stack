#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct stack{
    int index;
    int data[MAX];

};
//Alocamento de memoria e criação da pilha.
Stack* Stack_create(){
    Stack* nova = malloc(sizeof(Stack));
    if(nova){
        nova->index = -1;
    } return nova;
}
// Inserção de informações na pilha.
int Stack_push(Stack* stack, int info){
    if(!Stack_full(stack)){
        stack->index++;
        stack->data[stack->index] = info;
        return 1;
    }return 0; //overflow
}
// Retirada de informações de dentro da pilha.
int Stack_pop(Stack* stack, int* info){
    if(!Stack_empty(stack)){
        *info = stack->data[stack->index];
        stack->index--;
        return 1;
    }
    return 0; //underflow
}
/*Parte responsavél por retirar os valores da pilha até encontrar o que foi 
* 
requerido e logo após inserir os valores novamente na pilha pricipal.*/
int Stack_demand(Stack* stack, Stack* stack2, int info){
    int temp;
    while(Stack_pop(stack,&temp)){
        printf("%i,",temp);
        if(temp!=info){
            Stack_push(stack2,temp);
        }else{
          break;
        }
    }
    if(temp != info){
        printf("underflow");
    }
    while(Stack_pop(stack2,&temp)){
        Stack_push(stack,temp);
    }
    return 0;
}

int Stack_head(Stack* stack, int* info){
    if(!Stack_empty(stack)){
        *info = stack->data[stack->index];
        return 1;
    }   return 0;
}
void Stack_destroy(Stack* stack){
    free(stack);
}
int Stack_full(Stack* stack){
    return stack->index == MAX-1;
}
int Stack_empty(Stack* stack){
    return stack->index == -1;
}
int Stack_qty(Stack* stack){
    return stack->index+1;
}