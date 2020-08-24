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
list * delete_node( list * head, int del_index);


// Global head 
//list * head;

int main ()
{
	list * head = NULL;
	
	head = create_list(head, 5, "ld_5", "Load balancer 5");
	head = create_list(head, 4, "ld_4", "Load balancer 4");
	head = create_list(head, 3, "ld_3", "Load balancer 3");
	head = create_list(head, 2, "ld_2", "Load balancer 2");
	head = create_list(head, 1, "ld_1", "Load balancer 1");
	
	//Show List
	print_list(head);

	//head = delete_node(head, 3); //PASSED
	//head = delete_node(head, 1); //PASSED
	//head = delete_node(head, 5); //PASSED
	
	//Show List
	//printf("\n Printing list after deletion....\n ");
	//print_list(head);

	// Sort the list based on ascending key value, sort only data
	
	// Sort the list based on ascending key value, sort list pointer
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

//void create_list( int id, char name[], char desc[] )
list * delete_node( list * head, int del_index)
{
	int count = 1; 
	list * curr = head;
	list * prev = head;
			
// Deletion from begining based on index

	// case 1, if deleting node is head node
	if ( count = del_index )
	{ 	
		head = head->next;
	}
	else // case 2, if deleting node is not head node
	{	
		while (count != del_index )
		{
			prev = curr;
			curr = curr->next;
			count++;
		}

		prev->next = curr->next;
	}


	curr = NULL;
	free(curr);
	// Deletion from End

	return head;
}


