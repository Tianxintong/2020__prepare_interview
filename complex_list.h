#ifndef __COMPLEX_LIST_H_
#define __COMPLEX_LIST_H_

typedef struct ComplexListNode
{
	int m_nValue;
	struct ComplexListNode* m_pNext;
	struct ComplexListNode* m_pSlibling;
}complexListNode;




/* 分配节点 */
complexListNode* complexList_BuyNode(int data);

/* 删除节点 */
void complexList_DeleteNode(complexListNode* node);
/* 打印链表 */
void complexList_showdata(complexListNode* head);
/* 打印slibling */
void complexList_showSliblingData(complexListNode* head);
/*  */
complexListNode* complexList_InsertNodeTail(complexListNode* head);
/* 销毁链表 */
complexListNode* complexList_DestroyList(complexListNode* head);

////////////////////////////////////////
/* 复杂链表复制 */
complexListNode* CloneComplexList(complexListNode* head);
#endif