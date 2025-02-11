#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_ITEMS 200

// Definimos el Item de las pilas
typedef struct {

    uint8_t  input_pin; // Byte 1
    uint32_t time_interruption; // Bytes 4
    uint16_t reference; // Bytes 2

} Item;

//Definimos la pila estatica
typedef struct {

    Item items[MAX_ITEMS];
    int top; //Numero de elementos en la pila
    int size; //Tamaño de la pila
    int elements; //Número de elementos de la pila

} StaticStack;

//Crear pila
StaticStack CreateStack(StaticStack* stack) {

    stack->top = -1;
    stack->size = MAX_ITEMS;
    stack->elements = 0;

}

// Verificar si la pila está llena
bool isFull(StaticStack* stack) {

    return stack->elements == stack->size;
}

// Verificar si la pila está vacía
bool isEmpty(StaticStack* stack) {

    return stack-> elements == 0;
}

// Agregar un elemento a la pila
bool push(StaticStack* stack, Item item) {

    if (isFull(stack)) {
        
        return false;
    }
    
    stack->items[++stack->top] = item;
    stack->elements++;
    return true; 
}

// Eliminar un elemento de la pila
bool pop(StaticStack* stack) {

    if (isEmpty(stack)) {
        return false;
    }

    stack->items[(stack->top)--];
    return true;

}

// Obtener el número de ítems en la pila
int size(StaticStack* stack) {

    return stack->elements;
    
}

