#include "public.h"
#include "stack.h"
#include "queue.h"
#include "single_linked_list.h"
#include "binary_search_tree.h"


/* malloc�ڵ㲢��ֵ */
bstNode* Bst_BuyNode(const DataType val)
{
	bstNode *p = (bstNode*)malloc(sizeof(bstNode));
	p->data = val;
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
	return p;
}
/* free�ڵ� */
void Bst_DeleteNode(bstNode* node)
{
	if(NULL != node)
	{
		free(node);
		node = NULL;
	}
}
/* �������  */
void Inorder_Tree_Walk(bstNode* root)
{
	if(NULL != root)
	{
		Inorder_Tree_Walk(root->left);
		printf("%d	", root->data);
		Inorder_Tree_Walk(root->right);
	}
}
/*  ǰ����� */
void Preorder_Tree_Walk(bstNode* root)
{
	if(NULL != root)
	{
		printf("%d	", root->data);
		Preorder_Tree_Walk(root->left);
		Preorder_Tree_Walk(root->right);
	}
}
/* �������  */
void Postorder_Tree_Walk(bstNode* root)
{
	if(NULL != root)
	{
		Postorder_Tree_Walk(root->left);
		Postorder_Tree_Walk(root->right);
		printf("%d	", root->data);
	}
}
/*  ������ */
bstNode* Tree_Search(bstNode* root,const DataType val)
{
	if(NULL != root)
	{
		if(val == root->data)
		{
			return root;
		}
		else if(val > root->data)
		{
			Tree_Search(root->right, val);
		}
		else
		{
			Tree_Search(root->left, val);
		}
	}
	return NULL;
}
/*  �ǵݹ������ */
bstNode* Interative_Tree_Search(bstNode* root,const DataType val)
{
	bstNode* p = root;

	while(p != NULL && p->data != val)
	{
		if(val < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return p;
}
/*  ����С�ڵ� */
bstNode* Tree_Minimum(bstNode* root)
{
	if(NULL == root)
	{
		return NULL;
	}
	while(NULL != root->left)
	{
		root = root->left;
	}
	return root;
}
/*  �����ڵ� */
bstNode* Tree_Maximum(bstNode* root)
{
	if(NULL == root)
		return NULL;
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root;
}
/* ���̽ڵ�  */
bstNode* Tree_Successor(bstNode* root)
{
	bstNode* p = root, *pp = NULL;

	if(NULL== root)
	{
		return NULL;
	}
	if(NULL != root->right)
	{
		return Tree_Minimum(root->right);
	}

	pp = root->parent;
	while(NULL != p && p == pp->right )
	{
		p = pp;
		pp = pp->parent;
	}
	return pp;
}
/* ��ǰ���ڵ�  */
bstNode* Tree_Precursor(bstNode* root)
{
	bstNode* p = root, *pp = NULL;

	if(NULL == root)
	{
		return NULL;
	}
	if(p->left != NULL)
	{
		return Tree_Maximum(p->left);
	}

	p = root;
	pp = p->parent;

	while(NULL != p && p == pp->left)
	{
		p = pp;
		pp = pp->parent;
	}
	return pp;
}
/* ����ڵ�  */
bstNode* Tree_Insert(bstNode* root, const DataType val)
{
	bstNode* p = root, *pp = NULL;
	bstNode* new_node = Bst_BuyNode(val);
	
	if(NULL == root)
	{
		return new_node;
	}

	while(p != NULL)
	{
		pp = p;
		if(val <= p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if(val > pp->data)
	{
		pp->right = new_node;
	}
	else
	{
		pp->left = new_node;
	}
	new_node->parent = pp;
	return root;
}

void replace_a_with_b(bstNode* p, bstNode* b, bstNode** root)
{
	if(NULL == p)
	{
		return;
	}
	if(NULL != p->parent)
	{
		if(p->parent->left == p)
		{
			p->parent->left = b;
		}
		else
		{
			p->parent->right = b;
		}
	}
	else
	{
		*root = b;
	}
	if(b != NULL)
	{
		b->parent = p->parent;	
	}
	
}

/*  ɾ���ڵ� */
bstNode* Tree_Delete(bstNode* root,const DataType val)
{
	bstNode* p = root;
	bstNode *pp = NULL, *successor = NULL;

	p = Interative_Tree_Search(root, val);
	if(NULL == p)
	{
		printf("not find the %d node, nothing to delete.\n", val);
		return root;
	}

	//p��ڵ���null, ��p���Һ��ӽڵ��������滻p��ɾ��p����
	if(NULL == p->left && p->right != NULL)
	{
		replace_a_with_b(p, p->right, &root);
#if 0
		if(NULL != p->parent)
		{
			if(p->parent->left == p)
			{
				p->parent->left = p->right;
			}
			else
			{
				p->parent->right = p->right;
			}
			p->right->parent = p->parent;
		}
		else
		{
			if(p->right != NULL)
			{
				p->right->parent = NULL;
			}
			root = p->right;
		}
#endif
	}
	//p�Һ�����null, ��p�����ӽڵ��������滻p��ɾ��p����
	else if(NULL == p->right && NULL != p->left)
	{
		replace_a_with_b(p, p->left, &root);
#if 0
		if(NULL != p->parent)
		{
			if(p->parent->left == p)
			{
				p->parent->left = p->left;
			}
			else
			{
				p->parent->right = p->left;
			}
			p->left->parent = p->parent;
		}
		else
		{
			if(p->left != NULL)
			{
				p->left->parent = NULL;
			}
			root = p->left;
		}
#endif
	}
	//���Ӻ��Һ��Ӷ�����null,��p�����������ҳ���̣��滻p��ɾ��p����
	else if(NULL != p->left && NULL != p->right)
	{
		
		//p���Һ���û������������p���Һ��Ӿ���p�ĺ�̣���p���Һ����ᵽp��λ�ã�ɾ��p����
		if(p->right->left == NULL)
		{
			replace_a_with_b(p, p->right, &root);
#if 0
			if(p->parent != NULL)
			{
				if(p->parent->left == p)
				{
					p->parent->left = p->right;
				}
				else
				{
					p->parent->right = p->right;
				}
				if(NULL != p->right)
				{
					p->right->parent = p->parent;
				}	
			}
			else
			{
				p->right->parent = NULL;
				root = p->right;
			}
#endif
			p->left->parent = p->right;
			p->right->left = p->left;
			
			
		}
		//��p���Һ��Ӻ��
		else
		{
			successor = Tree_Successor(p); 


			//��̵��Һ��ӹҵ���̵ĸ��ڵ��µ����
			if(NULL != successor->right)
			{
				successor->right->parent = successor->parent;
			}
			successor->parent->left = successor->right;

			//p���Һ��ӹҴ��̵��Һ���λ��
			successor->right = p->right;
			p->right->parent = successor;

			//p�����ӹҵ���̵�����λ��
			successor->left = p->left;
			p->left->parent = successor;

			//��̵ĸ��ڵ��޸�Ϊp�ĸ�
			if(NULL != p->parent)
			{
				if(p->parent->left == p)
				{
					p->parent->left = successor;
				}
				else
				{
					p->parent->right = successor;
				}
				successor->parent = p->parent;
			}
			else
			{
				successor->parent = NULL;
				root = successor;
			}

		}
	}
	else
	{
		if(p->parent != NULL)
		{
			if(p->parent->left == p)
			{
				p->parent->left = NULL;
			}
			else
			{
				p->parent->right = NULL;
			}
		}

		if(root == p)
		{
			root = NULL;
		}
	}

	Bst_DeleteNode(p);
	return root;
}
//https://www.jianshu.com/p/db45201ef16f
/* ����ջʵ���������  */
single_list_node* Inorder_Tree_Walk_stack(bstNode* root)
{
	stack *st = createStack();
	single_list_node* head = NULL;


	bstNode* p = root;
	if(NULL == root)
	{
		return NULL;
	}

	push(st, root);
	p = p->left;
	while(!StackIsEmpty(st) || p != NULL )
	{
		while(NULL != p)
		{
			push(st, p);
			p = p->left;
		}
	
		{
			p = GetTop(st);
			pop(st);

			printf("%d,	", p->data);
			head = SingleList_insertTail(head , p );
			p = p->right;
		}
	}
	return head;
}

/*  ����ջʵ��ǰ����� */
single_list_node* Preorder_Tree_Walk_stack(bstNode* root)
{
	stack* st = createStack();
	bstNode* p = root;
	single_list_node* head = NULL;

	if(NULL == p)
	{
		printf("a\n");
		return NULL;
	}

	push(st, p);
	
	while(!StackIsEmpty(st))
	{
		p = GetTop(st);
		pop(st);
		head = SingleList_insertTail(head, p);

		if(NULL != p->right)
		{
			push(st, p->right);
		}
		if(NULL != p->left)
		{
			push(st, p->left);
		}
	}
	return head;
}
/* ����ջʵ�ֺ������  */
single_list_node* Postorder_Tree_Walk_stack(bstNode* root)
{
    stack* st = createStack();
	single_list_node* head = NULL;
	bstNode* p = root;

	if(NULL == p)
	{
		return NULL;
	}

	push(st, root);
	p = root;

	while( !StackIsEmpty(st) )
	{
		p = GetTop(st);
		pop(st);

		if(NULL != p->left)
		{
			push(st, p->left);
		}
		if(NULL != p->right)
		{
			push(st, p->right);
		}
		head = SingleList_insertHead(head, p);
	}
	return head;
}


/*  ����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩 */
single_list_node* LevelOrder_Walk_With_Queue(bstNode* root)
{
	queue* qu = CreateQueue();
	single_list_node* head = NULL;
	bstNode* p = root;

	if(NULL == p)
	{
		return NULL;
	}

	EnQueue(qu, root);
	p = root;
	while( !QueueIsEmpty(qu) )
	{
		p = DeQueue(qu);
		if(p->left != NULL)
		{
			EnQueue(qu, p->left);
		}
		if(p->right != NULL )
		{
			EnQueue(qu, p->right);
		}
		head = SingleList_insertTail(head, p);
	}
	return head;
}
/* �����߶�  */
int Get_High_BST(bstNode* root)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
{
	stack *qu = CreateQueue();
	int high = 0, level_len = 0, tmp =0;
	bstNode* p = NULL;

	if(NULL == root)
	{
		return 0;
	}
	
	EnQueue(qu, root);
	level_len = 1;
	while( !QueueIsEmpty(qu) )
	{
		while(level_len > 0)
		{
			p = DeQueue(qu);
			if( NULL != p->left )
			{
				++tmp;
				EnQueue(qu, p->left );
			}
			if( NULL != p->right )
			{
				++tmp;
				EnQueue(qu, p->right );
			}
			--level_len;
		}
		level_len = tmp ;
		tmp = 0;
		++high;
	}
	printf("\nBST high is %d\n\n", high);
	return high;
}

bstNode* Transfer_Mirror_Tree(bstNode* root)
{
	bstNode* p = root, *lp = NULL, *rp = NULL;
	int level_len = 0, tmp = 0, high = 0;
	queue* qu = CreateQueue();

	if(NULL == root)
	{
		return p;
	}

	EnQueue(qu, root);
	level_len = 1;
	while( !QueueIsEmpty(qu) )
	{
		while(level_len > 0)
		{
			p = DeQueue(qu);
			if(NULL != p->left)
			{
				++tmp;
				EnQueue(qu, p->left);
			}
			if(NULL != p->right)
			{
				EnQueue(qu, p->right);
				++tmp;
			}
			--level_len;

			if(p->left != NULL  || p->right != NULL)
			{
				lp = p->left;
				p->left = p->right;
				p->right = lp;
			}
		}
		level_len = tmp;
		tmp = 0;
		++high;
	}


	return root;
}
/* ����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ������� */
int Is_Balanced_BST(bstNode* root)
{
	return 1;

}

/* ����һ�����飬�жϸ������ǲ���ĳ�ö����������ĺ��������Ľ��������Ƿ���true�����򷵻�false*/
/* 
����˼·�������������ĺ����������У����һ�������Ǹ��ڵ㣬ǰ�沿�ֱȸ��ڵ�С���������������沿�ֱȸ��ڵ�����������
��ˣ����һ�����еݹ�������������������һ�������������ĺ���������
*/
int Is_BST_PostOrder(int* ar, int size)
{
	int left  = 0, right = 0;
	int ret_left = 0, ret_right = 0;

	if(NULL == ar || size < 3)
	{
	//	printf("Is BST PostOrder\n");
		return 1;
	}
	left = 0;
	right = size - 1 -1;
	while(left < right)
	{
		while(ar[left] < ar[size-1])
		{
			++left;
		}
		while(ar[right] > ar[size-1]  && right > left)
		{
			--right;
		}
		if(left == right)
		{
			printf("mid position = %d, value = %d\n", left, ar[left]);
			ret_left = Is_BST_PostOrder(ar, left);
			if(ret_left)
			{
				ret_right = Is_BST_PostOrder(ar+left, size -1 -left);
				if(ret_right)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

/* �������к�Ϊĳһ��ֵ��·����
����һ�Ŷ�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
�����ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ�����о����Ľڵ��γ�һ��·���� */

void print_all_path_in_BST_sum_is_n(bstNode* root, int val)
{
	stack* st1 = createStack();
	bstNode* p = root;
	int cur_sum = 0;
	int right_tag = 0;

	if(NULL == root)
	{
		return;
	}

	if(root->data > val)
	{
		return;
	}
	if(root->data == val)
	{
		printf("%d\n\n", root->data );
		return;
	}
	push(st1, root);
	cur_sum = root->data;


	while( !StackIsEmpty(st1) )
	{
		p = GetTop(st1);
		if( p->left != NULL && right_tag == 0)
		{
			if(p->left->data + cur_sum == val)
			{
				push(st1, p->left);
				cur_sum = cur_sum + p->data;
				showData_from_base_to_top_bstnode(st1, val);

				p  = GetTop(st1);
				while( !StackIsEmpty(st1) && NULL != p->parent && p->parent->left == p && p->right == NULL )
				{
					cur_sum = cur_sum - p->data;
					pop(st1);
					p = GetTop(st1);
				}

				while(!StackIsEmpty(st1) && NULL != p->parent && p->parent->right == p)
				{
					cur_sum -= p->data;
					pop(st1);
					p = GetTop(st1);
				}
				if(!StackIsEmpty(st1))
				{
					cur_sum -= p->data;
					pop(st1);
				}
				right_tag = 1;
			}
			else if( p->left->data + cur_sum < val )
			{
				cur_sum += p->left->data;
				push(st1, p->left);
				right_tag = 0;
			}
			else
			{
				p = GetTop(st1);
				cur_sum = cur_sum - p->data;
				pop(st1);

				p = GetTop(st1);
				while( !StackIsEmpty(st1) &&  NULL != p->parent && p->parent->left == p && p->right == NULL)
				{
					cur_sum -= p->data;
					pop(st1);
					p = GetTop(st1);
				}
				if(!StackIsEmpty(st1))
				{
					cur_sum -= p->data;
					pop(st1);
				}
				right_tag = 1;
			}
		}
		else 
		{
			
			while( !StackIsEmpty(st1) &&  (NULL == p->right ) )
			{
				cur_sum -= p->data;
				pop(st1);
				p = GetTop(st1);
			}


			if(cur_sum + p->right->data == val)
			{
				push(st1, p->right );
				cur_sum += p->right->data;
				showData_from_base_to_top_bstnode(st1, val);
			
				p = GetTop(st1);
				while( !StackIsEmpty(st1) && NULL != p->parent && p->parent->right == p)
				{
					cur_sum -= p->data;
					pop(st1);
					p = GetTop(st1);
				}
				if(!StackIsEmpty(st1))
				{
					cur_sum -= p->data;
					pop(st1);
				}

				right_tag = 1;

			}
			else if(cur_sum + p->right->data < val )
			{
				cur_sum += p->right->data;
				push(st1, p->right);
				right_tag = 0;

				p = GetTop(st1);
				if( p->right == NULL && NULL == p->left )
				{
					while( !StackIsEmpty(st1) && NULL != p->parent && p->parent->right == p)
					{
						cur_sum -= p->data;
						pop(st1);
						p = GetTop(st1);
					}
					if(p->parent == NULL)
					{
						pop(st1);
						return;
					}
					cur_sum -= p->data;
					if(!StackIsEmpty(st1) )
					{
						pop(st1);
					}
					right_tag = 1;
				} 

			}
			else
			{
				p = GetTop(st1);
				cur_sum -= p->data;
				pop(st1);

				p = GetTop(st1);
				while(!StackIsEmpty(st1) && p->parent != NULL && p == p->parent->left)
				{
					cur_sum -= p->data;
					pop(st1);
					p = GetTop(st1);
				}

				right_tag = 1;
			}
		}
	}
}