#include "Stack.h"
#include "stdio.h"
#define MAX 10

int main(){
    char opcao;
    int posicao, cont=0;

    Stack *pilha1 = Stack_create();
    Stack *pilha2 = Stack_create();
    
    while(opcao!='0'){
        scanf(" %c %i", &opcao, &posicao);
        if(opcao=='i'){
            if(!Stack_push(pilha1, posicao))
                puts("Overflow!!");
        }
        if(opcao=='r'){
            (Stack_demand(pilha1, pilha2, posicao));
            puts("");
        }
    }
    if(opcao == 0){
        Stack_destroy(pilha1);
        Stack_destroy(pilha2);
    }
    return 0;
}