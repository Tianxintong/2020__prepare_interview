#include "public.h"
#include "stack.h"
#include "queue.h"
#include "queue_st.h"
#include "single_linked_list.h"
#include "linear_array.h"
#include "complex_list.h"
#include "binary_search_tree.h"


#if 1

int main()
{
	bstNode* root = Bst_BuyNode(10);
	single_list_node* head = NULL, *head_pre = NULL, *head_post = NULL;
	single_list_node* head_level = NULL;

	
	root = Tree_Insert(root, 5);
	root = Tree_Insert(root, 4);
	root = Tree_Insert(root, 3);
	root = Tree_Insert(root, 2);
	root = Tree_Insert(root, 1);
	root = Tree_Insert(root, 7);
	root = Tree_Insert(root, 6);
	root = Tree_Insert(root, 8);
	root = Tree_Insert(root, 15);
	printf("Inorder:\n");
	Inorder_Tree_Walk(root);
#if 1
	head = Inorder_Tree_Walk_stack(root);
	SingleList_showdata_bst(head);

	print_all_path_in_BST_sum_is_n(root,0);
	print_all_path_in_BST_sum_is_n(root,10);
	print_all_path_in_BST_sum_is_n(root,15);
	print_all_path_in_BST_sum_is_n(root,19);
	print_all_path_in_BST_sum_is_n(root,22);
	print_all_path_in_BST_sum_is_n(root,24);
	print_all_path_in_BST_sum_is_n(root,28);
	print_all_path_in_BST_sum_is_n(root,25);
	print_all_path_in_BST_sum_is_n(root,30);
	print_all_path_in_BST_sum_is_n(root,100);
#endif
	print_all_path_in_BST_sum_is_n(root,23);
	print_all_path_in_BST_sum_is_n(root,18);
	print_all_path_in_BST_sum_is_n(root,11);
	print_all_path_in_BST_sum_is_n(root,29);

}

#endif
#if 0
int main()
{
	bstNode* root = Bst_BuyNode(8);	Get_High_BST(root);
	root = Tree_Insert(root, 13);	Get_High_BST(root);
	root = Tree_Insert(root, 10);	Get_High_BST(root);
	root = Tree_Insert(root, 17);	Get_High_BST(root);
	root = Tree_Insert(root, 12);	Get_High_BST(root);
	root = Tree_Insert(root, 9);	Get_High_BST(root);
	root = Tree_Insert(root, 11);	Get_High_BST(root);
	root = Tree_Insert(root, 15);	Get_High_BST(root);
	root = Tree_Insert(root, 14);	Get_High_BST(root);
	root = Tree_Insert(root, 16);	Get_High_BST(root);
	root = Tree_Insert(root, 20);	Get_High_BST(root);
	root = Tree_Insert(root, 4);	Get_High_BST(root);
	root = Tree_Insert(root, 2);	Get_High_BST(root);
	root = Tree_Insert(root, 2);	Get_High_BST(root);
	Inorder_Tree_Walk(root);
	Get_High_BST(root);
	printf("\n----------------------------\n");
	root = Tree_Delete(root, 8);
	printf("new root = %d\n",root->data);
	Inorder_Tree_Walk(root);
	printf("\n----------------------------\n");
	root = Tree_Delete(root, 4);
	printf("new root = %d\n",root->data);
	Inorder_Tree_Walk(root);
	printf("\n----------------------------\n");
	root = Tree_Delete(root, 13);
	printf("new root = %d\n",root->data);
	Inorder_Tree_Walk(root);
	printf("\n----------------------------\n");
	root = Tree_Delete(root, 2);
	printf("new root = %d\n",root->data);
	Inorder_Tree_Walk(root);
	printf("\n----------------------------\n");
	root = Tree_Delete(root, 10);
	printf("new root = %d\n",root->data);
	Inorder_Tree_Walk(root);
	printf("\n----------------------------\n");
	root = Tree_Delete(root, 17);
	printf("new root = %d\n",root->data);
	Inorder_Tree_Walk(root);
	printf("\n----------------------------\n");

}
#endif


