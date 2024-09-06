#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes in the linked list
struct node {
  int data;
  struct node *next;
};

// Function to initialize a new node
struct node *newNode(int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

// Function to find the middle node of the linked list
struct node *findMiddle(struct node *head) {
  struct node *slow = head;
  struct node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

int main() {
  // Initialize the linked list with user input
  printf("Enter the number of elements to be added to the linked list: ");
  int n, i, data;
  scanf("%d", &n);
  struct node *head = NULL;
  struct node *temp = NULL;
  for (i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &data);
    if (head == NULL) {
      head = newNode(data);
      temp = head;
    } else {
      temp->next = newNode(data);
      temp = temp->next;
    }
  }

  // Find the middle node of the linked list
  struct node *middle = findMiddle(head);
  printf("The middle element of the linked list is: %d\n", middle->data);

  return 0;
}

