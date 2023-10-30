#include <stdio.h>

// Function to display the elements of an array
void displayArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Function to insert an element at the beginning of the array
void insertBefore(int arr[], int size, int element, int position){

  for (int i = size; i >= position; i--){
    arr[i] = arr[i - 1];
  }

  arr[position - 1] = element;
}

// Function to insert an element after a specified position in the array
void insertAfter(int arr[], int size, int element, int position){
    
    for (int i = size; i >= position; i--){
      arr[i] = arr[i - 1];
    }
    arr[position] = element;
    
    (size)++;
  
}


// Function to delete an element at a specified position in the array
void deleteElement(int arr[], int size, int position){
  
    for (int i = position - 1; i < (size) - 1; i++){
      arr[i] = arr[i + 1];
    }
    (size)--;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == element)
    {
      return i;
    }
  }
  return -1; // Element not found
}

// Function to update an element at a specified position in the array
void updateElement(int arr[], int size, int element, int position)
{
  if (position >= 1 && position <= size)
  {
    arr[position - 1] = element;
  }
  else
  {
    printf("Position is out of bounds.\n");
  }
}

int main()
{
  int arr[100];
  int size = 0;

  // Insertion
  insertAfter(arr, &size, 10, 1);
  insertAfter(arr, &size, 20, 2);
  insertBefore(arr, &size, 5, 1);
  displayArray(arr, size); // Should display: 5 10 20

  // Deletion
  deleteElement(arr, &size, 2);
  displayArray(arr, size); // Should display: 5 20

  // Search
  int searchResult = searchElement(arr, size, 20);
  if (searchResult != -1)
  {
    printf("Element 20 found at position %d.\n", searchResult + 1);
  }
  else
  {
    printf("Element 20 not found.\n");
  }

  // Update
  updateElement(arr, size, 25, 2);
  displayArray(arr, size); // Should display: 5 25

  return 0;
}
