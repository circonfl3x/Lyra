#include <stdio.h>
#include "lyra.h"
#include <string.h>
#include <stdlib.h>
int main(void){

    linkedlist1d l;
    ll_new(&l, sizeof(int));
    int a = 5;
    ll_add(&l, &a);
    a+=9;
    ll_add(&l, &a);
    for(int i = 0; i < 60; i++){
        a = rand() % 100;
        ll_add(&l, &a);
    }
    linkedlist1d *ptr = &l;
    ll_free(&l);
    linkedlist2d l2;
    ll2d_new(&l2, sizeof(char));
    char *text = "Hello world";
    ll2d_add(&l2, text, strlen(text));
    text = "Goodbye world";
    ll2d_add(&l2, text, strlen(text));
    linkedlist2d *ptr2 = &l2;
    while(!ll2d_isnullelement(ptr2)){
        printf("%s\n", (char*)ptr2->elem);
        ptr2 = ptr2->next;
    }
    ll2d_free(&l2);


    array r;
    array1d_new(&r, sizeof(long));
    for(int i = 0; i < 60; i++){
        srand(i);
        array1d_push(&r, rand() %100);
    }
    array1d_free(&r);

    vector t;
    array2d_new(&t, sizeof(char));
    array2d_push(&t, "Hello\0", 6);
    array2d_push(&t, "World\0", 6);
    array2d_free(&t);

    string u;
    string i;
    string_new(&i);
    string_new(&u);
    string_concat(&i, "YOWOW");
    string_concat(&u, "Hello world");
    string_concat(&u, L"Hello world");
    string_concat(&u,&i);

    printf("%ls\n", u.data); 
    string_free(&u);
    string_free(&i);
    
    return 0;
}
