#include "public.h"
#include "stack.h"
#include "single_linked_list.h"




/*创建链表，创建有一个节点的链表*/
single_list_node* CreateSingleList(DataType data)
{
	single_list_node* node = NULL;
	node = SingleList_BuyNode(data);
	return node;
}
/*销毁整个链表*/
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
/*链表尾部插入节点*/
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
/*尾部删除一个节点*/
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
/*头插一个节点, 返回新的头结点*/
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
/*头删除一个节点*/
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

/*指定位置后面插入一个节点，比如要插入1位置，则pos=0, 0位置插入不能用这个函数*/
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


/*删除指定位置的节点*/
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

	//p指向删除节点的next
	p = p_pos->next;

	//删除的节点是0位置，头结点变化
	if(head == p_pos)
	{
		deleteListNode(p_pos);
		return p;
	}

	//找要删除节点的前驱
	pre = head;
	while(1)
	{
		if(pre->next == p_pos)
		{
			break;
		}
		pre = pre->next;
	}
	//删除节点的next指向删除节点的下一个节点
	pre->next = p;
	deleteListNode(p_pos);

	return head;
}

/*指定位置查询*/
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
/*查找第一个数据是data的节点，并返回该节点指针*/
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

/*删除节点*/
void deleteListNode(single_list_node* node)
{
	if(NULL != node)
	{
		free(node);
		node = NULL;
	}
}
/*malloc一个节点  并赋值*/
single_list_node* SingleList_BuyNode(DataType data)
{
	single_list_node* node = (single_list_node*)malloc(sizeof(single_list_node));
	node->data = data;
	node->next = NULL;
	return node;
}
/*显示数据*/
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
/*获取链表长度*/
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
/*返回链表的尾部节点指针*/
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
/*15：查找倒数第k个节点(要求只能遍历一次)*/
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
/* 16：倒着打印单链表 */
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
/* 17：逆置单链表 */
single_list_node* Reverse_List(single_list_node* head)
{
	single_list_node *p = NULL, *p_left = NULL, *p_right = NULL;

	p_left = head ;
	if(NULL == head)
	{
		return NULL;
	}

	/*p指向即将反转指向的节点，p_left指向被反转后的链表的尾部节点
	  p_right指向还没处理的部分的第一个节点*/
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

/*链表排序：冒泡*/
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
	/*p_left指向已拍好序的链表的头结点
	  p_right指向还没排序的头节点
	  p是从未排序的链表的头部取下来，即将有序插入已排好序的p_left指向的链表*/
	while(p != NULL)
	{
		p_right = p->next;

		tmp  = p_left;
		/*tmp遍历已排好序的链表，找p的data应该放的位置
		   prev是最终p的前驱，tmp是p的后继*/
		prev = NULL;
		while(tmp != NULL && tmp->data < p->data)
		{
			prev = tmp;
			tmp = tmp->next;
		}

		//比已排好序的链表的第一个元素还小，头插
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


/*合并两个有序链表*/
/*思想：可以这样想，是将两个链表list1, list2合成一个第三个链表merge_list的过程。
1. 先从两个链表的头中选择小的节点，初始化作为合成链表merge_list的头，
2. 然后从两个链表头开始，选择两个链表头节点小的那一个，开始找，找到全部小于另外一个链表头的所有节点，
3. 将这部分加到merge_list，然后这个链表的头更新，
继续开始重复2， 直到有一个链表到达结尾null*/
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
	
	/*两个链表都是从小到大的，因此两个头中小的那一个是合并后链表的头节点*/
	if(p1->data <= p2->data)
	{
		head = p1;
	}
	else
	{
		head = p2;
	}
	

	/*两个指针p1 p2分别指向两个链表中本次在比较的数字，
	  举例子，假设p1->data <= p2->data情况:
	  选取小的那个节点所在的链表p1，从p1开始向后找，在list1中找到大于p2节点的前一个节点last1,
	  则p1到last1之间的数字都是小于p2节点的，将last1->next指向p2，即将list1中小于p2节点的节点从list1中插入到p2前面了。
	   此时p1更新为last1的下一个节点，开始新一次的处理*/
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



/*查找中间节点*/
/*思想很简单，两个指针，同时开始从头走，一个一次走两步，一个一次走一步，
偶数节点时候，中间的返回前面或后面的都可，奇数个节点的时候返回中间节点*/
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

/*有环链表寻找入口节点
1、求环长度：快慢指针，一个指针走一步，一个走两步，当两个指针第一次相遇的时候，走的次数即是环长度
2、一个指针先走环的长度步数，另外一个指针从头开始， 然后两个指针同时走，第一次相遇即是环的入口节点*/
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
        /*进循环前，需要保证p2是p1的next节点，将判断p2和判p1的值是否重复。因为p2可能被删除，所以保存p2的next，用来在删除p2时候更新p2*/
		if(NULL != p2)
		{
			p3 = p2->next;
		}
		else
		{
			break;
		}

		/*p2和p1值相等，删除p2节点，并更新p2节点指向后面待处理节点*/
		if(p1->data == p2->data)
		{
			p1->next = p3;
			deleteListNode(p2);
			p2 = p3;
		}
		else/*p1和p2值不相等，即p1没有重复的节点，p1和p2都更新。因为此时已知的是p2节点不是null，所以p2不用判null*/
		{
			p1 = p1->next;
			p2 = p2->next;
			
		}
	}

	return head;
}

/*查找两个单向链表的第一个公共节点  */
/*公共部分长度一定是小于等于两个链表长度的，且公共部分在两个链表长度一样。*/
single_list_node* find_first_common_node(single_list_node* l1, single_list_node* l2)
{
	int len1 = 0, len2 = 0,comm_len = 0;
	int i = 0;
	single_list_node* p1 = l1, *p2 = l2;

	if(NULL == l1 || NULL == l2)
	{
		return NULL;
	}

	/*求出两个链表长度，先在长的链表多走几步，走到剩余节点个数和短的链表长度一样的位置*/
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

	/*两个指针一起走，第一个相同的节点即是所求*/
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

/* 单向环形链表，从头开始，每次从这个圆圈删除第m个节点。求链表最后剩余的节点  */
single_list_node* last_node_remain_in_the_cricle_list(single_list_node* head, int m)
{
	single_list_node* prev = NULL, *next = NULL, *cur = head;
	single_list_node* tail = NULL;
	int i = 0;

	if(NULL == head ||m <= 0 || head->next == head)
	{
		return head;
	}

	/* 特殊处理：每隔0个节点删除，即最后只剩下尾部节点 */
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