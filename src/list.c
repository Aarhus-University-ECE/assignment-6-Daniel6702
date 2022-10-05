#include <stdio.h>  /*printf*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

typedef struct node {
  int data;
  struct node *next;
} node;

void add(node *head, int x){
  /*pre: head points to the first, empty element. The last element's next is NULL
    post: a new node containing x is added to the end of the list*/
  assert(head!=NULL);
  node *p = head;
  while (p->next!=NULL) {
    p = p->next;
  } /*p points to the last element*/
  node *element = (node*) malloc(sizeof(node));
  element->next = NULL;
  element->data = x;
  p->next = element; 
}

int size(node *l){
    assert(l!=NULL); //Precondition
    int size = 0;
    while (l->next != NULL) { //loops through array until 'next' value is NULL
        size++;  //increment size with each iteration
        l = l->next; //the current node of list becomes the next node
    }
    return size;
}

void printout(node *l) {
    node *p = l->next; //skips first empty element 
    while (p != NULL) { //loops until empty element is found
        printf("\%d, ",p->data); //prints data
        p = p->next; //points to the next element in list
    }
    printf("\n");
}

int largest(node *l) {
    int max = l->next->data; //skips first empty element -> gets data next
    while (l->next != NULL) { //loops until empty element is found
        l = l -> next; //points to the next element in list
        (l->data > max) && (max = l->data); //if value at l->data is > max, its becomes new max 
    } 
    return max;
}

int main(void) {
    node *list = malloc(sizeof(node));
    list->next = NULL; /*create first, empty element*/
    add(list,1);
    add(list,3);
    add(list,2);
    add(list,5);
    add(list,4);
    add(list,6);
    add(list,3);
    add(list,1);
    add(list,2);

    printf("size: %d\n",size(list));
    printf("largest: %d\n",largest(list));
    printout(list);
    return 0;
}
