/* 
 * Given a singly linked list, find middle of the linked list. 
 * For example, if given linked list is 1->2->3->4->5 then output should be 3.
 * If there are even nodes, then there would be two middle nodes, we need to print second middle element. 
 * For example, if given linked list is 1->2->3->4->5->6 then output should be 4.
 *
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Linked_list{

	int id;
	char name[10];
	char desc[100];
	struct Linked_list * next;
};

typedef struct Linked_list list;

list * create_list( list * head, int id, char * name, char * desc);
void print_list( list * head);
int find_middle(list * head);

// Global head 
//list * head;

int main ()
{
	list * head = NULL;
	int i, middle;
	
	//char name[10] = {'i', 'd', '_' };
	char name[10] = "ld_";

	/* Above line is equivalent to blelow 2 lines 
	1. char name[10] ;
	2. strcpy(name, "ld_"); */ 

	char desc[100] = "Load balancer ";

	for ( i=1; i<8; i++)
	{	
		snprintf(name+3, sizeof(name), "%d", i);
		snprintf(desc+strlen(desc), sizeof(desc), "%d", i ); // This snprintf keeps appending data
		head = create_list(head, i, name, desc);
	}
	
	//Show List
	print_list(head);
	
	//print middle of list
	middle = find_middle(head);
	printf("\n Middle of list is %d \n", middle );

	// Sort the list based on ascending key value, sort only data
	
	// Sort the list based on ascending key value, sort list pointer
}
int find_middle(list * head)
{
	if ( head == NULL )
		return -1;
	//Method 1:
	//Iterative appraoch : first check length of list and then calculate middle index and the again traverse the list till that point and print middle element 
	
	//Method 2:
	//Take 2 pointer- fast and slow pointer, move fast pointer by 2 and slow pointer by 1, when fast pointer reaches the end of list then slow pointer will be at middle, take a count+2 along with fast pointer
	// Check it is odd or even no, then calculate middle as slow or slow+1 respectively.
	
	list * slow_p = head;
	list * fast_p = head;
	int count = 0;

	while( fast_p != NULL && fast_p->next != NULL )
	{
		fast_p = fast_p->next->next;
		slow_p = slow_p->next;
		count = count+2;
	}

	//Method 3:
	//Initialize mid element as head and initialize a counter as 0. Traverse the list from head, while traversing increment the counter and change mid to mid->next whenever the counter is odd. So the mid will move only half of the total length of the list.
	
	// slow_p is the middle node
	return (slow_p->id);

}
//void create_list( int id, char name[], char desc[] )
list * create_list( list * head, int id, char * name, char * desc)
{
	// Insert at begining 
	list * new_node = (list*)malloc(sizeof(list));
	new_node->id = id;
	strcpy(new_node->name, name);
	strcpy(new_node->desc, desc);
	new_node->next = NULL;
	
	/*new_node->name = name;
	new_node->desc = desc; */
	
	if ( head != NULL )
	{
		new_node->next = head;
	}
	head = new_node;

	return head;
}

void print_list( list * head )
{
	list * curr = head;
	while ( curr != NULL )	
	{
		printf("\n curr->id=%d, curr->name=%s, curr->desc=%s\n", curr->id, curr->name, curr->desc );
		curr = curr->next;
	}
}


