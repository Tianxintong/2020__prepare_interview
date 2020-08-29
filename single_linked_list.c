#include "public.h"
#include "stack.h"
#include "single_linked_list.h"




/*��������������һ���ڵ������*/
single_list_node* CreateSingleList(DataType data)
{
	single_list_node* node = NULL;
	node = SingleList_BuyNode(data);
	return node;
}
/*������������*/
void destroySingleList(single_list_node* head)
{
	single_list_node* next = NULL, *p = head;

	while(NULL != p)
	{
		next = p->next;
		deleteListNode(p);
		p = next;
	}
}
/*����β������ڵ�*/
single_list_node* SingleList_insertTail(single_list_node* head, DataType data)
{
	single_list_node *p = NULL, *tail = NULL;
	single_list_node *new_node = NULL;
	single_list_node* tail_pre = NULL;
	new_node = SingleList_BuyNode(data);

	
	p = SingleList_search_TailNode(head, &tail_pre);
	if(NULL == p)
	{
		return new_node;
	}
	p->next = new_node;

	return head;
	
}
/*β��ɾ��һ���ڵ�*/
single_list_node* SingleList_DeleteNodeTail(single_list_node* head)
{
	single_list_node* p = head, *pre = NULL;
	single_list_node* tail_pre = NULL;
	if(NULL == head)
	{
		printf("head is NULL,no node can be deleted.\n");
		return NULL;
	}

	p = SingleList_search_TailNode(head, &tail_pre);
	if(head == p)
	{
		deleteListNode(p);
		printf("delete head node when SingleList_DeleteNodeTail..\n");
		return NULL;
	}
	deleteListNode(p);
	tail_pre->next = NULL;
	return head;
}
/*ͷ��һ���ڵ�, �����µ�ͷ���*/
single_list_node* SingleList_insertHead(single_list_node* head, DataType data)
{
	single_list_node *node = NULL, *p = head;

	node = SingleList_BuyNode(data);
	if(node == NULL)
	{
		printf("malloc Failed when SingleList_insertHead,so head not change.\n ");
		return head;
	}

	node->next = head;


	return node;
}
/*ͷɾ��һ���ڵ�*/
single_list_node* SingleList_DeleteNodeHead(single_list_node* head)
{
	single_list_node* p = head, *head_next = NULL;

	if(NULL == p)
	{
		printf("head is NULL when SingleList_DeleteNodeHead.\n ");
		return NULL;
	}

	head_next = head->next;
	deleteListNode(p);
	return head_next;
}

/*ָ��λ�ú������һ���ڵ㣬����Ҫ����1λ�ã���pos=0, 0λ�ò��벻�����������*/
single_list_node* singleList_insert_byPos(single_list_node* head, int pos, DataType data)
{
	single_list_node* p = NULL, *new_node = NULL;
	single_list_node* p_pos = NULL;

	p_pos = SingleList_search_byPos(head, pos);
	if(NULL != p_pos)
	{
		p = p_pos->next;
		new_node = SingleList_BuyNode(data);
		p_pos->next = new_node;
		new_node->next = p;
	}
	else
	{
		printf("Not find the pos when singleList_insert_byPos.\n ");
		return head;
	}
	return head;
}


/*ɾ��ָ��λ�õĽڵ�*/
single_list_node* SingleList_NodeDelete_byPos(single_list_node* head, int pos)
{
	single_list_node* p_pos = NULL, *p = NULL;
	single_list_node* pre = NULL;

	p_pos = SingleList_search_byPos(head, pos);
	if(NULL == p_pos)
	{
		printf("Not find pos in list when SingleList_NodeDelete_byPos.\n ");
		return head;
	}

	//pָ��ɾ���ڵ��next
	p = p_pos->next;

	//ɾ���Ľڵ���0λ�ã�ͷ���仯
	if(head == p_pos)
	{
		deleteListNode(p_pos);
		return p;
	}

	//��Ҫɾ���ڵ��ǰ��
	pre = head;
	while(1)
	{
		if(pre->next == p_pos)
		{
			break;
		}
		pre = pre->next;
	}
	//ɾ���ڵ��nextָ��ɾ���ڵ����һ���ڵ�
	pre->next = p;
	deleteListNode(p_pos);

	return head;
}

/*ָ��λ�ò�ѯ*/
single_list_node* SingleList_search_byPos(single_list_node* head, int pos)
{
	int i = 0;
	single_list_node* p = head;

	while(p != NULL)
	{
		if(i == pos)
		{
			return p;
		}
		++i;
		p = p->next;
	}
	printf("List length is shorter than pos when SingleList_search_byPos.\n");
	return NULL;
}
/*���ҵ�һ��������data�Ľڵ㣬�����ظýڵ�ָ��*/
single_list_node* SinleList_search_byData(single_list_node* head, DataType data)
{
	single_list_node* p = head;

	while(NULL != p)
	{
		if(data == p->data)
		{
			return p;
		}
		p = p->next;
	}
	if(NULL == p)
	{
		printf("Single List not find the data:%d.\n", data);
		return NULL;
	}
	return 0;
}

