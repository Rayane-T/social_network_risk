#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>

#define THRESHOLD 3
#define CAPACITY_PROCESS 100 000
#define CAPACITY_STORAGE 100 000


typedef struct {
    int id;
    float risk;
} Post;
/*
typedef struct {
    Tuple t;
    Node *next;
    Node *prev;
} Node;
*/
void pre_process(){

}
// Function to swap two integers
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

Post riskiest_post(int *bot_output){
    
    Post riskiest = {0, 0.0};
    int compteur = 0;
    int riskiest_compteur = 0;
    
    while (bot_output != NULL){
        if  (bot_output[compteur][1] > riskiest[1]){
            riskiest = bot_output[compteur][1];
            riskiest_compteur = compteur;
        }
        // Enhance the next searches by doing sliding the riskiest to the beginning of the array as we go through the posts
        if (compteur > 1 && bot_output[compteur][1] > bot_output[compteur-1][1]){
            swap(bot_output[compteur], bot_output[compteur - 1]);
        }
        ++compteur;
    }
    swap(bot_output[riskiest_compteur], bot_output[compteur]); // Assuming that compteur is at the end of the list at the end of the iteration 
    
    return riskiest;
}

void processing_post(Heap* heap, int* processed){
    
    int processing_power = 4;
    
    while (true){
        wait(processing_power);
        extractMax(heap);
    }

}

typedef struct Heap {
    int* array;
    int size;
    int capacity;
} Heap;


// Function to create a heap
Heap* createHeap(int capacity)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Function to heapify the node at index i
void heapify(Heap* heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size
        && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size
        && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

// Function to insert a new value into the heap
void insertHeap(Heap* heap, int value)
{
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    // Fix the heap property if it is violated
    while (i != 0
           && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the root (maximum element)
int extractMax(Heap* heap)
{
    if (heap->size <= 0)
        return INT_MIN;
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // Store the maximum value, and remove it
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Function to print the heap
void printHeap(Heap* heap)
{
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->array[i]);
    printf("\n");
}


int main(int argc, char *argv[]) {
    
    Heap* heap = createHeap(CAPACITY_PROCESS);
    
    // Gerer les ajouts de post et les process de post en meme temps -> multi-threading
    
    pthread_t get;
    pthread_t process;

    pthread_create(get, NULL);
    pthread_create(process, NULL);

    while (bot_output != NULL){
    
    Tuple riskiest = riskiest_post(bot_output);
    
    if (heap->size == heap->capacity){
       find lowest of the heap
       swap(riskiest, );
    }
    } else {
        insertHeap(heap, riskiest);
    }
    }

    printf("Max Heap array: ");
    printHeap(heap);

    printf("Extracted max value: %d\n",
           extractMax(heap));
    printf("Max Heap array after extraction: ");
    printHeap(heap);

    free(heap->array);
    free(heap);
}
