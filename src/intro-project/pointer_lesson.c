#include <stdio.h>
#include <stdlib.h>

/***********************************************
 * This is Array Pointer Assignment Rapping 
 ***********************************************/

// This function returns a pointer to a memory location that stores integers
int *childOfMainWithAllocation()
{
  // these are both 10 item integer arrays, why so obfuscated, C?
  int *integerPointer = malloc(10 * sizeof(int));

  for (int i = 0; i < 10; ++i)
  {
    integerPointer[i] = i;
  }

  return integerPointer;
}

// int *childOfMainWithoutAllocation()
// {
//   // Here, we don't use `malloc`. We just statically allocate an array to hold
//   // 10 integers.
//   int integerArray[10];

//   for (int i = 0; i < 10; ++i)
//   {
//     integerArray[i] = i;
//   }

//   // The `&` operator is the inverse of the `*` operator. It outputs the actual
//   // memory address of its operand, not the operand's value.

//   // HOWEVER, returning &integerArray is bad news. WHY?
//   // when function goes out of scope local vars are popped off of stack, locations can be written over anytime anything is pushed to stack
//   return integerArray;
// }

void doThePointerAssignmentTest()
{
  // what's gonna happen?
  int *integerPointer = childOfMainWithAllocation();

  puts("I'm good");

  int sum = 0;

  for (int i = 0; i < 10; ++i)
  {
    printf("%d", integerPointer[i]);
    sum = sum + integerPointer[i];
  }

  printf("\n");
  printf("Sum: %d\n", sum);

  free(integerPointer);

  printf("\n");

  // int *integerArray = childOfMainWithoutAllocation();

  // // WHY is childOfMainWithoutAllocation() BAD?
  // // It is VERY bad... but why?
  // // integerArray is pointing to an unallocated stack location and causes Segmentation fault
  // puts("I'm bad");

  // sum = 0;

  // for (int i = 0; i < 10; ++i)
  // {
  //   printf("%d", integerArray[i]);
  //   sum = sum + integerArray[i];
  // }

  // printf("\n");
  // printf("Sum: %d\n", sum);
  // printf("\n");
}

/***********************************************
 * This is struct Pointer Assignment Rapping 
 ***********************************************/

// A struct that represents a doubly-linked list node
//
// i.e. A node that references both the node that comes before it in the list,
// as well as the node that comes after it
struct radDoublyLinkedList
{
  struct radDoublyLinkedList *next;
  struct radDoublyLinkedList *last;
  int value;
} radDoublyLinkedList;

// A function that allocates the necessary memory and initializes the nodes with
// NULL `next` and `last` fields.
//
// It should return an instance of the `radDoublyLinkedList` struct.
struct radDoublyLinkedList *doTheStructAssignmentTest()
{
  // Implement this function
  struct radDoublyLinkedList *rd = (struct radDoublyLinkedList *)malloc(sizeof(radDoublyLinkedList));
  rd->next = NULL;
  rd->last = NULL;
  return rd;
}

// Adds a new doubly-linked list node to an existing node
//
// More memory will need to be allocated to the node, and its struct properties
// need to be initialized accordingly
void radDoublyLinkedListAdd(struct radDoublyLinkedList *list, int value)
{
  // Implement this function
  printf("calling radDoublyLinkedListAdd");
  struct radDoublyLinkedList *rd = doTheStructAssignmentTest();
  rd->value = value;
  rd->next = list;
  list->last = rd;
}

/***********************************************
 * This is Array Pointer Assignment Rapping 
 ***********************************************/
int main()
{
  doThePointerAssignmentTest(); // ____

  struct radDoublyLinkedList *list = doTheStructAssignmentTest();

  while (list->next != NULL)
  {
    printf("delete list %i", list->value);
    struct radDoublyLinkedList *freeItem = list;
    list = list->next;
    free(freeItem);
  }
  return 0;
}

// You'll need to implement the `doTheStructAssignmentTest` function and the
// `radDoublyLinkedListAdd` function for this code to compile.