#if 0
int main()
{
	bstNode* root = Bst_BuyNode(4);
	single_list_node* head = NULL, *head_pre = NULL, *head_post = NULL;
	single_list_node* head_level = NULL;
    int a[9] = { 2, 1, 5, 7, 6, 13, 9, 8, 4};
	int ret = 0;

	root = Tree_Insert(root, 8);
	root = Tree_Insert(root, 1);
	root = Tree_Insert(root, 6);
	root = Tree_Insert(root, 7);
	root = Tree_Insert(root, 9);
	root = Tree_Insert(root, 5);
	root = Tree_Insert(root, 13);
	root = Tree_Insert(root, 2);
	printf("Inorder:\n");
	Inorder_Tree_Walk(root);
	head = Inorder_Tree_Walk_stack(root);
	SingleList_showdata_bst(head);

	printf("\nPreorder:\n");
	Preorder_Tree_Walk(root);
	head_pre = Preorder_Tree_Walk_stack(root);
	SingleList_showdata_bst(head_pre);

	printf("\nPostorder:\n");
     Postorder_Tree_Walk(root);
	head_post = Postorder_Tree_Walk_stack(root);
	SingleList_showdata_bst(head_post);

	printf("LevelOrder:\n");
	head_level = LevelOrder_Walk_With_Queue(root);
	SingleList_showdata_bst(head_level);

	Get_High_BST(root);
	root = Transfer_Mirror_Tree(root);
	head_level = LevelOrder_Walk_With_Queue(root);
	SingleList_showdata_bst(head_level);

	ret = Is_BST_PostOrder(a, 9);
	if(ret)
	{
		printf("\nIs BST PostOrder.\n\n");
	}


	print_all_path_in_BST_sum_is_n(root, 5);
}
#endif


#if 0
int main()
{
	complexListNode* head = complexList_BuyNode(1), *head2 = NULL;
	complexListNode* p = NULL, *tmp = NULL;
	complexListNode *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL, *p6 = NULL;

	p2 = head->m_pNext = complexList_BuyNode(2);
	p3 = head->m_pNext->m_pNext = complexList_BuyNode(3);
	p4 = head->m_pNext->m_pNext->m_pNext = complexList_BuyNode(4);
	p5 = head->m_pNext->m_pNext->m_pNext->m_pNext = complexList_BuyNode(5);
	p6 = head->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext = complexList_BuyNode(6);
	p1 = head;
	p1->m_pSlibling = p6;
	p2->m_pSlibling = p3;
	p3->m_pSlibling = p2;
	p4->m_pSlibling = p4;
	p5->m_pSlibling = NULL;
	p6->m_pSlibling = p1;
	complexList_showdata(head);
	head2 = CloneComplexList(head);
	complexList_showdata(head2);
	complexList_showSliblingData(head2);
	return 0;
}
#endif

#if 0
int main()
{

	single_list_node* ls1 = NULL , *tail= NULL, *last = NULL, *tail_prev = NULL;
	int m = 3, i =0;
	int size = 10 ;

	ls1 = CreateSingleList(0);
	for(i = 1; i < size; ++i)
	{
		ls1 = SingleList_insertTail(ls1, i);
	}
	SingleList_showdata(ls1);
	tail = SingleList_search_TailNode(ls1, &tail_prev);
	printf("tail  = %d\n", tail->data);
	tail->next = ls1;
	last = last_node_remain_in_the_cricle_list(ls1, 3);


	return 0;
}
#endif
#if 0
int main()
{
	int a[5] = {0,1,2,3,4};
	int b[10] = {0,1,2,3,4,5,6,7,8,9};
	int len = 5;
	int m = 3;

	print_linear_array_int(a,len);
	last_num_remain_in_cricle(a,len, m);

	m = 1;
	print_linear_array_int(a,len);
	last_num_remain_in_cricle(a,len, m);

	len = 1;
	print_linear_array_int(a,len);
	last_num_remain_in_cricle(a,len, m);

	len = 10;
	m = 3;
	print_linear_array_int(b,len);
	last_num_remain_in_cricle(b,len, m);

	return 0;
}
#endif


#if 0

