#include "Bor.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

namespace bor
{
	Bor::Bor()
	{
	}
	
	Bor::~Bor()
	{
	}

	//---BOR FUNCTIONS-------------------------------------------//
	xfast_tree_t* Bor::CreateNode(void)
	{
		xfast_tree_t* node = (xfast_tree_t*)malloc(sizeof(xfast_tree_t));
		node->link = NULL;
		return node;
	}
	void Bor::AddLink(char key, xfast_tree_t* node)
	{
		xfast_link_t* link = (xfast_link_t*)malloc(sizeof(xfast_link_t));
		link->link = CreateNode();
		link->key = key;
		link->next = node->link;
		node->link = link;
	}
	void Bor::AddString(const char * str1, xfast_tree_t* ptr)
	{
		string str = str1;
		int length = str.length();

		for (int sub = 0; sub < length; sub++)
		{
			char letter = str[sub];
			xfast_link_t* link_ptr = ptr->link;
			while (link_ptr && link_ptr->key != letter)
				link_ptr = link_ptr->next;

			//if (sub == length - 1)
			//	ptr->link->leaf = true;
			
			if (link_ptr)
			{
				cout << ptr->link->key;
				ptr = link_ptr->link;
			}
			else
			{
				AddLink(letter, ptr);
				cout << ptr->link->key;
				ptr = ptr->link->link;
			}
		}
		cout << " ";
	}

	void Bor::ClearXFastTree(xfast_tree_t* ptr)
	{
		xfast_link_t* link_ptr = ptr->link;
		while (link_ptr)
		{
			ClearXFastTree(link_ptr->link);
			xfast_link_t* del = link_ptr;
			link_ptr = link_ptr->next;
			free(del);
		}
		free(ptr);
	}

//	void Bor::MakeBor();

	//!!!BOR FUNCTIONS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

}

