# Memory_Management_Project_S2P1
## By: Antoine Martinet, Yedong Wu, Daniel Sánchez
This documentation outlines the implementation details and usage of our custom memory allocation functions: mymalloc(), myfree(), myrealloc(), and mycalloc(). These functions are designed to allocate memory on the heap of a program using the brk(2) and sbrk(2) system calls.
### Prerequisites
GCC (GNU Compiler Collection) installed on your system.
### Compilation
To compile the program, follow these steps:
1. Open a terminal window.
2. Navigate to the directory containing the source code files

   (main.c and heap.c).
3. Compile the source files to object files:

   gcc -c main.c -o main.o
   gcc -c heap.c -o heap.o
5. Link the object files to create the executable:

   gcc main.o heap.o -o my_program
### Execution
To run the program, use the following command:
./my_program
### Cleanup
rm main.o heap.o my_program

### Theory explanation 
In computer memory management, the Random Access Memory (RAM) is divided into two essential components: the stack and the heap. The stack is a dedicated portion of memory primarily responsible for handling function calls and managing local variables. Whenever a function is invoked, a new stack frame is created, encompassing space for local variables, function parameters, and return addresses. The stack operates on a Last In, First Out (LIFO) basis, meaning that the most recently added item is the first to be removed. While the stack is efficient for managing function-related data, exclusively relying on it can lead to memory inefficiency.

To address this limitation, C provides the heap, a more versatile region of memory designed for dynamic memory allocation. The heap allows for on-the-fly memory requests during program execution, offering flexibility in managing memory resources. Unlike the stack, the heap requires explicit allocation and deallocation of memory by the programmer and does not adhere to a strict LIFO order. Generally, the heap has a larger size compared to the stack, and programs can dynamically request memory as needed. However, accessing data on the heap typically involves more intricate memory management processes, resulting in slower performance compared to the stack. 

In C, to manage the memory with dynamic allocation, there are these main functions from the <unistd.h> library:
1. malloc: Stands for "memory allocation", it is used to dynamically allocate memory on the heap during the execution. It returns a pointer of type void which can be cast into a pointer of any form. Syntax: int *numPtr = (int *)malloc(sizeof(int));
2. calloc: Stands for "contiguous allocation", it is used to dynamically allocate a specified number of blocks of memory, each with a specified number of bytes, and is initialized it to zero. Syntax: void* calloc(size_t num_elements, size_t element_size);
3. realloc: Stands for "reallocate", it is used to resize a previously allocated block of memory. It takes a pointer to a block of memory previously allocated with malloc, calloc, or realloc, and changes the size of that block. If the size is increased, the content of the previously allocated memory is preserved up to the minimum of the old and new sizes. If the size is decreased, the excess memory at the end of the block is released. Syntax: void* realloc(void* ptr, size_t new_size);
4. free: It is used to deallocate memory that was previously allocated using functions like malloc, calloc, or realloc. It helps in releasing the memory back to the system so that it can be used for other purposes. Syntax: free(variable);

To understand how these functions work, take a look of the schematics:
