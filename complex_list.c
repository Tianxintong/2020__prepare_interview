#include "public.h"
#include "complex_list.h"

/* 分配节点 */
complexListNode* complexList_BuyNode(int data)
{
	complexListNode* p = (complexListNode*)malloc(sizeof(complexListNode));
	if(NULL == p)
	{
		printf("malloc erro\n!!!");
		return NULL;
	}
	p->m_nValue = data;
	p->m_pNext = NULL;
	p->m_pSlibling = NULL;
	return p;
}

/* 删除节点 */
void complexList_DeleteNode(complexListNode* node)
{
	if(NULL != node)
	{
		free(node);
		node = NULL;
	}
}
void complexList_showdata(complexListNode* head)
{
	while(NULL != head)
	{
		printf("%d	",head->m_nValue);
		head = head->m_pNext;
	}
	printf("\n-------------------------------\n");
}
/* 打印slibling */
void complexList_showSliblingData(complexListNode* head)
{
	complexListNode* p = head;
	if(NULL == head)
	{
		return;
	}

	printf("Slibling:\n");
	while(NULL != p)
	{
		if(p->m_pSlibling != NULL)
		{ 
			printf("%d	", p->m_pSlibling->m_nValue);
		}
		else
		{
			printf("NULL	");
		}
		p = p->m_pNext;
	}
	printf("\n----------------------------------------------\n");
}
/* 复杂链表复制 */
complexListNode* CloneComplexList(complexListNode* head)
{
	complexListNode* p = head, *prev = NULL, *next = NULL;
	complexListNode* head2 = NULL;

	if(NULL == head)
	{
		return NULL;
	}

	/* 1 插入 */
	while(p != NULL)
	{
		prev = p;
		next = p->m_pNext;
		p = complexList_BuyNode(prev->m_nValue);
		p->m_pNext = prev->m_pNext;
		prev->m_pNext = p;
		p = next;
	}

	/* 2 修正Slibling */
	p = head;
	while(NULL != p)
	{
		next = p->m_pNext;
		if(NULL != p->m_pSlibling)
		{
			next->m_pSlibling = p->m_pSlibling->m_pNext;
		}
		p = next->m_pNext;
	}

	/* 3 拆分*/
	p = head;
	head2 = p->m_pNext;
	while(NULL != p && NULL != p->m_pNext)
	{
		next = p->m_pNext;
		p->m_pNext = next->m_pNext;
		p = next;
	}

	return head2;
}