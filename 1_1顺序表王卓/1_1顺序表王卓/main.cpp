#define _CRT_SECURE_NO_WARNINGS 1
//#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
//��̬�Ļ��ö�̬�ڴ����
//��̬�Ļ��� ���� �� �궨��

//��̬��
//typedef struct SeqList {
//	int arr[MAXSIZE]; //��ʾ˳���Ŀռ����ʼλ��    ǰ�����������һ�㶼�ǽṹ������
//	int length;		//��ʾ˳���ĵ�ǰ����
//}SeqList;

typedef struct SeqList {
	int* init; //��ʾ˳���Ŀռ����ʼλ��    ǰ�����������һ�㶼�ǽṹ������
	int length;		//��ʾ˳���ĵ�ǰ����
	int MaxSize;
}SeqList;
SeqList L;

//��̬����   ��ʼ�����Ա�
void InitSqlist(SeqList& L) {
	L.init = (int*)malloc(sizeof(int) * L.MaxSize);
	assert(L.init);	//��ֹ�ռ����ʧ��
	L.length = 0;
	L.MaxSize = 4;
}
//�������Ա�
void DestroySqList(SeqList& L) {
	if (L.init)
		free(L.init);
}
// ������Ա�
void ClaerSqList(SeqList& L) {
	L.length = 0;
}
//�����Ա���
int GetLength(SeqList& L) {
	return L.length;
}
//�ж��Ƿ�ǿ�
bool EmptyJudge(SeqList& L) {
	if (L.length)
		return false;
	return true;
}
//��ȡ���Ա��� ��i��Ԫ��   ����ֱ�ӷ��ص� i ��Ԫ��
int Getele(SeqList& L, int i) {
	if (i < 1 || i>L.length)
		return -1;
	return L.init[i - 1];
}
//��ֵ���� ���Ա��е�Ԫ��   �жϱ������޶�ӦԪ��  ͬʱ���ظ�Ԫ�� �Ǳ��еĵڼ���Ԫ��
int GetEle(SeqList& L, int ele) {
	for (int i = 0; i < L.length; i++) {
		if (L.init[i] == ele)
			return i + 1;
	}
	return 0;
}
//��̬��˳�������
void IncreaseLen(SeqList& L, int len) {
	int* p = L.init;
	L.init = (int*)malloc(sizeof(int)* (len+L.MaxSize));
	assert(L.init);
	//ת��Ԫ��
	for (int i = 0; i < L.length; i++) {
		L.init[i] = p[i];
	}
	p = NULL;
	free(p);
	L.MaxSize = L.MaxSize + len;
}
void Insertele_1(SeqList& L, int i, int ele) {//����i����������Ԫ�غ��� j�����һ��Ԫ��(�±�Ϊlength-1)��ʼ
	for (int j = L.length-1; j >= i - 1; j--)	// ��Ҫ�ƶ������һ��Ԫ�ص��±�Ϊ(i-1)
		L.init[j + 1] = L.init[j];
	L.init[i-1] = ele;	//��i��Ԫ�ص������±�Ϊ i-1
	L.length++;
}
//��˳���� �� i ��λ���ϲ���һ��Ԫ��
bool Insertele_2(SeqList& L, int i, int ele) {
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length == L.MaxSize) {
		IncreaseLen(L, 1);
		Insertele_1(L, i, ele);
		return true;
	}
	Insertele_1(L, i, ele);
	return true;
}
//ɾ��˳����ϵ� i ��Ԫ��   ������
bool Delele(SeqList& L, int i, int& ele) {
	if (i<1 || i>L.length)
		return false;
	ele = L.init[i - 1];
	for (int j = i-1; j <= L.length-1; j++) {
		L.init[j] = L.init[j+1];
	}
	L.length--;
}

//����˳���
void printSqlist(SeqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.init[i]);
	}
	printf("\n");
}
int main() {
	InitSqlist(L);
	for (int i = 0; i < 5; i++) {
		Insertele_2(L, i + 1, i);
	}
	printSqlist(L);
	int x = 0;
	Delele(L, 5, x);
	printSqlist(L);

	return 0;
}