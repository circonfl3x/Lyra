#include <stdio.h>
#include "lyra.h"
#include <string.h>
#include <stdlib.h>
int main(void){


    linkedlist1d l;
    ll_new(&l, sizeof(int)); //define new linkedlist1d (TYPE SIZE MUST BE PASSED)
    int a ;

    for(int i = 0; i < 60; i++){
        a = rand() % 100;
        ll_add(&l, &a); //add an element
    }
    linkedlist1d *ptr = &l;
    ll_free(&l); //free linkedlist

    linkedlist2d l2;
    ll2d_new(&l2, sizeof(char)); //define linkedlist2d (TYPE SIZE MUST BE PASSED)
    char *text = "Hello world";
    ll2d_add(&l2, text, strlen(text)); //add an element. (for linkedlist2d, you also have to pass the length (n) of what you are adding

    linkedlist2d *ptr2 = &l2;
    while(!ll2d_isnullelement(ptr2)){ //ll2disnullelement and ll1disnullelement checks if the pointer is pointing to a null element, and if so returns true
        printf("%s\n", (char*)ptr2->elem);
        ptr2 = ptr2->next;
    }
    ll2d_free(&l2); //free linkedlist


    array r;
    array1d_new(&r, sizeof(int)); //new array1d (type size MUST be passed through)
    for(int i = 0; i < 60; i++){
        
        srand(i);
        array1d_push(&r, rand() % 100); //pushing an element
        printf("%ld\n", r.data[i]); 
    }
    array1d_free(&r); //free array1d 

    vector t;
    array2d_new(&t, sizeof(char)); //new array2d
    array2d_push(&t, "Hello\0", 6); //add an element
    array2d_push(&t, "World\0", 6);
    array2d_free(&t); //free array2d

    string u; //new string
    string i;
    string_new(&i); //new string
    string_new(&u);
    //string_concat is a generic that can work with
    //char*, wchar_t* and string*
    string_concat(&i, "YOWOW");
    string_concat(&u, "Hello world");
    string_concat(&u, L"Hello world");
    string_concat(&u,&i);

    printf("%ls\n", u.data); 
    string_free(&u); //free string
    string_free(&i);
    
    return 0;
}
