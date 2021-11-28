// ALdi Julyan Sugiyarto - 2301852455
// UTS ADA Priority Queue (Unsorted)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Queue{
	int k;			//priority number
	int val;		//value
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
    // Create new List
    List* temp = newList(value, key); 
	temp->next = *head; 
    (*head) = temp; 
    
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