int main()
{
	single_list_node* head = NULL;
	int len = 0;
	single_list_node* tmp = NULL,*p = NULL;
	single_list_node* ls2 = NULL, *ls3 = NULL;
	single_list_node* tail = NULL;
	single_list_node* tmp2 = NULL;
	int i=0,j=0,size = 10;


	head = CreateSingleList(1);
	for(i = 0; i < size; ++i)
	{
		SingleList_insertTail(head, i+1);
	}
	SingleList_showdata(head);

	destroySingleList(head);

	
	head = CreateSingleList(0);
	size = 29;
	for(i = 0; i < size; ++i)
	{
		head = SingleList_insertTail(head, i+1);
	}
	printf("Tail insert 29 nums.\n");
	SingleList_showdata(head);


	size = 30;
	for(i = 0; i < size; ++i)
	{
		head = SingleList_insertHead(head, i+30);
	}
	printf("Head insert 30 nums.\n");
	SingleList_showdata(head);

	size = 10;
	for(i = 0; i < size; ++i)
	{
		head = SingleList_DeleteNodeTail(head);
	}
	printf("Tail delete 10 nums.\n");
	SingleList_showdata(head);

	size = 10;
	for(i = 0; i < size; ++i)
	{
		head = SingleList_DeleteNodeHead(head);
	}
	printf("Head delete 10 nums.\n");
	SingleList_showdata(head);

	size = 41;
	for(i = 0; i < size; ++i)
	{
		head = SingleList_DeleteNodeHead(head);
	}
	printf("Head delete 40 nums.\n");
	SingleList_showdata(head);
////////////////////////////////////////////////////////////////////////////////////////

	head = CreateSingleList(0);
	size = 29;
	for(i = 0; i < size; ++i)
	{
		head = singleList_insert_byPos(head,i, i+1);
	}
	printf("ByPos  insert 29 nums.\n");
	SingleList_showdata(head);


	head = singleList_insert_byPos(head, 0, 100);
	head = singleList_insert_byPos(head, 0, 100);
	head = singleList_insert_byPos(head, 100, 100);
	printf("ByPos  insert 2 nums after 0 position.\n");
	SingleList_showdata(head);

	head = SingleList_NodeDelete_byPos(head,0);
	head = SingleList_NodeDelete_byPos(head,0);
	head = SingleList_NodeDelete_byPos(head,0);
	head = SingleList_NodeDelete_byPos(head,0);
	printf("ByPos delete 1 position 4 times:\n");
	SingleList_showdata(head);

	head = SingleList_NodeDelete_byPos(head,1);
	head = SingleList_NodeDelete_byPos(head,55);
	head = SingleList_NodeDelete_byPos(head,2);
	head = SingleList_NodeDelete_byPos(head,10);
	printf("ByPos delete 1 55 2 10 position 4 times:\n");
	SingleList_showdata(head);


	len = Get_SingleList_Length(head);
	printf("List length  = %d.\n", len);

	tmp = SingleList_search_TailNode(head, &p);
	printf("Search Tail Node data = %d, tail prev node data = %d\n", tmp->data, p->data);

	tmp = SingleList_search_byPos(head, 10);
	printf("Search 10 position data = %d\n", tmp->data);

	size = 20;
	for(i = 0; i<size; ++i)
	{
		head = SingleList_NodeDelete_byPos(head,3);
	}
	printf("after delete byPos 23 nums in  3 position:\n");
	SingleList_showdata(head);
	///////////////////////////////////////////////////
	len = Get_SingleList_Length(head);
	printf("List length  = %d.\n", len);

	j = 10;
	tmp = find_Reverse_order_nth_number(head, j);
	if(NULL != tmp)
	{
		printf("reverse %dth number = %d\n",j, tmp->data);
	}
	j = 0;
	tmp = find_Reverse_order_nth_number(head, j);
	if(NULL != tmp)
	{
		printf("reverse %dth number = %d\n",j, tmp->data);
	}
	j = 1;
	tmp = find_Reverse_order_nth_number(head, j);
	if(NULL != tmp)
	{
		printf("reverse %dth number = %d\n",j, tmp->data);
	}
	j = 5;
	tmp = find_Reverse_order_nth_number(head, j);
	if(NULL != tmp)
	{
		printf("reverse %dth number = %d\n",j , tmp->data);
	}


	printf("Reverse print list:\n");
	Reverse_print_linked_list(head);

	head = Reverse_List(head);
	printf("After List was reversed:\n");
	SingleList_showdata(head);

	destroySingleList(head);

	head = CreateSingleList(1);
	SingleList_showdata(head);
	head = Reverse_List(head);
	SingleList_showdata(head);
	head = SingleList_insertHead(head,10000);
	SingleList_showdata(head);

	head = Reverse_List(head);
	SingleList_showdata(head);
	head = SingleList_insertHead(head,100);
	head = SingleList_insertHead(head,1);
	head = SingleList_insertHead(head,5);
	head = SingleList_insertHead(head,3);
	head = SingleList_insertHead(head,3);
	head = SingleList_insertHead(head,3);
	head = SingleList_insertHead(head,0);
	head = SingleList_insertHead(head,333);
	len = Get_SingleList_Length(head);
	printf("List has %d nums:\n", len);
	SingleList_showdata(head);

	printf("head list After Sort:\n");
	head = SortList(head);
	SingleList_showdata(head);

	ls2 = CreateSingleList(0);
	printf("ls2 :\n");
	SingleList_showdata(ls2);
	tmp = Find_middle_node(ls2);
	printf("ls2's middle node is %d\n\n", tmp->data);
	ls2 = SingleList_insertTail(ls2, 1);

	printf("ls2 :\n");
	SingleList_showdata(ls2);
	tmp = Find_middle_node(ls2);
	printf("ls2's middle node is %d\n\n", tmp->data);

	ls2 = SingleList_insertTail(ls2, 2);

	printf("ls2 :\n");
	SingleList_showdata(ls2);
	tmp = Find_middle_node(ls2);
	printf("ls2's middle node is %d\n\n", tmp->data);

	ls2 = SingleList_insertTail(ls2, 5);
	printf("ls2 :\n");
	SingleList_showdata(ls2);
	tmp = Find_middle_node(ls2);
	printf("ls2's middle node is %d\n\n", tmp->data);

	ls2 = SingleList_insertTail(ls2, 6);

	printf("ls2 :\n");
	SingleList_showdata(ls2);

	tmp = Find_middle_node(ls2);
	printf("ls2's middle node is %d\n\n", tmp->data);

	ls2 = SingleList_insertTail(ls2, 9);

	printf(" ls2 After Sort:\n");
	ls2 = SortList(ls2);
	SingleList_showdata(ls2);


	tmp = Find_middle_node(ls2);
	printf("ls2's middle node is %d\n\n", tmp->data);

	ls2 = Merge_two_ordered_list(head, ls2);
	printf("after merge head list and ls2 list:\n");
	SingleList_showdata(ls2);

	//环的尾部节点指向链表中间节点
	tmp = Find_middle_node(ls2);
	printf("ls2's middle node is %d\n\n", tmp->data);

    tail = find_single_linked_tail(ls2);
	tail->next = tmp;
	printf("tail node data = %d\n", tail->data);
//	SingleList_showdata_sleep(ls2);

	tmp2 = find_cricle_list_entrance(ls2);
	printf("The single linked list with Cricle , entrance node data = %d \n", tmp2->data);


	//无环链表
	tail->next = NULL;
	tmp2 = find_cricle_list_entrance(ls2);
	//一个节点成环
	tail->next = tail;
	tmp2 = find_cricle_list_entrance(ls2);
	printf("The single linked list with Cricle , entrance node data = %d \n", tmp2->data);
	//整个链表是一个大环
	tail->next = ls2;
	tmp2 = find_cricle_list_entrance(ls2);
	printf("The single linked list with Cricle , entrance node data = %d \n", tmp2->data);
    //一个节点的链表，无环
	ls3 = CreateSingleList(2);
	tmp2 = find_cricle_list_entrance(ls3);
    //一个节点的链表，有环
	ls3->next = ls3;
	tmp2 = find_cricle_list_entrance(ls3);
	printf("The single linked list with Cricle , entrance node data = %d \n", tmp2->data);

	ls3->next = NULL;
	ls3 = SingleList_insertHead(ls3,33);
	printf("ls3:\n");
	SingleList_showdata(ls3);
	//ls3 有两个节点，无环
	tmp2 = find_cricle_list_entrance(ls3);
	ls3->next->next = ls3->next;
	//两个节点，尾部节点自成环
	tmp2 = find_cricle_list_entrance(ls3);
	printf("The single linked list with Cricle , entrance node data = %d \n", tmp2->data);
	ls3->next->next = ls3;
	tmp2 = find_cricle_list_entrance(ls3);
	printf("The single linked list with Cricle , entrance node data = %d \n", tmp2->data);

////////////////////////////////////////////////////////////////////////
	printf("---------------------------------------------\n\n");
	tail->next = NULL;
	ls2 = SingleList_insertTail(ls2,10000);
	ls2 = SingleList_insertTail(ls2, 10000);
	printf("ls2 list:\n");
	SingleList_showdata(ls2);
	printf("After dlelete duplicate node, ls2 list :\n");
	ls2 = Ordered_list_delete_duplicate_node(ls2);
	SingleList_showdata(ls2);
	
	ls3->next->next = NULL;
	deleteListNode(ls3->next);
	ls3->next = NULL;
	ls3 = Ordered_list_delete_duplicate_node(ls3);
	SingleList_showdata(ls3);
	ls3 = SingleList_insertHead(ls3,33);
	printf("ls3 list:\n");
	SingleList_showdata(ls3);
	ls3 = Ordered_list_delete_duplicate_node(ls3);
	printf("After delete duplicate node, ls3 list:\n");
	SingleList_showdata(ls3);

	///////////////////////////////////////////

	
    tmp2 = find_first_common_node(ls2, ls3);
	if(NULL == tmp2)
	{
		printf("two list (ls2 , ls3) has not common node.\n\n");
	}
	tmp2 = SinleList_search_byData(ls2, 100);
	printf("set common node is %d\n", tmp2->data);
    ls3->next = tmp2;
	printf("ls2:\n");
	SingleList_showdata(ls2);
	printf("ls3:\n");
	SingleList_showdata(ls3);
    tmp2 = find_first_common_node(ls2, ls3);
	printf("ls2 and ls3 's frist common node  = %d\n\n", tmp2->data);



	return 1;
}
#endif

