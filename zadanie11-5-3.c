#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CTWL_OK 0
#define CTWL_FAIL 1
 

// вузол
typedef struct TWN{
  float data;
  struct TWN *prev;
  struct TWN *next;
 }TWN;
 
 
// Це керівна структура — вона не зберігає елементи напряму, а лише вказує на cur
typedef struct{
 TWN *cur;
 }CTWL;
 
 
// створює новий
CTWL *ctwl_create_empty(void){ 
	CTWL *list = (CTWL*)malloc(sizeof(CTWL));
	list->cur = NULL;
	return list;
}


// інсерт та деліт
TWN *ctwl_insert_right(CTWL* list, float val){
	TWN *new_node = (TWN*)malloc(sizeof(TWN));
	new_node->data = val;
	
	if (list->cur == NULL){
		new_node->next = new_node->prev = new_node;
		list->cur = new_node;
	} else {
		TWN *right = list->cur->next;
		
		list->cur->next = new_node;
		new_node->prev = list->cur;
		
		new_node->next = right;
		right->prev = new_node;
	}
	return new_node;
}

TWN *ctwl_insert_left(CTWL* list, float val); //nie je potrebne realizovat, ale nabuduce mozno

char ctwl_delete(CTWL* list){
	if (list->cur == NULL)
		return CTWL_OK;
	
	TWN *to_delete = list->cur;
	
	if (to_delete->next == to_delete){
		free(to_delete);
		list->cur = NULL;
		return CTWL_FAIL;
	}
	
	TWN *prev = to_delete->prev;
    TWN *next = to_delete->next;
    
    prev->next = next;
    next->prev = prev;
    
    list->cur = next;
    free(to_delete);
    
	return CTWL_OK;
}


// рандом потрібної довжини
CTWL *ctwl_create_random(unsigned int size){
    CTWL *list = ctwl_create_empty();
    for(unsigned int i = 0; i < size; ++i){
    	//float val = (float)(rand() % 100);
    	float val = ((float) rand() / RAND_MAX) * 100.0f;
    	ctwl_insert_right(list, val);
	}
	return list;
}


// руйнує
void ctwl_destroy(CTWL* list){
	if(list == NULL || list->cur == NULL)
	free(list);
	return;
	
	TWN *start = list->cur;
	TWN *node = start->next;
	
	while(node != start){
		TWN *tmp = node->next;
		free(node);
		node = tmp;
	}
	
	free(start);
	free(list);
}


// виписує
void ctwl_print(CTWL *list){
	if(list->cur == NULL){
		printf("Zoznam je prazny\n");
        return;
	}
	
	TWN *start = list->cur;
	TWN *node = start;
	do{
		printf("%.2f ", node->data);
		node = node->next;	
	} while (node != start);
	printf("\n\n");
}


// зміна курсора
void ctwl_cur_step_right(CTWL *list){
	if(list->cur != NULL)
	list->cur = list->cur->next;
}

void ctwl_cur_step_left(CTWL *list); //nie je potrebne realizovat, ale nabuduce mozno


// головна функція
void ctwl_concatenate(CTWL *a, CTWL *b);


int main(){
	srand(time(NULL));
	
	CTWL *a = ctwl_create_random(4);
	CTWL *b = ctwl_create_random(3);
	
	printf("Zoznam a pred preretazenim:\n");
	ctwl_print(a);
	
	printf("Zoznam b pred preretazenim:\n");
	ctwl_print(b);
	
	return 0;
}




