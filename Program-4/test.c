#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"

void test_push(List *root)
{
    push(&root, 1);
    push(&root, 2);
    push(&root, 3);

    assert(root->x == 1);
    assert(root->next->x == 2);
    assert(root->next->next->x == 3);
    assert(root->next->next->next == NULL);
}

void test_reverse(List *root)
{
    reverseList(&root);

    assert(root->x == 3);
    assert(root->next->x == 2);
    assert(root->next->next->x == 1);
    assert(root->next->next->next == NULL);
}
void test_clear(List *root)
{
    clearList(&root);
    assert(root == NULL);
}

void test_insert(List *root)
{
    // TESTING INSERT FUNCTION WHEN LINKED LIST CONTAINS 0 ELEMENTS

    insertElement(&root, 7, 0);

    assert(root->x == 7);

    clearList(&root);

    // TESTING INSERT FUNCTION WHEN LINKED LIST CONTAINS ONE OR MORE ELEMENTS

    push(&root, 1);
    push(&root, 2);

    insertElement(&root, 7, 1);

    assert(root->x == 7);
    assert(root->next->x == 1);
    assert(root->next->next->x == 2);
    assert(root->next->next->next == NULL);

    // TESTING INSERT FUNCTION WHEN INSERTING ELEMENT BEFORE PREVIOUSLY INSERTED ELEMENT

    insertElement(&root, 111, 7);

    assert(root->x == 111);
    assert(root->next->x == 7);
    assert(root->next->next->x == 1);
    assert(root->next->next->next->x == 2);
    assert(root->next->next->next->next == NULL);
}

int main()
{
    List *root = NULL;

    // TESTING PUSH FUNCTION

    test_push(root);

    // TESTING REVERSE LIST FUNCTION

    test_reverse(root);

    // TESTING CLEAR LIST FUNCTION

    test_clear(root);

    // TESTING INSERT ELEMNT FUNCTION

    test_insert(root);

    return 0;
}