#if 0
int main()
{
	queuestack *qs = NULL;
	int i = 0,size = 0,j = 0;

	qs = CreateQueueWithStack();

	size = 101;
	for(i = 0; i < size; ++i)
	{
		AppendTail(qs, (i+1));
	}
	printf("tail append 100 numbers.\n");
	Qs_showdata_int(qs);

	size = 50;
	for(j = 0; j < size; ++j)
	{
		DeleteHead(qs);
	}
	printf("head delete 50 numbers.\n");
	Qs_showdata_int(qs);

	size = 30;
	for(j = 0; j < size; ++j)
	{
		AppendTail(qs, (101+j));
	}
	printf("tail append 30 numbers\n");
	Qs_showdata_int(qs);
	
	size = 20;
	for(j = 0; j < size; ++j)
	{
		DeleteHead(qs);
	}
	printf("head delete 20 numbers.\n");
	Qs_showdata_int(qs);

	size = 30;
	for(j = 0; j < size; ++j)
	{
		AppendTail(qs, (131+j));
	}
	printf("tail append 30 numbers\n");
	Qs_showdata_int(qs);

	size = 92;
	for(j = 0; j < size; ++j)
	{
		DeleteHead(qs);
	}
	printf("head delete 90 numbers.\n");
	Qs_showdata_int(qs);
	return 0;
}
#endif


