#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//�����Һ�̵�   �ö�������
typedef struct BiNode {
	int data;	//	������
	struct BiNode *Lchild, *Rchild;	//ָ����   ָ�����Һ���
}BiNode, *BiTree;	//ǰ���ǽ��   ������ָ��ý���ָ��

void visit(BiTree T) {
	printf("%d ", T->data);
}

//�������� ��������㷨
void PreOrderTraverse(BiTree T) {
	if (T == NULL)	//�ж϶������Ƿ�Ϊ��    Ϊ�յĻ�����
		return;
	else {
		//���� �� �� ��
		visit(T);	//�Խ����з���
		PreOrderTraverse(T->Lchild);// �ݹ����������
		PreOrderTraverse(T->Rchild);// �ݹ����������
	}
}

//�������� ��������㷨
void InOrderTraverse(BiTree T) {
	if (T == NULL)	//�ж϶������Ƿ�Ϊ��    Ϊ�յĻ�����
		return;
	else {
		//����  �� �� ��
		InOrderTraverse(T->Lchild);// �ݹ����������
		visit(T);	//�Խ����з���
		InOrderTraverse(T->Rchild);// �ݹ����������
	}
}

//�������� ��������㷨
void PostOrderTraverse(BiTree T) {
	if (T == NULL)	//�ж϶������Ƿ�Ϊ��    Ϊ�յĻ�����
		return;
	else {
		//����  �� �� ��
		PostOrderTraverse(T->Lchild);// �ݹ����������
		PostOrderTraverse(T->Rchild);// �ݹ����������
		visit(T);	//�Խ����з���
	}
}
int main() {


	printf("%d ", 1);
	return 0;
}