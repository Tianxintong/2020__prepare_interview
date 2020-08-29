#ifndef __SINGLE_LINKED_LIST_
#define __SINGLE_LINKED_LIST_



typedef struct single_list
{
	struct single_list* next;
	DataType data;
}single_list_node;
/*
          **���ܣ�Ӧ��C����ʵ�ֵ�����ĸ������
          **                  1�������ڵ�
          **                  2����ӡ������    
          **                  3��β��
          **                  4��βɾ
          **                  5��ͷ��       
          **                  6��ͷɾ    
          **                  7�������������   
          **                  8����ȡ������    
          **                  9����������    
          **                10����ĳλ�ú��������    
          **                11��ɾ��ĳλ�õ�����
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
		  //      ����Ӧ��
          **                12��ɾ��һ����ͷ������ķ�β�ڵ�
          **                13������ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
          **                14�������м�ڵ�
          **                15�����ҵ�����k���ڵ�(Ҫ��ֻ�ܱ���һ��)
          **                16�����Ŵ�ӡ������
          **                17�����õ�����
          **                18���ϲ��������������ϲ�����Ȼ����
          **                19��ð������
          **                                                         
 */
/*15�����ҵ�����k���ڵ�(Ҫ��ֻ�ܱ���һ��)*/
single_list_node* find_Reverse_order_nth_number(single_list_node* head, int n);

/* 17�����õ����� */
single_list_node* Reverse_List(single_list_node* head);
/*�ϲ�������������*/
single_list_node* Merge_two_ordered_list(single_list_node* list1, single_list_node* list2);
/* 16�����Ŵ�ӡ������ */
void Reverse_print_linked_list(single_list_node* head);

/*��������*/
single_list_node* SortList(single_list_node* head);

/*�����м�ڵ�*/
single_list_node* Find_middle_node(single_list_node* head);
/* �����һ���� */
single_list_node* find_cricle_list_entrance(single_list_node* head);
/* ��������β���ڵ� */
single_list_node* find_single_linked_tail(single_list_node* head);
/* ��������ɾ���ظ��ڵ� */
single_list_node* Ordered_list_delete_duplicate_node(single_list_node* head);
/*����������������ĵ�һ�������ڵ�  */
single_list_node* find_first_common_node(single_list_node* l1, single_list_node* l2);
/* ������������ͷ��ʼ��ÿ����m���ڵ�ɾ�������������ʣ��Ľڵ�  */
single_list_node* last_node_remain_in_the_cricle_list(single_list_node* head, int m);
#endif