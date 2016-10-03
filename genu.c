#include <stdio.h>
#include <stdlib.h>
#define COUNT 3 
struct elem {int key; int data;} Table[COUNT];
int key_compare(const void* e1, const void* e2);

int main(void)
{
    Table = {0, 42, 432};
    struct elem* result;
    struct elem key_elem;
    key_elem.key = 11;

    result = (struct elem *) bsearch(&key_elem, &Table[0], COUNT, sizeof(struct elem), key_compare);
    printf("%d\n", result->data);
    return 0;
}

int key_compare(const void* e1, const void* e2)
{
    int v1 = ((struct elem *)e1)->key;
    int v2 = ((struct elem *)e2)->key;
    return (v1 < v2) ? -1: (v1 > v2) ? 1: 0;
}
