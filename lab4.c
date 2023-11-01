// Programa para Laboratorio 4 de estructuras de datos
// Se crea una lista enlazada cuyo nodo contiene un int como dato
// y se implementan operaciones para agregar o eliminar un nodo

#include <stdio.h>
#include <stdlib.h>

// Definir struct del nodo para almacenar entero y apuntar al siguiente
struct Nodo {
    int data;
    struct Nodo* next;
};

// 1(4). Agregar un nodo (al final de la lista)
// Recibe un puntero a un puntero al primer nodo (head) y el valor
void append(struct Nodo** head, int data) {
    
    struct Nodo* newNode = (struct Nodo*)malloc(sizeof(struct Nodo)); // reservar memoria dinámica para nuevo nodo
    
    newNode->data = data; // establecer valor del dato
    newNode->next = NULL; // no hay siguiente porque el nodo se agrega al final

    // Verificar si la lista está vacía
    if (*head == NULL) {
        *head = newNode; // newNode es el primer (y único) nodo
    } else { // si la lista no está vacía
        struct Nodo* current = *head;
        while (current->next != NULL) { // recorrer lista para encontrar último nodo
            current = current->next;
        }

	// Agregar newNode al final de la lista
        current->next = newNode;
    }
}

// 2. Eliminar un nodo por valor
// Recibe puntero doble a primer nodo y valor a eliminar
// Busca el nodo con el valor, lo elimina y libera la memoria asociada
void deleteNode(struct Nodo** head, int value) {

    struct Nodo* current = *head;
    struct Nodo* prev = NULL;

    // Recorrer la lista en busca de nodo que contiene el valor a eliminar
    while (current != NULL && current->data != value) { // hasta llegar al último (NULL)
        prev = current; // nodo anterior
        current = current->next;
    }

    // Si se llega al final y no se encuentra
    if (current == NULL) {
        printf("No se encontró el nodo con el valor %d\n", value);
        return;
    }


    if (prev == NULL) { // el nodo a eliminar es el primero
        *head = current->next; // head apunta al siguiente --> elimina nodo
    } else {
        prev->next = current->next; // si está en medio, anterior apunta al siguiente
    }

    // liberar memoria para evitar memory leaks
    free(current);
}

// 3. Agregar un nodo al inicio de la lista ("prepend")
// Recibe puntero a puntero a primer nodo y valor a agregar
void prepend(struct Nodo** head, int data) {
    
    struct Nodo* newNode = (struct Nodo*)malloc(sizeof(struct Nodo)); // asignar memoria dinámica para nuevo nodo
    
    newNode->data = data; // establecer valor de dato
    newNode->next = *head; // next apunta al primer nodo
    
    *head = newNode; // se actualiza *head a nuevo nodo

}

// 5. Buscar un nodo por valor
void searchNode(struct Nodo * head, int value) {
    
    struct Nodo * current = head; // puntero a nodo para recorrer lista, se inicializa a primer nodo
    
    while (current != NULL) { // loop hasta el último elemento de lista
        // Verificar si el valor del nodo actual es el buscado
        if (current->data == value) {
            printf("Buscar nodo: El nodo con el valor %d sí existe en la lista.\n", value);
            return;
        }

	// avanzar al siguiente nodo
        current = current->next;
    
    }
    
    printf("Buscar nodo: El nodo con el valor %d no existe en la lista.\n", value);

}

// 6. Imprimir la lista
void printList(struct Nodo* head) {
    
    struct Nodo* current = head;
    
    while (current != NULL) {
	// imprimir valor del nodo actual
        printf("%d --> ", current->data);
        current = current->next;
    }

    printf("(NULL)\n"); // indica final de la lista

}

// 7.Obtener el n-ésimo elemento
void getNthNode(struct Nodo* head, int index) {
    
    struct Nodo * current = head; // se inicializa puntero al primer nodo
    int count = 0; // registro de posición en lista

    while (current != NULL) {
	// verificar si posición es el índice buscado
        if (count == index) { 
	    // si coincide índice imprime valor de nodo actual
            printf("Elemento en el índice %d: %d\n", index, current->data);

            return;
        }

        count++;
        current = current->next;

    }

    printf("No se encontró un nodo en el índice %d.\n", index);
}

// Liberar la memoria de la lista
void freeList(struct Nodo * head) {
    
    while (head != NULL) {
        struct Nodo * temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    
    struct Nodo * head = NULL;

    // Ejemplificación del uso de las operaciones
    //
    append(&head, 1);
    append(&head, 3);
    append(&head, 100);

    prepend(&head, 5);

    append(&head, 23);

    printList(head);

    deleteNode(&head, 3);
    printList(head);

    searchNode(head, 1);
    searchNode(head, 100);
    searchNode(head, 15);

    getNthNode(head, 1);
    getNthNode(head, 3);

    // Liberar la memoria de la lista
    freeList(head);

    return 0;
}