/*ɾ���ڵ�*/
void deleteListNode(single_list_node* node)
{
	if(NULL != node)
	{
		free(node);
		node = NULL;
	}
}
/*mallocһ���ڵ�  ����ֵ*/
single_list_node* SingleList_BuyNode(DataType data)
{
	single_list_node* node = (single_list_node*)malloc(sizeof(single_list_node));
	node->data = data;
	node->next = NULL;
	return node;
}
/*��ʾ����*/
void SingleList_showdata(single_list_node* head)
{
	single_list_node* p = head;
	while(NULL != p)
	{
		printf("%d	", p->data);
		p = p->next;
	}
	printf("\n");
	printf("-------------------------------\n\n");
}
void SingleList_showdata_sleep(single_list_node* head)
{
	single_list_node* p = head;
	int n = 40;
	while(NULL != p && n>=0 )
	{
		printf("%d	", p->data);
		Sleep(1000);
		p = p->next;
		--n;
	}
	printf("\n");
	printf("-------------------------------\n\n");
}
/*��ȡ������*/
int Get_SingleList_Length(single_list_node* head)
{
	int len = 0;
	single_list_node* p = head;
	while(NULL != p)
	{
		++len;
		p = p->next;
	}
	return len;
}
/*���������β���ڵ�ָ��*/
single_list_node* SingleList_search_TailNode(single_list_node* head, single_list_node** tail_pre)
{
	single_list_node* p = head;
	*tail_pre = NULL;

	if(NULL == p)
	{
		return NULL;
	}

	while(p->next != NULL)
	{
		*tail_pre = p;
		p = p->next;
	}
	return p;
}
single_list_node* find_single_linked_tail(single_list_node* head)
{
	if(NULL == head)
	{
		return head;
	}
	while( NULL != head->next )
	{
		head = head->next;
	}
	return head;
}
void SingleList_showdata_bst(single_list_node* head)
{
	if(NULL == head)
	{
		return ;
	}
	printf("\n\nOrder With stach:\n");
	head = head;
	while(NULL != head )
	{
		printf("%d	", head->data->data);
		head = head->next;
	}

	printf("\n-----------------------------------------------------\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////
/*15�����ҵ�����k���ڵ�(Ҫ��ֻ�ܱ���һ��)*/
single_list_node* find_Reverse_order_nth_number(single_list_node* head, int n)
{
	int i = 0;
	single_list_node* p1 = head, *p2 = head;

	if(n <=0)
	{
		printf("input %d is InValid.\n",n);
		return NULL;
	}
	while(p1 != NULL)
	{
		++i;
		if(i == n)
		{
			break;
		}
		p1 = p1->next;
	}
	if(i != n)
	{
		printf("The List's Length is less than n = %d\n", n);
		return NULL;
	}
	while(p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	return p2;
}
/* 16�����Ŵ�ӡ������ */
void Reverse_print_linked_list(single_list_node* head)
{
	single_list_node* p = head;
	stack* st = createStack();
	
	while(p != NULL)
	{
		push(st, p->data );
		p = p->next;
	}
	while(!StackIsEmpty(st))
	{
		printf("%d	",GetTop(st));
		pop(st);
	}
	printf("\n");
	
}
/* 17�����õ����� */
single_list_node* Reverse_List(single_list_node* head)
{
	single_list_node *p = NULL, *p_left = NULL, *p_right = NULL;

	p_left = head ;
	if(NULL == head)
	{
		return NULL;
	}

	/*pָ�򼴽���תָ��Ľڵ㣬p_leftָ�򱻷�ת��������β���ڵ�
	  p_rightָ��û����Ĳ��ֵĵ�һ���ڵ�*/
	p = head->next;
	p_left->next = NULL;

	while(p != NULL)
	{
		p_right = p->next;
		p->next = p_left;
		p_left = p;
		p = p_right;
	}
	return p_left;
}

/*��������ð��*/
single_list_node* SortList(single_list_node* head)
{
	single_list_node *p = NULL, *p_left = NULL, *p_right = NULL;
	single_list_node *tmp = NULL, *prev = NULL;

	p_left = head;

	if(head == NULL)
	{
		return NULL;
	}

	p = head->next;
	p_left->next = NULL;
	/*p_leftָ�����ĺ���������ͷ���
	  p_rightָ��û�����ͷ�ڵ�
	  p�Ǵ�δ����������ͷ��ȡ��������������������ź����p_leftָ�������*/
	while(p != NULL)
	{
		p_right = p->next;

		tmp  = p_left;
		/*tmp�������ź����������p��dataӦ�÷ŵ�λ��
		   prev������p��ǰ����tmp��p�ĺ��*/
		prev = NULL;
		while(tmp != NULL && tmp->data < p->data)
		{
			prev = tmp;
			tmp = tmp->next;
		}

		//�����ź��������ĵ�һ��Ԫ�ػ�С��ͷ��
		if(NULL == prev)
		{
			p->next = p_left;
			p_left = p;
			p = p_right;

			continue;
		}

		prev->next = p;
		p->next = tmp;

		p = p_right;

	}

	return p_left;
}


/*�ϲ�������������*/
/*˼�룺���������룬�ǽ���������list1, list2�ϳ�һ������������merge_list�Ĺ��̡�
1. �ȴ����������ͷ��ѡ��С�Ľڵ㣬��ʼ����Ϊ�ϳ�����merge_list��ͷ��
2. Ȼ�����������ͷ��ʼ��ѡ����������ͷ�ڵ�С����һ������ʼ�ң��ҵ�ȫ��С������һ������ͷ�����нڵ㣬
3. ���ⲿ�ּӵ�merge_list��Ȼ����������ͷ���£�
������ʼ�ظ�2�� ֱ����һ���������βnull*/
single_list_node* Merge_two_ordered_list(single_list_node* list1, single_list_node* list2)
{
	single_list_node *last1 = NULL, *p1 = NULL, *last2 = NULL, *p2 = NULL;
	single_list_node *tmp1 = NULL, *tmp2 = NULL;
	single_list_node* head = NULL;
	
	if(NULL == list1)
	{
		return list2;
	}
	if(NULL == list2)
	{
		return list1;
	}
	
	p1 = list1;
	p2 = list2;
	
	/*���������Ǵ�С����ģ��������ͷ��С����һ���Ǻϲ��������ͷ�ڵ�*/
	if(p1->data <= p2->data)
	{
		head = p1;
	}
	else
	{
		head = p2;
	}
	

	/*����ָ��p1 p2�ֱ�ָ�����������б����ڱȽϵ����֣�
	  �����ӣ�����p1->data <= p2->data���:
	  ѡȡС���Ǹ��ڵ����ڵ�����p1����p1��ʼ����ң���list1���ҵ�����p2�ڵ��ǰһ���ڵ�last1,
	  ��p1��last1֮������ֶ���С��p2�ڵ�ģ���last1->nextָ��p2������list1��С��p2�ڵ�Ľڵ��list1�в��뵽p2ǰ���ˡ�
	   ��ʱp1����Ϊlast1����һ���ڵ㣬��ʼ��һ�εĴ���*/
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data <= p2->data)
		{
			tmp1 = p1;
			while(tmp1 != NULL && tmp1->data <= p2->data)
			{
				last1 = tmp1;
				tmp1 = tmp1->next;
			}
			last1->next = p2;
			p1 = tmp1;
			last1 = NULL;
		}
		else
		{
			tmp2 = p2;
			while(tmp2 != NULL && tmp2->data <= p1->data)
			{
				last2 = tmp2;
				tmp2 = tmp2->next;
			}
			last2->next = p1;
			p2 = tmp2;
			last2 = NULL;
		}
	}
	return head;
	
}



/*�����м�ڵ�*/
/*˼��ܼ򵥣�����ָ�룬ͬʱ��ʼ��ͷ�ߣ�һ��һ����������һ��һ����һ����
ż���ڵ�ʱ���м�ķ���ǰ������Ķ��ɣ��������ڵ��ʱ�򷵻��м�ڵ�*/
single_list_node* Find_middle_node(single_list_node* head)
{
	single_list_node *p1 = NULL, *p2 = NULL;

	if(NULL == head)
	{
		return NULL;
	}
	p1 = p2 = head;
	while(p1 != NULL)
	{
		p1 = p1->next;
		if(NULL == p1)
		{
			break;
		}		
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

/*�л�����Ѱ����ڽڵ�
1���󻷳��ȣ�����ָ�룬һ��ָ����һ����һ����������������ָ���һ��������ʱ���ߵĴ������ǻ�����
2��һ��ָ�����߻��ĳ��Ȳ���������һ��ָ���ͷ��ʼ�� Ȼ������ָ��ͬʱ�ߣ���һ���������ǻ�����ڽڵ�*/
single_list_node* find_cricle_list_entrance(single_list_node* head)
{
	single_list_node* p1 = head, *p2 = head;
	int circle_len = 0, n = 0, len_entrance = 0;

	if(NULL == head)
	{
		return head;
	}

	while(  NULL != p1 && NULL != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
		++circle_len;
		if(NULL != p2)
		{
			p2 = p2->next;
		}
		if(p1 == p2)
		{
			break;
		}
	}
	if(NULL == p2 || NULL == p1)
	{
		printf("the list has not cricle.\n\n");
		return NULL;
	}

	p1 = head;
	p2 = head;


	n = 0;
	while(n < circle_len)
	{
		p1 = p1->next;
		++n;
	}

	while(1)
	{
		if(p1 == p2)
		{
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
		++len_entrance;
	}
	printf("circle_length = %d,  list len = %d\n", circle_len, (circle_len+ len_entrance));
	return p2;
}
single_list_node* Ordered_list_delete_duplicate_node(single_list_node* head)
{
	single_list_node *p1 = NULL, *p2 = NULL, *p3 = NULL;

	if(NULL == head)
	{
		return head;
	}
	p1 = head;
	p2 = p1->next;

	while(NULL != p1)
	{
        /*��ѭ��ǰ����Ҫ��֤p2��p1��next�ڵ㣬���ж�p2����p1��ֵ�Ƿ��ظ�����Ϊp2���ܱ�ɾ�������Ա���p2��next��������ɾ��p2ʱ�����p2*/
		if(NULL != p2)
		{
			p3 = p2->next;
		}
		else
		{
			break;
		}

		/*p2��p1ֵ��ȣ�ɾ��p2�ڵ㣬������p2�ڵ�ָ����������ڵ�*/
		if(p1->data == p2->data)
		{
			p1->next = p3;
			deleteListNode(p2);
			p2 = p3;
		}
		else/*p1��p2ֵ����ȣ���p1û���ظ��Ľڵ㣬p1��p2�����¡���Ϊ��ʱ��֪����p2�ڵ㲻��null������p2������null*/
		{
			p1 = p1->next;
			p2 = p2->next;
			
		}
	}

	return head;
}

/*����������������ĵ�һ�������ڵ�  */
/*�������ֳ���һ����С�ڵ������������ȵģ��ҹ�������������������һ����*/
single_list_node* find_first_common_node(single_list_node* l1, single_list_node* l2)
{
	int len1 = 0, len2 = 0,comm_len = 0;
	int i = 0;
	single_list_node* p1 = l1, *p2 = l2;

	if(NULL == l1 || NULL == l2)
	{
		return NULL;
	}

	/*������������ȣ����ڳ���������߼������ߵ�ʣ��ڵ�����Ͷ̵�������һ����λ��*/
	len1 = Get_SingleList_Length(l1);
	len2 = Get_SingleList_Length(l2);
	if(len1 > len2)
	{
		while(i < (len1 - len2) )
		{
			++i;
			p1 = p1->next;
		}
		comm_len = len2;
	}
	else if(len1 < len2)
	{
		while(i < (len2 - len2) )
		{
			++i;
			p2 = p2->next;
		}
		comm_len = len1;
	}
	else
	{
		comm_len = len1;
	}

	/*����ָ��һ���ߣ���һ����ͬ�Ľڵ㼴������*/
	i = 0;
	while(i < comm_len && NULL != p1 && NULL != p2)
	{
		if(p1 == p2)
		{
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
		++i;
	}
	return p1;
}

/* ������������ͷ��ʼ��ÿ�δ����ԲȦɾ����m���ڵ㡣���������ʣ��Ľڵ�  */
single_list_node* last_node_remain_in_the_cricle_list(single_list_node* head, int m)
{
	single_list_node* prev = NULL, *next = NULL, *cur = head;
	single_list_node* tail = NULL;
	int i = 0;

	if(NULL == head ||m <= 0 || head->next == head)
	{
		return head;
	}

	/* ���⴦��ÿ��0���ڵ�ɾ���������ֻʣ��β���ڵ� */
	if(1 == m)
	{
		tail = cur;
		while(cur->next != head)
		{
			cur = cur->next;
			tail = cur;
		}

		prev = tail;
		cur = head;
		while( cur != tail )
		{
			prev->next = cur->next;
			deleteListNode(cur);
			cur = prev->next;
		}
		printf("the last remaining node is tail node , data = %d\n", cur->data);
		return cur;
	}

	cur = head;
	while(cur->next != cur)
	{
		i = 0;
		while(i < m - 1)
		{
			prev = cur;
			cur = cur->next;
			++i;
		}
		prev->next = cur->next;
		printf("1 delete: %d\n", cur->data);
		deleteListNode(cur);
		cur = prev->next;

		if(cur->next == cur)
		{
			printf("the last remaining node : %d\n", cur->data);
			return cur;
		}
	}
	return head;
}