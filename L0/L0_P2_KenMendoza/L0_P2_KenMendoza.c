#include "static_stack.c" // o "dynamic_stack.c"
#include <stdint.h>

//Definimos las interrupciones

typedef enum {

    toggle_pin1 = 0x00,
    print_pin1 = 0x01,
    increment_counter = 0x02,
    print_counter = 0x03,
    check_items = 0x05,
    exit_full = 0x06

} Interruptions; 

// Definimos el Item de las pilas

typedef struct {

    uint8_t  input_pin; // Byte 1
    uint32_t time_interruption; // Bytes 4
    uint16_t reference; // Bytes 2

} Item;

//Función de interrupciones
int handleInterruption(Item item, bool* pin1, size_t* counter, StaticStack* stack) {

    switch (item.input_pin) {
        case toggle_pin1:
            *pin1 = !*pin1;
            return 0;
        case print_pin1:
            printf("El valor del Pin1 es: %d\n", *pin1);
            return 1;
        case increment_counter:
            (*counter)++;
            return 2;
        case print_counter:
            printf("El valor del contador es: %zu\n", *counter);
            return 3;
        case check_items:
            printf("El tamaño de la pila es: %d\n", stack->elements);
            return 5;
        case exit_full:
            if (isFull(stack)) {
                printf("La pila está llena.\n");
                exit(0);
            }
            return 6;
        default:
            return -1;
    }
}
