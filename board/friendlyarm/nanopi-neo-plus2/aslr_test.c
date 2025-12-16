#include <stdio.h>
#include <stdlib.h>

// 1. ZONE EXECUTABLE (Data Segment)
// Une variable globale est stockée dans l'image même du programme.
int global_var = 42;

int main() {
    // 2. ZONE STACK (Pile)
    // Une variable locale est stockée sur la pile.
    int local_var = 10;

    // 3. ZONE HEAP (Tas)
    // Une allocation dynamique se fait dans le tas.
    void *heap_var = malloc(16);

    printf("=== Verification ASLR ===\n");

    // Affiche l'adresse dans l'exécutable (nécessite PIE pour changer)
    printf("1. Executable (Global var): %p\n", &global_var);
    printf("   Executable (Main func):  %p\n", main);

    // Affiche l'adresse de la Stack [cite: 55]
    printf("2. Stack (Local var):       %p\n", &local_var);

    // Affiche l'adresse du Heap 
    printf("3. Heap (Malloc):           %p\n", heap_var);

    // 4. ZONE SHARED LIBRARIES (Bibliothèques partagées) 
    // Affiche l'adresse d'une fonction de la LibC (ex: printf)
    printf("4. Shared Lib (printf):     %p\n", printf);

    // Nettoyage
    free(heap_var);
    return 0;
}