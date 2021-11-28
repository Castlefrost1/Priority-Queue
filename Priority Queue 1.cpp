// ALdi Julyan Sugiyarto - 2301852455
// UTS ADA Priority Queue (Sorted)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Queue{
	int k;			//priority number
	int val;		//value / data
	struct Queue *next;
} List;

List* newList(int value, int key){
	List* temp = (List*)malloc(sizeof(List)); 
    temp->val = value; 
    temp->k = key; 
    temp->next = NULL;
	
	return temp; 
}

void insertItem(List** head, int value, int key) 
{ 
    List* start = (*head); 
  
    // create new Node 
    List* temp = newList(value, key); 
    // if priority (head) < priority (new node) -> create newnode before head
    if ((*head)->k > key) 
    { 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else
    { 
        // insert newnode 
        while (start->next != NULL && start->next->k < key)  
        { 
            start = start->next; 
        } 
        // positioning
        temp->next = start->next; 
        start->next = temp; 
    } 
}

int printHead(List** head) 
{ 
    return (*head)->val;
} 

int printHeadkey(List** head)
{
	return (*head)->k;
}

void pop(List** head) 
{ 
    List* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 

int listEmpty(List** head) 
{ 
    return (*head) == NULL; 
} 

int main() 
{ 
    // 3->17->19->45->77 (randomized key)
    List* queue = newList(3, 0);
    insertItem(&queue, 17, 2);
    insertItem(&queue, 19, 3);
    insertItem(&queue, 45, 1);
    insertItem(&queue, 77, 4);
  
    while (!listEmpty(&queue))  
    { 
        cout << "Value : " << printHead(&queue);
        if (printHead(&queue) < 10)
        {
        	cout << " ";
		}
		cout <<  "   Key : " << printHeadkey(&queue) << endl; 
        pop(&queue);
    } 
    return 0; 
} 
