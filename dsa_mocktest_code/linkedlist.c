#include "linkedlist.h"
#include <stdio.h>

static node *create_node_for_list(process p);
// Check header files for documentation/ function description
process_linked_list *create_empty_process_linked_list() {
    process_linked_list *list=malloc(sizeof(process_linked_list));
    if(!list){
        return NULL;
    }
    list->head->next=NULL;
    list->head->previous=NULL;
    list->head->process=NULL;
    list->size=0;

    return list;
    // COMPLETE
}

bool add_first_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, 0, p);
}

bool add_last_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, list->size, p);
}

bool add_at_index_linked_list(process_linked_list *list, size_t index, process p) {
   // COMPLETE
   
   node *n=create_node_for_list(p);
   if(list->head->next==NULL){
        list->head->next=n;
        list->size=1;
        return true;
   }
   else if(index==list->size){
    node *tracker = list->head->next;
        while(tracker->next!=NULL){
            tracker=tracker->next;
        }
        n->previous=tracker;
        tracker->next=n;
        n->next=NULL;
        list->size++;
        return true;
   }
   else{
    node *tracker = list->head->next;
    while(index!=1){
        tracker=tracker->next;
        index--;
    }
    n->next=tracker->next;
    tracker->next=n;
    n->previous=tracker;
    n->next->previous=n;
    list->size++;
    return true;
   }
   return false;
   
}

bool remove_first_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
    node *tracker = list->head->next;
    list->head->next=tracker->next;
    tracker->next->previous=NULL;
    list->size--;
    *p=*(tracker->process);
    free(tracker);
    return true;
   // COMPLETE
}

bool remove_last_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
    node *tracker = list->head->next;
    while(tracker->next!=NULL){
        tracker=tracker->next;
    }
    tracker->previous->next=NULL;
    list->size--;
    *p=*(tracker->process);
    free(tracker);
    return true;
   // COMPLETE
}

size_t get_size_linked_list(process_linked_list *list) {
    return list->size;
}

void print_linked_list(process_linked_list *list) {
    node *tracker = list->head->next;
    for (int i = 0; i < list->size; ++i) {
        printf("%d => ", tracker->process->pid);
        tracker = tracker->next;
    }
    printf("%s", "\n");
}

static node *create_node_for_list(process p) {
    process *to_add_process = malloc(sizeof(process));
    if (!to_add_process) {
        return NULL;
    }
    *to_add_process = p;
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        return NULL;
    }
    new_node->process = to_add_process;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}


void destroy_linked_list(process_linked_list *list) {
    node *current = list->head->next;
    for (int i = 0; i < list->size; ++i) {
        node *next = current->next;
        free(current->process);
        current = next;
    }
    free(list->head);
    free(list);
}
