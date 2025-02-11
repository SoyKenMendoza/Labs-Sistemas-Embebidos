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
int HandleInterruptions(Item *items, int N, int nro_max_de_elementos) {



}