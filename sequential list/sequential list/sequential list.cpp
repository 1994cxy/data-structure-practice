// sequential list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//初始化一个空的顺序线性表
int InitList_Sq(Sqlist &L){
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(1);            //内存分配失败
	L.length = 0;                  //初始元素0个
	L.listsize = LIST_INIT_SIZE;    //初始表长
	return 0;
}

//顺序线性表的插入
//线性表L，在i位置之前插入，插入的值为e
//i的合法值为:0<=i<=ListLength_Sq(L)
int ListInsert_Sq(Sqlist &L,int i,ElemType e){

	ElemType *p,*insert;  //插入位置的地址,最后一个元素的地址
	
	if(i<0||i>L.length){
		printf("插入位置不合法！");
		return -1;   
	}
	if(L.length>=L.listsize){    //元素个数达到上限时，重新分配内存，增加表长
		L.elem = (ElemType*)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType));
		if(!L.elem) exit(1);   //内存重新分配失败
		L.listsize += LISTINCREMENT;
	}

	insert = L.elem+i;   //得到插入位置的地址
	for(p = L.elem+(L.length-1);p >= insert;--p){  //插入位置后的元素后移1
		*(p+1) = *p;
	}
	*insert = e;
	++L.length;  //当前元素个数
	return 0;
}

//删除一个元素，并返回此元素值
//输入参数：线性表起始地址L，要删除的参数位置i(0<=i<=(L.length-1))
ElemType ListDelete_Sq(Sqlist &L,int i){

	ElemType e;
	e = *(L.elem+i);    //记录被删除元素的值

	if(i<0||i>(L.length-1)){
		printf("删除位置不合法！");
		return -1;
	}

	for(;i <= (L.length-1);++i){         //被删除元素之后的元素前移1
		*(L.elem+i) = *(L.elem+(i+1));
	}
	--L.length;           //表长-1

	return e;
}


//在链表中查找与e满足compare（）关系的_第一个_元素
//并返回它的位置（0-(L.length-1)）
//若不存在，则返回-1
//关系满足时，compare函数应返回1，否则返回0
int LocateElem_Sq(Sqlist &L,ElemType e,int (*compare)(ElemType,ElemType)){
	int i = 0;
	while((i <= (L.length-1))&&!(compare(*(L.elem+i),e))) ++i;
	if(i <= (L.length-1)) return i;
	else return -1;
}
//比较两个参数值是否相等
int compare(ElemType a,ElemType b){
	if(a == b) return 1;
	else return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ElemType e;
	int i;

	Sqlist sqlist1;        //生成一个Sqlist型的引用sqlist1
	InitList_Sq(sqlist1);   //初始化sqlist1

	for(i = 0;i <= 14;++i){       //对sqlist1连续赋值 0到14
		ListInsert_Sq(sqlist1,i,i);
	}
	for(i = 0;i <= (sqlist1.length-1);++i){     //显示赋值结果
		printf("顺序线性表的第%d个元素为%d\n",i,*(sqlist1.elem+i));
	}

/*	
	e = ListDelete_Sq(sqlist1,7);      //删除一个元素
	printf("被删除的元素为%d\n",e);
	for(i = 0;i <= (sqlist1.length-1);++i){    //显示删除后的结果
		printf("顺序线性表的第%d个元素为%d\n",i,*(sqlist1.elem+i));
	}
*/

	typedef int(*cmp)(ElemType,ElemType);
	cmp cmp1;
	cmp1 = &compare;
	printf("元素的位置为%d",LocateElem_Sq(sqlist1,15,cmp1));

	getchar();

	return 0;
}


