# include <stdio.h>

// uzol
typedef struct TWN{
  float data;
  struct TWN *prev;
  struct TWN *next;
 }TWN;
 
// cely zoznam
typedef struct{
 TWN *cur;
 }CTWL;
 
// створює новий
CTWL *ctwl_create_empty(void);

// рандом потрібної довжини
CTWL *ctwl_create_random(unsigned int size);

// руйнує
void ctwl_destroy(CTWL* list);

// vypis
void ctwl_print(CTWL *list);

// зміна курсора
void ctwl_cur_step_right(CTWL *list);
void ctwl_cur_step_left(CTWL *list);

// інсерт деліт
TWN *ctwl_insert_left(CTWL* list, float val);
TWN *ctwl_insert_right(CTWL* list, float val);
char ctwl_delete(CTWL* list);

// головна функція
void ctwl_concatenate(CTWL *a, CTWL *b);

int main(){
	
}