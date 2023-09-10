#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // pointer to a char, which gets contigous blocks of memory addresses
    // by malloc of len 4 here
    char *bob = malloc(sizeof(char) * 4);
    // copy the string literal "bob"
    strncpy(bob, "bob", 3);

    // so just printing the whole string will give bob with %s format specifier
    printf("%s\n", bob);
    
    // lets validate the same by performing pointer arithmetic and incrementing
    // the pointer address locations and printing the char at each memory
    // address until \0 (null)
    
    // lets preserve the original location of begin pointer to "bob", i.e. to
    // the char b, and perform increments on a temporary pointer
    // Pointer B = 'b'
    // Pointer B + 1 = 'o'
    // Pointer B + 2 = 'b'
    // Pointer B + 3 = '\0'
    char *bob_temp = bob;
    while (*bob_temp != 0) {
        printf("%c", *bob_temp);
        bob_temp += 1;
    }
    printf("\n");
    free(bob);
    bob = bob_temp = NULL;

    // now this makes it quite rewarding to think that similar to a pointer
    // with valid memory address can be used to navigate the blocks and access
    // its data, the pointers can have a list of pointers to traverse through
    // as well.
    // a pointer A to a pointer B (lets say char type)
    // this makes a matrix! Visualize it with following pointer A list of names
    // Pointer A -> Pointer B = 'j'
    // Pointer A -> Pointer B + 1 = 'i'
    // Pointer A -> Pointer B + 2 = 'm'
    // Pointer A -> Pointer B + 3 = '\0'
    // Pointer A + 1 -> Pointer B = 'a'
    // Pointer A + 1 -> Pointer B + 1 = 'l'
    // Pointer A + 1 -> Pointer B + 2 = 'i'
    // Pointer A + 1 -> Pointer B + 3 = 'c'
    // Pointer A + 1 -> Pointer B + 4 = 'e'
    // Pointer A + 1 -> Pointer B + 5 = '\0'

    // !!! NOTE the syntax
    // ** is for the Pointer A
    char **names = malloc(sizeof(char) * 2);
    // * is for the Pointer B
    // names + i is the Pointer A with increments to its memory location
    // *(names + i) derefernces the pointer A and we access the value at the 
    // memory location for the Pointer A and malloc space for the Pointer B
    *(names + 0) = malloc(sizeof(char) * 4);
    *(names + 1) = malloc(sizeof(char) * 6);

    // instead of writing *(names + i) every where, lets copy these address
    // locations to readable names
    // on a sidenote, this should give you an idea how this got its own
    // syntactical sugar of Arrays [] to access values, if you do not already
    // know
    char *jim = *(names + 0);
    char *alice = *(names + 1); // can be written as char *alice = names[1];
                                // but lets keep this notation for arrays
                                // when we talk about arrays

    strncpy(jim, "jim", 3);
    strncpy(alice, "alice", 5);

    printf("%s\n", jim);
    printf("%s\n", alice);

    // Lets iterate with pointer arithmetic similar to pointer
    // visualizer comment above
    for (int i = 0; i < 2; i++) {
        char *curr_name = *(names + i);
        while (*curr_name != 0) {
            printf("%c", *curr_name);
            curr_name += 1;
        }
        printf("\n");
    }

    // easy free
    for (int i = 0; i < 2; i++) {
        free(*(names + i));
    }
    free(names);
    names = NULL;
    jim = alice = NULL;

    return EXIT_SUCCESS;
}

