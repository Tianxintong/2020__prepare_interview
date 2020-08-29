#ifndef __COMPLEX_LIST_H_
#define __COMPLEX_LIST_H_

typedef struct ComplexListNode
{
	int m_nValue;
	struct ComplexListNode* m_pNext;
	struct ComplexListNode* m_pSlibling;
}complexListNode;




/* ����ڵ� */
complexListNode* complexList_BuyNode(int data);

/* ɾ���ڵ� */
void complexList_DeleteNode(complexListNode* node);
/* ��ӡ���� */
void complexList_showdata(complexListNode* head);
/* ��ӡslibling */
void complexList_showSliblingData(complexListNode* head);
/*  */
complexListNode* complexList_InsertNodeTail(complexListNode* head);
/* �������� */
complexListNode* complexList_DestroyList(complexListNode* head);

////////////////////////////////////////
/* ���������� */
complexListNode* CloneComplexList(complexListNode* head);
#endif