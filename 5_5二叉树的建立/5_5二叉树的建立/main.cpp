#include <stdlib.h>
#include <assert.h>
#include <iostream>
//�����Һ�̵�   �ö�������
typedef struct BiNode {
	char data;	//	������
	struct BiNode* LChild, * RChild;	//���Һ���ָ����
}BiNode, *BiTree;	//ǰ���ǽ��   ������ָ��ý���ָ��

// �˴��Ķ���������ڴ�ŵ������� char ����      
bool creatBiTree(BiTree& T) {
	char input;
	std::cin >> input;	//��������
	if (input == '#')	// ���� int  ���� char ���������μ��壬�Ƚϵ�ʱ��Ƚ�  ASCII ��ֵ
		T = NULL;
	else {
		if (!(T = (BiNode*)malloc(sizeof(BiNode))))	// �������
			return false;
		T->data = input;
		creatBiTree(T->LChild);	//�ݹ齨��������������
		creatBiTree(T->RChild);	//�ݹ齨��������������
	}
	return true;
}
//�������� ��������㷨
void PreOrderTraverse(BiTree T) {
	if (T == NULL)	//�ж϶������Ƿ�Ϊ��    Ϊ�յĻ�����
		return;
	else {
		//���� �� �� �� //�Խ����з���
		std::cout << T->data << " ";
		PreOrderTraverse(T->LChild);// �ݹ����������
		PreOrderTraverse(T->RChild);// �ݹ����������
	}
	
}

bool CopyBiTree(BiTree& NewT, BiTree T) {	// ��һ�������� Ҫ����ȥ�Ŀռ�
	if (T == NULL) {	//�ж��Ƿ�Ϊ�գ��յĻ��Ͳ���Ҫ������
		NewT = NULL;
		return false;	//����ǿ����Ļ����� false
	}
	else {	//��Ϊ�յĻ�  ����ռ俪ʼ����
		NewT = (BiNode*)malloc(sizeof(BiNode));
		assert(NewT);
		// ���Ƹ����
		NewT->data = T->data;
		//�ݹ鸴��������
		CopyBiTree(NewT->LChild, T->LChild);	
		// �ݹ鸴��������
		CopyBiTree(NewT->RChild, T->RChild);	
		return true;	// ���ƽ������� true
	}
}
int main() {
	BiTree T;
	creatBiTree(T);
	PreOrderTraverse(T);
	std::cout << "\n";
	BiTree T2;
	CopyBiTree(T2, T);
	PreOrderTraverse(T2);
	std::cout << "\n";
	return 0;
}