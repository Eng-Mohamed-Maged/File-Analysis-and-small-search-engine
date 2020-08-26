/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 14 March 2020                                                 */
/*******************************************************************************/
#include"inord_list.h"
#include <stdio.h>

Inorder_List::Inorder_List()
{
	head=NULL;
	tail=NULL;
	Current=NULL;
	Predecessor=NULL;
//	cout << "Constructor 1 called  on object:" << this << "\n";
}

bool Inorder_List::next(ListElemType& element,ListLineType & line)
{
	if((Current->next==NULL)||(Current==NULL))
	{
		return false;
	}
	else
	{
		element=Current->next->item;
		line=Current->next->LineNumber;
		Current=Current->next;
		return true;
	}
}


bool Inorder_List::insert(const ListElemType& element,ListLineType & line)
{
	ptr Newnode;
	Newnode= new Node;
	// Check is node created or not
	if(Newnode==NULL)
	{
		return false;
	}
	else
	{
		Newnode->item=element;
		Newnode->LineNumber=line;
	//	Newnode->ReapetedCount=counter;
		// if element less than head element (head is null)
		// if you put if(element<=(head->item) || (head==NULL)) Code will not run
		if((head==NULL) ||(element<=(head->item)))
		{
			// newnode.next== (address of old head)
			Newnode->next=head;
			// this newnode will be the head node
			head=Newnode;
		}
		else
		{
			// Put address of head node into Predecessor of inserted node
			Predecessor=head;
			while(Predecessor->next!=NULL && element>=Predecessor->next->item)
			{
				 Predecessor=Predecessor->next;
				if(Predecessor->next==NULL)
				{
			    break;
			    }
			}
			// Like line 52 & 54
			Newnode->next = Predecessor->next;
			Predecessor->next=Newnode;
		}
	}
	return true;
}


bool Inorder_List::first(ListElemType& element,ListLineType & line)
{
	if(head==NULL)
	{
		return false;
	}
	else
	{
		element=head->item;
		line=head->LineNumber;
	//	counter=head->ReapetedCount;
		Current=head;
		return true;
	}
}


/*bool Inorder_List::ModifyList(const ListElemType& element,ListLineType & line,ListReapetedCounterType & counter)
{
	ListElemType itemTmp;
	ListLineType LineTmp;
	ListElemType itemTmp2;
	ListLineType LineTmp2;
	if(head==NULL)
	{
		return false;
	}
	else
	{
		itemTmp=head->item;
		LineTmp=head->LineNumber;
		if((element==itemTmp)&&(line==LineTmp))
		{
			head->ReapetedCount=counter;
		}
		else
		{
			itemTmp2=head->next->item;
			LineTmp2=head->next->LineNumber;
			while(head->next!=NULL)
			{
				if((element==itemTmp2)&&(line==LineTmp2))
				{
					head->next->ReapetedCount=counter;
				}
				head=head->next;
				if(head->next==NULL)
				{
					break;
			    }
			}
		}
		return true;
	}
}*/
