#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_



/* 二叉搜索树性质：左子树的节点的data小于等于根节点，右子树的节点data大于等于根节点*/


/* malloc节点并赋值 */
bstNode* Bst_BuyNode(const int val);
/* free节点 */
void Bst_DeleteNode(bstNode* node);
/* 中序遍历  */
void Inorder_Tree_Walk(bstNode* root);
/*  前序遍历 */
void Preorder_Tree_Walk(bstNode* root);
/* 后序遍历  */
void Postorder_Tree_Walk(bstNode* root);


/* 中序遍历  */
single_list_node* Inorder_Tree_Walk_stack(bstNode* root);
/*  前序遍历 */
single_list_node* Preorder_Tree_Walk_stack(bstNode* root);
/* 后序遍历  */
single_list_node* Postorder_Tree_Walk_stack(bstNode* root);

/*  查找树 */
bstNode* Tree_Search(bstNode* root, const DataType val);
/*  非递归查找树 */
bstNode* Interative_Tree_Search(bstNode* root,const DataType val);
/*  求最小节点 */
bstNode* Tree_Minimum(bstNode* root);
/*  求最大节点 */
bstNode* Tree_Maximum(bstNode* root);
/* 求后继节点  */
bstNode* Tree_Successor(bstNode* root);
/* 求前驱节点  */
bstNode* Tree_Precursor(bstNode* root);
/* 插入节点  */
bstNode* Tree_Insert(bstNode* root,const DataType val);
/*  删除节点 */
bstNode* Tree_Delete(bstNode* root, const DataType val);
/* 求树高度  */
int Get_High_BST(bstNode* root);


/*  给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点） */
single_list_node* LevelOrder_Walk_With_Queue(bstNode* root);

/* 给定一个二叉树，判断它是否是高度平衡的二叉树。 */
int Is_Balanced_BST(bstNode* root);
/*  给定一个二叉树，检查它是否是镜像对称的。*/
int Is_Mirror_BST(bstNode* root);
/* 根据二叉树的前序遍历和中序遍历的结果，重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字*/
bstNode* Rebuild_BST(int* Pre_q, int* In_q, int size);

/*输入一棵树，获取其镜像树*/
bstNode* Transfer_Mirror_Tree(bstNode* root);

/* 给定一个数组，判断该数组是不是某棵二叉搜索树的后续遍历的结果。如果是返回true，否则返回false*/
int Is_BST_PostOrder(int* ar, int size);


/* 二叉树中和为某一个值的路径：
输入一颗二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从树的根节点开始往下一直到叶节点的所有经过的节点形成一条路径。 */
void print_all_path_in_BST_sum_is_n(bstNode* root, int val);


#endif