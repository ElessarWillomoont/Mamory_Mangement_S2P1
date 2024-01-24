#include <stdio.h>
#include "heap.h"

int main() {
    // Initialisation du heap et stack_base
    stack_base = (const uintptr_t*)__builtin_frame_address(0);

    // Allocation de mémoire avec heap_alloc
    int *ptr1 = (int*)heap_alloc(sizeof(int));
    *ptr1 = 42;

    // Allocation de mémoire avec heap_calloc
    int *ptr2 = (int*)heap_calloc(5, sizeof(int));
    // La mémoire allouée par heap_calloc est initialisée à zéro
    for (int i = 0; i < 5; ++i) {
        printf("%d ", ptr2[i]);  // Devrait imprimer "0 0 0 0 0 "
    }
    printf("\n");

    // Reallocation de mémoire avec heap_realloc
    ptr2 = (int*)heap_realloc(ptr2, 10 * sizeof(int));
    // La nouvelle mémoire allouée par heap_realloc n'est pas initialisée
    for (int i = 0; i < 10; ++i) {
        printf("%d ", ptr2[i]);  // Les valeurs peuvent être imprévisibles
    }
    printf("\n");

    // Libération de mémoire avec heap_free
    heap_free(ptr1);
    heap_free(ptr2);

    // Collecte de la mémoire non utilisée
    heap_collect();

    // Affichage des informations sur les chunks alloués
    chunk_list_dump(&alloced_chunks, "Allocated");
    chunk_list_dump(&freed_chunks, "Freed");

    return 0;
}