#if 0
int main()
{
	queue* qu = NULL;
	int i = 0,j = 0,size = 10;
	qu = CreateQueue();
	for(i = 0; i < size; ++i)
	{
		EnQueue(qu, i+1);
	}
	
	ShowData_int(qu);

	size = 90;
	for(i = 0; i < size; ++i)
	{
		EnQueue(qu, i+11);
	}
	
	ShowData_int(qu);


	size = 70;
	for(i = 0; i < size; ++i)
	{
		DeQueue(qu);
	}
	
	ShowData_int(qu);


	size = 20;
	for(i = 0; i < size; ++i)
	{
		EnQueue(qu, i+100);
	}
	
	ShowData_int(qu);
	size = 10;
	for(i = 0; i < size; ++i)
	{
		DeQueue(qu);
	}
	
	ShowData_int(qu);
	
	
	size = 20;
	for(i = 0; i < size; ++i)
	{
		EnQueue(qu, i+200);
	}
	
	ShowData_int(qu);

	/////////////////////////////////////////////
	size = 50;
	for(i = 0; i < size; ++i)
	{
		DeQueue(qu);
	}
	
	ShowData_int(qu);
	size = 11;
	for(i = 0; i < size; ++i)
	{
		DeQueue(qu);
	}
	

	return 0;
}
#endif

#if 0
int main() 
{
	stack* st = NULL;
    int size = 20;
	int i  = 0,j = 0;
	int ret = 0;
	float val = 1.0;
	st = createStack();
	for(i = 0; i < size; ++i)
	{
		push(st,  (val + (float)(i)));
	}
	showData_float(st);
	for(i = 0; i < size+3; ++i)
	{
		ret = pop(st);
		if(0 != ret)
		{
			printf("Invalid data pop!!!\n");

		}
	}
	showData_float(st);
	if(StackIsEmpty(st) )
	{
		printf("Stack is Empty!!!!\n");
	}
	size = length+2;
	for(i = 0; i < size; ++i)
	{
		push(st, (val + (float)(i)));
	}
	showData_float(st);
	return 0;
}
#endif

#if 0
int main()
{
    stack* st = NULL;
	int i = 0, j = 0,size = 10;

	st = createStack();
	for(i = 0; i < size; ++i)
	{
		push(st, 'a'+i);
	}
	showData_char(st);
	while(!StackIsEmpty(st))
	{
		pop(st);
	}

	showData_char(st);
	size = 103;
	for(i = 0; i < size; ++i)
	{
		push(st, 'a'+i);
	}
	showData_char(st);
	return 0;
}
#endif