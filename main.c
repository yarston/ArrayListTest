
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

ArrayList* getFast(size_t size) {
    ArrayList *list = NEW_ARRAY_LIST(size, unsigned);
    list->size = list->sizeMax;
    int i = 0;
    FOR(unsigned, el, list) *el = i++ * 10;
    return list;
} 

ArrayList* getSlow(size_t size) {
    ArrayList *list = NEW_ARRAY_LIST(256, unsigned);
    for(size_t i = 0; i < size;) *((unsigned*) add2ArrayList(list)) = i++ * 10;
    return list;
}

int main(int argc, char** argv) {
    //ArrayList *list = getSlow(100000000);
    ArrayList *list = getSlow(100000000);
    CONVERT_VEC_TYPE(unsigned, in, list, unsigned, out, list2) *out = *in + 1;
    for(int i = 0; i < 10; i++) printf("el = %d\n", ((unsigned*) list2->data)[i]);
    return (EXIT_SUCCESS);
}

