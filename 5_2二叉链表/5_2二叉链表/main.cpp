#include "head.h"
extern Sqstack S;

void visit(BiTree T) {
	printf("%d ", T->data);
}
// 递归遍历算法
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

// 非递归遍历算法
// 利用栈 直线非递归遍历二叉树
// 中序遍历非递归算法

BiTree BT;
BiNode* creatNode(int data) {
	BiNode* T = (BiNode*)malloc(sizeof(BiNode));
	assert(T);
	T->data = data;
	T->Lchild = NULL;
	T->Rchild = NULL;
	return T;
}
bool InitBinTree(BiTree T, int data) {
	T = (BiNode*)malloc(sizeof(BiNode)* MAXSIZE);
	assert(T);
	T->data = data;
	T->Lchild = NULL;
	T->Rchild = NULL;
	return true;
}

bool InOrderTraverse_N(BiTree T) {
	BiTree p = T;
	BiTree q = NULL;
	InitStack(S);
	while (p || !EmptyStack(S)) {
		if (p) {
			Push(S, q);
			p = p->Lchild;
		}
		else {
			Pop(S, q);
			printf("%d ", 1);//实际是 q->data   这里是因为 二叉树还为建立  就打印了 1
			assert(q);
			p = q->Rchild;
		}
	}
	return true;
}
int main() {
	
	printf("%d ", 1);
	return 0;
}