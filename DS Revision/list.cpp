#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}n;

n *head = NULL;
n *tail = NULL;

n* createNode()
{
	n *newnode;
	newnode = new n(); 
	cout<<"Enter data : ";
	cin>>newnode->data;
	newnode->next = NULL;
	return newnode;
}

void addFirst()
{
	if(head == NULL)
	{
		head = createNode();
		tail = head;	
	}
	else
	{
		n *temp = createNode();
		temp->next = head;
		head = temp;
	}	
	cout<<"Inserted at First Successfully"<<endl;	
}

void addmid(int pos)
{
	if(head == NULL)
	{
		head = createNode();
		tail = head;
	}
	else
	{
		n *temp = createNode();
		n *th = head;
		int count = 1;
		while(th != NULL)
		{
			if(count == pos-1)
			{
				temp->next = th->next;
				th->next = temp;
				break;
			}
			count++;
			th = th->next;
		}
		cout<<"Inserted at "<<pos<<" Successfully\n";
	}
}

void addLast()
{
	if(head == NULL)
	{
		head = createNode();
		tail = head;
	}
	else
	{
		n *temp = createNode();
		tail->next = temp;
		temp->next = NULL;
		tail = temp;
	}
	cout<<"Inserted at Last Successfully"<<endl;
}

void delfirst()
{
	if(head == NULL)
	{
		cout<<"List is empty\n";
		return;
	}
	if(head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		n *temp = head;
		head = head->next;
		temp->next = NULL;
		free(temp);
	}
	cout<<"First Element deleted successfully"<<endl;
}

void dellast()
{
	if(head == NULL)
	{
		cout<<"List is empty";
		return;
	}
	if(head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		n *th1 = head->next;
		n *th2 = head;
		while(th1->next != NULL)
		{
			th1 = th1->next;
			th2 = th2->next;
		}
		th2->next = NULL;
		tail = th2;
		free(th1);
		free(th2);
	}
	cout<<"Deleted last node Successfully"<<endl;
}

void delmid(int pos)
{
	if(head == NULL)
	{
		cout<<"List is empty";
		return;
	}
	if(head->next == NULL)
		free(head);
	else
	{
		n *temp = head;
		int count = 1;
		while(temp != NULL)
		{
			if(count == pos-1)
				break;
			temp = temp->next;
			count++;
		}
		n *th = temp->next;
		temp->next = th->next;
		free(th);
	}
	cout<<"Deleted node "<<pos<<" Successfully"<<endl;
	
}

void checkEven_or_Odd()
{
	int flag = 0;
	n *t = head;
	while(t != NULL)
	{
		flag = !flag;
		t = t->next;
	}
	if(flag == 0 )
		cout<<"List is Even"<<endl;
	else
		cout<<"List is Odd"<<endl;
		
}

void reverse(n *curr)
{
	n *prev=NULL, *temp=NULL;
	while(curr)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
	free(prev);
	free(temp);
	
}

void middlevalue()
{
	n *temp = head,*fast=head,*slow=head;
	while(fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast->next != NULL)
			fast = fast->next;
	}
	cout<<"\nMiddle value "<<slow->data<<endl;
	free(fast);
	free(slow);
	free(temp);
}

int size()
{
	node *t = head;
	int size = 0;
	while(t != NULL)
	{
		++size;
		t = t->next;
	}
	return size;
}

bool loop()
{
	if(head == NULL)
		return false;
	if(head->next == NULL)
		return false;
	n *fast=head,*slow=head;
	while(fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast->next != NULL)
			fast = fast->next;
		if(slow == fast)
			return true;
	}
	return false;	
}

/*n* sortedMerge(Node* head1,   Node* head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    n *head=NULL,*tail=NULL;
    if(head1->data <= head2->data)
    {
        head=tail=head1;
        head1 = head1->next;
    }
    else
    {
        head=tail=head2;
        head2 = head2->next;
    }
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
            
        }
        else
        {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
    }
    if(head1 == NULL)
    {
        tail->next = head2;
    }
    else
    {
        tail->next = head1;
    }
    return head;
}
*/

n * reversekalternatenodes(n *head,int k)
{
	n *curr = head,*prev = NULL,*temp = NULL;
	int count = 0;
	while(curr != NULL && count < k)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		count++;
	}
	if(head != NULL)
		head->next = curr;
	count = 0;
	while(count < k-1 && curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	if(curr != NULL)
		curr->next = reversekalternatenodes(curr->next,k);
	return prev;
}

void display(n *head)
{
	n *t = head;
	while(t != NULL)
	{
		cout<<t->data<<" ";
		t = t->next;
	}
}

int main()
{
	int count;
	addFirst();
	addFirst();
	addFirst();
	addLast();
	addLast();
	addmid(3);
	//delfirst();
	//delmid(3);
	//dellast();
	display(head);
	checkEven_or_Odd();
	count = size();
	cout<<"Number of Nodes : "<<count<<endl;
	cout<<"List before Reverse : "<<endl;
	display(head);
	reverse(head);
	cout<<"\nList after Reverse : "<<endl;
	display(head);
	middlevalue();
	cout<<"Does loop exist? "<<loop()<<"\n";
	head = reversekalternatenodes(head,2);
	display(head);
	
	return 0;
}
