#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main(void) {}

node* list_insert_tail(node* headPTR, char* newData)
{
	if(!headPTR) //if the head is null then we know there is nothing in the list
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));
		temp->data=newData;
		headPTR=temp;
		headPTR->next=NULL;
		//printf("%s \n",headPTR->data);
	
	}
	else if(headPTR->next == NULL) //if the next one is null then we can set the next to our new one
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));
		temp->data=newData;
		headPTR->next=temp;
		//printf("%s \n",headPTR->next->data);
	}
	else //if its neither then we try the next node
	{
		 list_insert_tail(headPTR->next, newData);
	}
	return headPTR;


	/*node *this = headPTR;
	while(headPTR)
	{
		this = this->next;
	}
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=newData;
	//headPTR=temp;
	headPTR->next=NULL;
	printf("%s \n",headPTR->data);
	return headPTR;*/
}

void list_print(node* headPTR)
{
	if(!headPTR) //if we find null then we hit the end
	{
	}
	else //we print and recurse through
	{
		printf("%s \n", headPTR->data);
		list_print(headPTR->next);
	}
	/*char* prin = NULL;
	while(!headPTR)
	{
		//prin = headPTR->data + prin;
		printf("%s here", prin);
		headPTR = headPTR->next;
	}
	//printf("%s+", prin);
	*/
}
node* list_insert_head(node* headPTR, char* newData)
{
	//create a node and link it to the old head
	node* newNode;
	newNode=(node*)malloc(sizeof(node));
	newNode->data=newData;
	newNode->next=headPTR;
	return newNode; //return the new node as head
}

node* list_insertn(node* headPTR, char* newData, int pos)
{
	int count=1;
        node *temp;
	temp = headPTR;
	node* newNode;
	newNode=(node*)malloc(sizeof(node));
	newNode->data=newData;

	if(pos==1){
		newNode->next=headPTR;
		return newNode;
	}

	while(count!=pos-1&& temp){
		count++;
		temp=temp->next;
	}
	newNode->next=temp->next;
	temp->next=newNode;

	return headPTR;
}


node* list_remove(node* headPTR, char* oldData)
{
	node *temp;
	temp = headPTR;
	
	if(headPTR->data==oldData){
	
		temp=headPTR->next;
		free(headPTR);
		return temp;
	}
	while(temp){
		if(temp->next->data==oldData){
			temp->next=temp->next->next;
			return headPTR;
		}
		temp=temp->next;
	
	}
	return headPTR;
}


char* list_get(node* headPTR, int pos)
{
	int count=1;
	char* dataF="";
	node *temp;
	temp = headPTR;

	if(pos==1){
		dataF=headPTR->data;
		return dataF;
	}

	while(count!=pos){
		count++;
		temp=temp->next;
	}

	dataF=temp->data;
	return dataF;
}
node* list_removen(node* headPTR, int pos)
{
	int count=1;
        node *temp;
	temp = headPTR;
	if(pos==1){
	temp=headPTR->next;
	free(headPTR);
	return temp;
	}
	while(count!=pos-1){
	count++;
	temp=temp->next;
	}
	temp->next=temp->next->next;
	
	return headPTR;
	
}
void list_destroy(node* headPTR)
{
	node *temp;
	node *current;
	temp = headPTR;

	while(temp!=NULL){
		current=temp->next;
		free(temp);
		temp=current;
	}
	free(headPTR);
	headPTR = NULL;
	
}



