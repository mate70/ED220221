#include <stdio.h>
#include <stdlib.h>
#include "GeneralizedLinkedList.h"
#include "log.h"

int main() {
	log_set_level(LOG_TRACE);
	Node *list = NULL;
	Node *list2 = NULL;
	Node *list3 = NULL;
	Node *list4 = NULL;
	Node *list5 = NULL;
	Node *list6 = NULL;
	Node *list7 = NULL;
	Node *list8 = NULL;
	Node *list9 = NULL;
	Node *list10 = NULL;
	addAtom(&list,1);
	addAtom(&list,2);
	addAtom(&list,3);
	addAtom(&list,4);
	addAtom(&list,5);
	printf("Exemplo 1 --------------");	
	printf("\nL = ");
	show(list);
	printf("\nProfundidade de L = %d", depth(list));
	printf("\nhead(L) = ");
	show(head(list));
	printf("\ntail(L) = ");
	show(tail(list));
	printf("\nhead(tail(L)) = ");
	show(head(tail(list)));	
	printf("\nExemplo 2 --------------");
	addAtom(&list4,1);
	addAtom(&list4,2);
	addList(&list3,&list4);	
	addAtom(&list5,3);
	addAtom(&list5,4);
	addList(&list3,&list5);
	printf("\nL = ");
	show(list3);
	printf("\nProfundidade de L = %d", depth(list3));
	printf("\nhead(L) = ");
	show(head(list3));
	printf("\ntail(L) = ");
	show(tail(list3));	
	printf("\nhead(tail(L)) = ");
	show(head(tail(list3)));
	printf("\nhead(head(tail(L))) = ");
	show(head(head(tail(list3))));
	printf("\nExemplo 3 --------------");		
	addAtom(&list6,1);
	addAtom(&list7,2);
	addAtom(&list7,3);
	addList(&list6,&list7);
	addAtom(&list8,4);
	addList(&list6,&list8);
	addAtom(&list9,5);
	addAtom(&list9,6);
	addList(&list8,&list9);
	addAtom(&list6,7);
	addList(&list6,&list10);
	addAtom(&list6,8);
	printf("\nL = ");
	show(list6);
	printf("\nProfundidade de L = %d", depth(list6));
	printf("\nBusca 5 na list9 = %d ", search(list9, 5));
	printf("\nBusca 4 na list5 = %i ", search(list5, 4));
	printf("\n");
}

int addAtom(Node **list, int atom) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->type = 0;
	newNode->atomList.atom = atom;
    newNode->next = NULL;

    if (*list == NULL)            //se a lista estiver vazia
        *list = newNode;    //novo nó é o primeiro
    else {
        Node *aux = *list;  //aux aponta para o primeiro

        while (aux->next != NULL){ //enquanto não for o último nó
            aux = aux->next;      //aux avança para o nó seguinte
			//printf("%d %p\n",aux->atomList.atom, aux->atomList.list);
		}
        aux->next = newNode;      //último nó aponta para o novo nó
    }
    return 1;
}

int addList(Node **list, Node **subList) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->type = 1;
	newNode->atomList.list = *subList;
    newNode->next = NULL;

    if (*list == NULL)            //se a lista estiver vazia
        *list = newNode;    //novo nó é o primeiro
    else {
        Node *aux = *list;  //aux aponta para o primeiro
        while (aux->next != NULL){ //enquanto não for o último nó
            aux = aux->next;      //aux avança para o nó seguinte
		}
        aux->next = newNode;      //último nó aponta para o novo nó
    }
    return 1;
}

Node* head(Node *list){	
	Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    newNode->type = list->type;
	if(list->type ==0){
		newNode->atomList.atom = list->atomList.atom;
	}else{
		newNode->atomList.list = list->atomList.list;
	}
    newNode->next = NULL;
	return newNode;	
}

Node* tail(Node *list){	
	return list->next;
}

/*int depth(Node *list){
	Node *aux = list;
	int max = 0;
	while(aux != NULL) {
		if(aux->type == 1) {
			int n = depth(aux->atomList.list);
			if(max<n)max=n;		
		}
		aux=aux->next;	
	}
	return max+1;
}*/

int depth(Node *list){
	Node *aux = list;
	int dN = 0, a = 1, c, c2 = -1;
	if(aux == NULL) return 0;
	
	while(a){
		// conferir na lista profundidade
		if(aux->type==1){
			c = depth(aux->atomList.list);
			c +1;
			if(c > c2) c2 = c;
		}
		aux = aux->next;
		if(aux == NULL)break;
	}
	return c2+1;
}

bool search(Node *list, int atom){
	Node *aux = list;
	if(aux == NULL) return false;
	int x = 1;
	while(aux != NULL){
		if(aux->type == 0){ 
			if(aux->atomList.atom == atom) return true;
		} else { 
			if(search(aux, atom) ){
				return true; break;
			}
		}
		aux = aux->next;
		if(aux == NULL){
			return false;
		}
	}
}

void show(Node *list){
	Node *aux = list;  //aux aponta para o primeiro
	printf("(");
    while (aux != NULL) {//enquanto não for o último nó
		if (aux->type == 0){
        	printf("%d", aux->atomList.atom); 
		}else {
			show(aux->atomList.list);
		}
    	if(aux->next == NULL){
			break;
		} else {
			printf(",");
			aux = aux->next;
		} 
	}
	printf(")");
}