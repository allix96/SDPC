#pragma once


namespace bor
{

	//---STRUCTURES-------------------------------------------//
	typedef struct node
	{
		struct node_link* link;
	} xfast_tree_t;

	typedef struct node_link
	{
		char key;
		struct node* link;
		struct node_link* next;
		bool leaf;
	} xfast_link_t;


	class Bor
	{
	public:

		//---FUNCTIONS----------------------------------------------//
		xfast_tree_t* CreateNode(void);
		void AddLink(char, xfast_tree_t*);
		void AddString(const char *, xfast_tree_t*);
		void ClearXFastTree(xfast_tree_t*);
//		void MakeBor();

		Bor();

		~Bor();
	};

}

