#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "linked_list.h"


List *create_list() {
    List *new_list = malloc(sizeof(List));
    Node *first = create_node();
    new_list->first=first;
    return new_list;
}

Node *create_node() {
    Node *temp = malloc(sizeof(Node));
    temp->next=NULL;
    return temp;
}

void delete_list(List *list) {
    Node *node = list->first;
    Node *next;
    while(node) {
        next = node->next;
        delete_node(node);
        node=next;
    }
    free(list);
}

void remove_node(List *list, unsigned int pid) {
    Node *node = list->first;
    Node *temp;
    while(node->next != NULL) {
        if(node->pid == pid) {
            temp = node->next;
            node->next=node->next->next;
        }
        node=node->next;
    }
    free(temp);
}

void delete_node(Node *node) {
    free(node);
}

void append_list(List *list, unsigned int pid,unsigned int status) {
    Node *node = list->first;
    while(node->next != NULL) { node=node->next; }
    node->pid=pid;
    node->status=status;
    node->returncode=(int)NULL;
    node->next=create_node();
}

Node *pop(List *list) {
    Node *temp = list->first;
    Node *new_first=temp->next;
    list->first=new_first;
    return temp;
}

Node *peek(List *list) { return list->first; }

Node *get_element(List *list, int element) {
    Node *node = list->first;
    int i = 0;
    while(i < element && node != NULL) { node=node->next; i++; }
    return node;
}

Node *find_status(List *list, unsigned int status) {
    Node *node = list->first;
    while(node->next != NULL) {
        if(node->status == status) { return node; }
        node=node->next;
    }
    return NULL;
}

Node *find_pid(List *list, unsigned int pid) {
    Node *node = list->first;
    while(node->next != NULL) {
        if(node->pid == pid) { return node; }
        node=node->next;
    }
    return NULL;
}

int print_list(List *list) {
    Node *node = list->first;
    int i=0;
    while(node->next != NULL) {
        printf("Pid: %d\tStatus: %d\n",node->pid, node->status);
        node = node->next;
        i++;
    }
    printf("\n");
    return i-1;
}
void print_node(Node *node) { 
    if(node->returncode=(int)NULL)
        printf("Pid: %d\tStatus: %d\tReturn Code: NULL\n",node->pid,node->status); 
    else
        printf("Pid: %d\tStatus: %d\tReturn Code: %d\n",node->pid,node->status,node->returncode); 

}
/*
int main(int argc, char *argv[]) {
    List *list = create_list();
    int i;
    for(i = 0; i < argc; i++) {
        append_list(list,i,i*2);
    }
    int num = print_list(list);
    printf("%i arguments printed\n\n\n",num);

    remove_node(list,4);

    print_list(list);



    delete_list(list);
}
*/
