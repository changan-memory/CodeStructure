#include <iostream>
#include <string>
using namespace std;

#define MaxSize 20		//设记录不超过20个
typedef struct {
	int Keyword;	//设关键字为 整形
	string otherInfo;		//其他数据项
}RedType;		//record type

typedef struct {
	RedType data[MaxSize+1];	//顺序表 data[0]  一般用作哨兵
	int length;		//顺序表的长度不算data[0]
}SqList;

//顺序插入排序
//顺序法定位插入位置
void InsertSort(SqList& L) {
	int i = 0, j = 0;		
	for (i = 2; i <= L.length; ++i) {	// i 为待插入的元素的下标
		//如果后面的比前面的小，就开始移动，否则不用执行任何操作
		if (L.data[i].Keyword < L.data[i-1].Keyword) {

			L.data[0] = L.data[i];	//待插入数据比前一个小，就复制为哨兵
			for (j = i - 1; L.data[j].Keyword > L.data[0].Keyword; --j) {
				L.data[j + 1] = L.data[j];		//当前元素比待插入元素大 就后移
			}
			L.data[j + 1] = L.data[0];
		}
	}
}

//二分法定位插入位置
void BInsertSort(SqList& L) {
	int i = 0, j = 0;
	int low = 0, high = 0, mid = 0;
	for (int i = 2; i <= L.length; ++i) {	//从第二个元素开始看
		L.data[0] = L.data[i];		//复制为哨兵

		//如果后面的比前面的小，就开始查找 并且 移动，否则不用执行任何操作
		if (L.data[i].Keyword < L.data[i-1].Keyword) {		
			low = 1, high = i - 1;
			while (low <= high) {
				mid = (low + high) / 2;
				if (L.data[0].Keyword < L.data[mid].Keyword)
					high = mid - 1;
				else
					low = mid + 1;
			}	//low 和 high 相等的时候也进入了循环 因此最后 high 比 low 小1
			for (j = i - 1; j >= high + 1; --j)		//依次移动元素
				L.data[j + 1] = L.data[j];
			L.data[high + 1] = L.data[0];		//最后插入
		}	
	}
}


int main() {
	/*RedType r1;
	r1.Keyword = 1;
	r1.otherInfo = "你好";
	RedType r2;
	r2 = r1;
	cout << r2.Keyword << " " << r2.otherInfo << endl;*/
	SqList L;
	L.length = 20;
	int j = 20;
	for (int i = 1; i <= L.length; i++) {
		L.data[i].Keyword = j--;
	}
	for (int i = 1; i <= L.length; i++) {
		cout << L.data[i].Keyword << " ";
	}
	cout << endl;
	InsertSort(L);
	for (int i = 1; i <= L.length; i++) {
		cout << L.data[i].Keyword << " ";
	}
	return 0;
}