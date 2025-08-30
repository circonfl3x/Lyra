# Lyra
Small memory management framework for C

### About
it defines several types that help deal with arrays, linkedlists and most importantly.... strings
It isn't yet perfect... Memory-wise it seems to be stable enough, it doesn't leak any memory (if used correctly ofc this is C afterall).
There might still be weird bugs/quirks/undefined behaviour tho

### New types
It defines the following:
- `linkedlist1d` (a linkedlist with a (void*) pointer, ideal for storing integers, sequences of chars etc)
- `linkedlist2d` (a linkedlist with a (void**) pointer for everything else)
- **All the linkedlists are circular btw**
- `array1d` (an array with a (void*) pointer) (it's also typedefed to **array**)
- `array2d` (an array with a (void**) pointer) (it's typedefed to **vector**) (yeah the naming is a bit all over the place rn)
- `string` (I wanted to typedef it to array2d but for now it will remain independent)
- `filebuf` (a struct with a `string*` inside that acts as a buffer for reading in a file)

### Example usages
```C
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
```

and using filebuf is as easy as 
```C 
filebuf *f = file_openr("filepath.txt");
```

then you can just cycle through all of the lines using:
```C
for(int i = 0; i < f->size; i++){
  ....
}
```

The biggest advantage with using filebuf is that it checks for endings in files rather than a set buffer size. (I will expand on it to not just read '\n' in the future)
