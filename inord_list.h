/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 14 March 2020                                                 */
/*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <cctype>
#include<string>
using namespace std;
//typedef int ListReapetedCounterType;
typedef int ListLineType;
typedef string ListElemType;
class Inorder_List
{
	public:
		/* Constructor */
			Inorder_List();
			bool insert(const ListElemType& element,ListLineType & line);
			bool first(ListElemType& element,ListLineType & line);
			bool next(ListElemType& element,ListLineType & line);
		//	bool ModifyList(const ListElemType& element,ListLineType & line,ListReapetedCounterType & counter);

	private:
			struct Node;
			typedef Node* ptr;
			struct Node{
				ListElemType item;
				ptr next;
				ListLineType LineNumber;
		//		ListReapetedCounterType ReapetedCount;
			};
			ptr head;
			ptr tail;
			ptr Current;
			ptr Predecessor;
};
