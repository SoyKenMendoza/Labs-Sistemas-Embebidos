#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


// Definimos el Item de las pilas
typedef struct {

    uint8_t  input_pin; // Byte 1
    uint32_t time_interruption; // Bytes 4
    uint16_t reference; // Bytes 2

} Item;

//Definimos la pila dinamica
typedef struct {

    Item* items;
    int top; //Numero del elemento tope en la pila
    int size; //Tamaño de la pila
    int elements; //Número de elementos de la pila

} DinamicStack;

//Crear pila
void CreateStack(DinamicStack* stack, int size) {

    stack->items = (Item*)malloc(size * sizeof(Item));
    stack->top = -1;
    stack->size = size;
    stack->elements = 0;

}

// Verificar si la pila está llena
bool isFull(DinamicStack* stack) {

    return stack->elements == stack->size;
}

// Verificar si la pila está vacía
bool isEmpty(DinamicStack* stack) {

    return stack-> elements == 0;
}

// Agregar un elemento a la pila
bool push(DinamicStack* stack, Item item) {

    if (isFull(stack)) {
        
        return false;
    }
    
    stack->items[++stack->top] = item;
    stack->elements++;
    return true; 
}

// Eliminar un elemento de la pila
bool pop(DinamicStack* stack) {

    if (isEmpty(stack)) {
        return false;
    }

    stack->items[(stack->top)--];
    return true;

}

// Obtener el número de ítems en la pila
int size(DinamicStack* stack) {

    return stack->elements;

}

