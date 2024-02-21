#include "StrList.h"
#include <stdio.h>
#include <string.h>

#define True 1
#define False 0

typedef struct _node {
    const char* _data;
    struct _node * _next;
} Node;

Node* Node_alloc(const char* data, Node* next) {
    Node* n = (Node*)malloc(sizeof(Node));

    if(n == NULL){
        return NULL;
    }

    n->_data = data;
    n->_next = next;
    return n;
}

void Node_free(Node* node) {
    free((char*)node->_data);
    free(node);
}


/*
 * StrList represents a StrList data structure.
 */
struct _StrList {
    Node* _head;
    int _size;
};

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc(){
    StrList* s = (StrList*)malloc(sizeof(StrList));

    if(s == NULL){
        return NULL;
    }

    s->_head = NULL;
    s->_size = 0;
    return s;
}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList){

    if (StrList==NULL){
        return;
    }

    Node* p1 = StrList->_head;
    Node* p2;
    while(p1 != NULL) {
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    free(StrList);
}

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* StrList){
    return StrList->_size;
}

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* StrList, const char* data){

    int size = (int) StrList_size(StrList);
    StrList_insertAt(StrList, data, size);
//    printf("data %s\n", data);
//    StrList_printAt(StrList, (int) StrList_size(StrList) - 1);

}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList, const char* data,int index) {

    //Out of range index
    if (index < 0 || index > StrList->_size) {
        return;
    }

    Node *node = Node_alloc(data, NULL);
    //printf("something %s", node->_data);

    if(index == 0){
        node->_next = StrList->_head;
        StrList->_head = node;
    }

    else{
        Node* current_node = StrList->_head;
        for (int i = 0; i < index - 1; i++) {
            current_node = current_node->_next;
        }
        node->_next = current_node->_next;
        current_node->_next = node;
    }

    StrList->_size++;

}

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList){
    return (char*)StrList->_head->_data;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList){
    Node* current_node = StrList->_head;

    for(int i = 0; i < StrList->_size - 1; i++){
        printf("%s ", current_node->_data);
        current_node = current_node->_next;
    }
    printf("%s", current_node->_data);

}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index){

    //Out of range index
    if (index < 0 || index > Strlist->_size) {
        return;
    }

    Node* current_node = Strlist->_head;

    for(int i = 0; i < index - 1; i++){
        current_node = current_node->_next;
    }

    printf("%s\n", current_node->_data);
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist){
    int counter = 0;

    Node* current_node = Strlist->_head;

    for(int i = 0; i < Strlist->_size; i++){
        counter += strlen(current_node->_data);
        current_node = current_node->_next;
    }

    return counter;
}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data){
    int counter = 0;

    Node* current_node = StrList->_head;

    for(int i = 0; i < StrList->_size; i++){
        if(strcmp(data, current_node->_data)){
            counter++;
        }
        current_node = current_node->_next;
    }

    return counter;
}

/*
	Given a string and a list, remove all the appearances of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data){

    Node* current_node = StrList->_head;
    Node* previous_node = NULL;

    while(current_node != NULL){
        if(strcmp(data, current_node->_data)){
            if(previous_node == NULL){
                StrList->_head = current_node->_next;
                free(current_node);
                current_node = StrList->_head;
            }

            else{
                previous_node->_next = current_node->_next;
                free(current_node);
                current_node = previous_node->_next;

            }

            StrList->_size--;
        }

        else{
            previous_node = current_node;
            current_node = current_node->_next;
        }
    }

}

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index){

    //Out of range index
    if (index < 0 || index > StrList->_size) {
        return;
    }

    Node* current_node = StrList->_head;
    Node* previous_node = NULL;

    for(int i = 0; i < index; i++){
        previous_node = current_node;
        current_node = current_node->_next;
    }

    if(previous_node == NULL){
        StrList->_head = current_node->_next;
    }
    else{
        previous_node->_next = current_node->_next;
    }

    free(current_node);
    StrList->_size--;
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1->_size != StrList2->_size){
        return False;
    }

    Node* current_node1 = StrList1->_head;
    Node* current_node2 = StrList2->_head;

    for(int i = 0; i < StrList1->_size; i++){
        if(!strcmp(current_node1->_data, current_node2->_data)){
            return False;
        }

        current_node1 = current_node1->_next;
        current_node2 = current_node2->_next;
    }

    return True;
}

/*
 * Clones the given StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrList){
    struct _StrList *StrListClone;
    StrListClone = StrList_alloc();

    Node* current = StrList->_head;
    Node* currentClone = NULL;

    while(current != NULL){
        Node* node = Node_alloc(current->_data, NULL);

        if (StrListClone->_head == NULL) {
            StrListClone->_head = node;
            currentClone = StrListClone->_head;
        }

        else {
            currentClone->_next = node;
            currentClone = currentClone->_next;
        }

        StrListClone->_size++;
        current = current->_next;
    }

    return StrListClone;
}

/*
 * Reverces the given StrList.
 */
void StrList_reverse( StrList* StrList){
    Node* prev = NULL;
    Node* current = StrList->_head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }

    StrList->_head = prev;
}

/*
 * Sort the given list in lexicographical order
 */
void StrList_sort( StrList* StrList){

    if (StrList->_head == NULL || StrList->_head->_next == NULL) {
        return; // The list is empty or has a single element
    }

    // Using bubble sort
    int swapped;
    Node *current;
    Node *last_swapped_node = NULL;

    do {
        swapped = 0;
        current = StrList->_head;

        while (current->_next != last_swapped_node) {
            if (strcmp(current->_data, current->_next->_data) > 0) {

                // Swap data
                const char* tempData = current->_data;
                current->_data = current->_next->_data;
                current->_next->_data = tempData;

                swapped = True;
            }

            current = current->_next;
        }

        last_swapped_node = current;

    } while (swapped);

}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList){
    if (StrList->_head == NULL || StrList->_head->_next == NULL) {
        return True; // The list is empty or has a single element
    }

    Node *current = StrList->_head;
    while (current != NULL && current->_next != NULL) {
        if (strcmp(current->_data, current->_next->_data) > 0) {
            return False; // Not sorted
        }
        current = current->_next;
    }
    return True; // Sorted
}

