#ifndef __SINGLE_LINKED_LIST_
#define __SINGLE_LINKED_LIST_



typedef struct single_list
{
	struct single_list* next;
	DataType data;
}single_list_node;
/*
          **功能：应用C语言实现单链表的各项操作
          **                  1：建立节点
          **                  2：打印单链表    
          **                  3：尾插
          **                  4：尾删
          **                  5：头插       
          **                  6：头删    
          **                  7：清空整个链表   
          **                  8：获取链表长度    
          **                  9：查找数据    
          **                10：在某位置后插入数据    
          **                11：删除某位置的数据
*/

single_list_node* CreateSingleList(DataType data);
void destroySingleList(single_list_node* head);

single_list_node* SingleList_insertTail(single_list_node* head, DataType data);
single_list_node* SingleList_DeleteNodeTail(single_list_node* head);

single_list_node* SingleList_insertHead(single_list_node* head, DataType data);
single_list_node* SingleList_DeleteNodeHead(single_list_node* head);

single_list_node* singleList_insert_byPos(single_list_node* head, int pos, DataType data);
single_list_node* SingleList_NodeDelete_byPos(single_list_node* head,int pos);

single_list_node* SinleList_search_byData(single_list_node* head, DataType data);
single_list_node* SingleList_search_byPos(single_list_node* head, int pos);

void SingleList_showdata(single_list_node* head);
int Get_SingleList_Length(single_list_node* head);

void SingleList_showdata_bst(single_list_node* head);
void deleteListNode(single_list_node* node);
single_list_node* SingleList_BuyNode(DataType data);
single_list_node* SingleList_search_TailNode(single_list_node* head, single_list_node** tail_pre);
void SingleList_showdata_sleep(single_list_node* head);
////////////////////////////////////////////
/*
		  //      进阶应用
          **                12：删除一个无头单链表的非尾节点
          **                13：在无头单链表的一个非头节点前插入一个节点
          **                14：查找中间节点
          **                15：查找倒数第k个节点(要求只能遍历一次)
          **                16：倒着打印单链表
          **                17：逆置单链表
          **                18：合并两个有序链表（合并后依然有序）
          **                19：冒泡排序
          **                                                         
 */
/*15：查找倒数第k个节点(要求只能遍历一次)*/
single_list_node* find_Reverse_order_nth_number(single_list_node* head, int n);

/* 17：逆置单链表 */
single_list_node* Reverse_List(single_list_node* head);
/*合并两个有序链表*/
single_list_node* Merge_two_ordered_list(single_list_node* list1, single_list_node* list2);
/* 16：倒着打印单链表 */
void Reverse_print_linked_list(single_list_node* head);

/*链表排序*/
single_list_node* SortList(single_list_node* head);

/*查找中间节点*/
single_list_node* Find_middle_node(single_list_node* head);
/* 链表找环入口 */
single_list_node* find_cricle_list_entrance(single_list_node* head);
/* 单链表找尾部节点 */
single_list_node* find_single_linked_tail(single_list_node* head);
/* 有序单链表删除重复节点 */
single_list_node* Ordered_list_delete_duplicate_node(single_list_node* head);
/*查找两个单向链表的第一个公共节点  */
single_list_node* find_first_common_node(single_list_node* l1, single_list_node* l2);
/* 单向环形链表，从头开始，每隔第m个节点删除。求链表最后剩余的节点  */
single_list_node* last_node_remain_in_the_cricle_list(single_list_node* head, int m);
#endif