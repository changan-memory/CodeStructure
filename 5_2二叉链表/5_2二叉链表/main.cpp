#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//经常找后继的   用二叉链表
typedef struct BiNode {
	int data;	//	数据域
	struct BiNode *Lchild, *Rchild;	//指针域   指向左右孩子
}BiNode, *BiTree;	//前面是结点   后面是指向该结点的指针

void visit(BiTree T) {
	printf("%d ", T->data);
}

//二叉树的 先序遍历算法
void PreOrderTraverse(BiTree T) {
	if (T == NULL)	//判断二叉树是否为空    为空的话返回
		return;
	else {
		//先序 根 左 右
		visit(T);	//对结点进行访问
		PreOrderTraverse(T->Lchild);// 递归遍历左子树
		PreOrderTraverse(T->Rchild);// 递归遍历右子树
	}
}

//二叉树的 中序遍历算法
void InOrderTraverse(BiTree T) {
	if (T == NULL)	//判断二叉树是否为空    为空的话返回
		return;
	else {
		//中序  左 根 右
		InOrderTraverse(T->Lchild);// 递归遍历左子树
		visit(T);	//对结点进行访问
		InOrderTraverse(T->Rchild);// 递归遍历右子树
	}
}

//二叉树的 后序遍历算法
void PostOrderTraverse(BiTree T) {
	if (T == NULL)	//判断二叉树是否为空    为空的话返回
		return;
	else {
		//后序  左 右 根
		PostOrderTraverse(T->Lchild);// 递归遍历左子树
		PostOrderTraverse(T->Rchild);// 递归遍历右子树
		visit(T);	//对结点进行访问
	}
}
int main() {


	printf("%d ", 1);
	return 0;
}