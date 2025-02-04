#include<stdlib.h>
#include<stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t** remove_nth_from_end(node_t** ll_head, int pos)
{
    if(*ll_head == NULL)
    {
        return NULL;
    }

    if((*ll_head)->next == NULL)
    {
        return NULL;
    }

    node_t* head = *ll_head;
    node_t* left = head;
    node_t* right = head;
    node_t* prev = NULL;
    int pos_count = 1;

    while(right->next != NULL)
    {
        if(pos_count == pos)
        {
            break;
        }
        right = right->next;
        pos_count+= 1;
    }

    while(right->next != NULL)
    {
        prev = left;
        left = left->next;
        right = right->next;
    }
    if(prev == NULL)
    {
        node_t** head = &left->next;
        return head;
    }
    else {
        prev->next = left->next;
    }
    left->next = NULL;
    free(left);

    return ll_head;
}


int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./a.out <int: position>");
        exit(1);
    }

    char *pos_str = argv[1];
    int pos = atoi(pos_str);

    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->value = 50;
    head->next = NULL;

    node_t *first = (node_t *)malloc(sizeof(node_t));
    first->value = 40;
    first->next = NULL;
    head->next = first;

    node_t *second = (node_t *)malloc(sizeof(node_t));
    second->value = 30;
    second->next = NULL;
    first->next = second;

    node_t *third = (node_t *)malloc(sizeof(node_t));
    third->value = 20;
    third->next = NULL;
    second->next = third;

    node_t **ll_head = &head;

    node_t **ll_head_modified = remove_nth_from_end(ll_head, pos);

    if(ll_head_modified != NULL) {
        node_t* head_modified = *ll_head_modified;
        node_t* free_node = NULL;
        while(head_modified != NULL)
        {
            printf("%d \n", head_modified->value);
            free_node = head_modified;
            head_modified = head_modified->next;
            free(free_node);
        }
    }
    return 0;
}
