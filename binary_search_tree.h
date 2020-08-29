#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_



/* �������������ʣ��������Ľڵ��dataС�ڵ��ڸ��ڵ㣬�������Ľڵ�data���ڵ��ڸ��ڵ�*/


/* malloc�ڵ㲢��ֵ */
bstNode* Bst_BuyNode(const int val);
/* free�ڵ� */
void Bst_DeleteNode(bstNode* node);
/* �������  */
void Inorder_Tree_Walk(bstNode* root);
/*  ǰ����� */
void Preorder_Tree_Walk(bstNode* root);
/* �������  */
void Postorder_Tree_Walk(bstNode* root);


/* �������  */
single_list_node* Inorder_Tree_Walk_stack(bstNode* root);
/*  ǰ����� */
single_list_node* Preorder_Tree_Walk_stack(bstNode* root);
/* �������  */
single_list_node* Postorder_Tree_Walk_stack(bstNode* root);

/*  ������ */
bstNode* Tree_Search(bstNode* root, const DataType val);
/*  �ǵݹ������ */
bstNode* Interative_Tree_Search(bstNode* root,const DataType val);
/*  ����С�ڵ� */
bstNode* Tree_Minimum(bstNode* root);
/*  �����ڵ� */
bstNode* Tree_Maximum(bstNode* root);
/* ���̽ڵ�  */
bstNode* Tree_Successor(bstNode* root);
/* ��ǰ���ڵ�  */
bstNode* Tree_Precursor(bstNode* root);
/* ����ڵ�  */
bstNode* Tree_Insert(bstNode* root,const DataType val);
/*  ɾ���ڵ� */
bstNode* Tree_Delete(bstNode* root, const DataType val);
/* �����߶�  */
int Get_High_BST(bstNode* root);


/*  ����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩 */
single_list_node* LevelOrder_Walk_With_Queue(bstNode* root);

/* ����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ������� */
int Is_Balanced_BST(bstNode* root);
/*  ����һ����������������Ƿ��Ǿ���ԳƵġ�*/
int Is_Mirror_BST(bstNode* root);
/* ���ݶ�������ǰ���������������Ľ�����ؽ����ö����������������ǰ���������������Ľ���ж������ظ�������*/
bstNode* Rebuild_BST(int* Pre_q, int* In_q, int size);

/*����һ��������ȡ�侵����*/
bstNode* Transfer_Mirror_Tree(bstNode* root);

/* ����һ�����飬�жϸ������ǲ���ĳ�ö����������ĺ��������Ľ��������Ƿ���true�����򷵻�false*/
int Is_BST_PostOrder(int* ar, int size);


/* �������к�Ϊĳһ��ֵ��·����
����һ�Ŷ�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
�����ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ�����о����Ľڵ��γ�һ��·���� */
void print_all_path_in_BST_sum_is_n(bstNode* root, int val);


#endif