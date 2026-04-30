1. Project Title

Embedded Systems: Circular Buffer Implementation (CE-ESY Project)
2. Description

This project demonstrates a manual implementation of a Circular (Ring) Buffer in C, a fundamental data structure in embedded systems used for efficient data streaming and memory management. The program takes a user's name, appends the course code "CE-ESY", and processes the data through the buffer.
3. Key Technical Features

    Static Memory Allocation: Uses a fixed-size array (BUFFER_SIZE 15) to comply with embedded systems constraints where dynamic memory is often avoided.

    Modulo Arithmetic: Implements pointer wrapping using the % operator to maintain a continuous loop within the array.

    Resource Monitoring: Includes functions to check bufferIsFull and bufferIsEmpty to prevent data overflow or underflow.

4. Code Structure

    RingBuffer struct: Holds the data array, read/write positions, and element count.

    bufferWrite(): Adds a character to the buffer if space is available.

    bufferRead(): Retrieves a character from the buffer in First-In-First-Out (FIFO) order.

5. How to Run

    Using GCC (Linux/WSL):
    Bash

    gcc main.c -o ring_buffer
    ./ring_buffer

    Using VS Code: Open the terminal and run the compiled executable.
