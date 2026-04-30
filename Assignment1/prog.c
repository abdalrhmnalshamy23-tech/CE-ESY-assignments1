#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 15

typedef struct {
    char data[BUFFER_SIZE];
    int readPos;
    int writePos;
    int elements;
} RingBuffer;

void bufferInit(RingBuffer *rb) {
    rb->readPos = 0;
    rb->writePos = 0;
    rb->elements = 0;
}

int bufferIsFull(RingBuffer *rb) {
    return rb->elements == BUFFER_SIZE;
}

int bufferIsEmpty(RingBuffer *rb) {
    return rb->elements == 0;
}

void bufferWrite(RingBuffer *rb, char value) {
    if (bufferIsFull(rb)) {
        printf("Cannot write '%c' -> Buffer is full!\n", value);
        return;
    }

    rb->data[rb->writePos] = value;
    rb->writePos = (rb->writePos + 1) % BUFFER_SIZE;
    rb->elements++;
}

char bufferRead(RingBuffer *rb) {
    if (bufferIsEmpty(rb)) {
        printf("Cannot read -> Buffer is empty!\n");
        return '\0';
    }

    char value = rb->data[rb->readPos];
    rb->readPos = (rb->readPos + 1) % BUFFER_SIZE;
    rb->elements--;

    return value;
}

int main() {
    RingBuffer rb;
    bufferInit(&rb);

    char username[60];
    printf("Enter your name: ");
    scanf("%59s", username);

    strcat(username, "CE-ESY");

    for (int i = 0; i < strlen(username); i++) {
        bufferWrite(&rb, username[i]);
    }

    printf("\nResult: ");
    while (!bufferIsEmpty(&rb)) {
        printf("%c", bufferRead(&rb));
    }

    printf("\n");

    if (bufferIsEmpty(&rb)) {
        printf("Buffer is empty now.\n");
    }

    return 0;
}
