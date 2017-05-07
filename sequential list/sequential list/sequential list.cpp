// sequential list.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//��ʼ��һ���յ�˳�����Ա�
int InitList_Sq(Sqlist &L){
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(1);            //�ڴ����ʧ��
	L.length = 0;                  //��ʼԪ��0��
	L.listsize = LIST_INIT_SIZE;    //��ʼ��
	return 0;
}

//˳�����Ա�Ĳ���
//���Ա�L����iλ��֮ǰ���룬�����ֵΪe
//i�ĺϷ�ֵΪ:0<=i<=ListLength_Sq(L)
int ListInsert_Sq(Sqlist &L,int i,ElemType e){

	ElemType *p,*insert;  //����λ�õĵ�ַ,���һ��Ԫ�صĵ�ַ
	
	if(i<0||i>L.length){
		printf("����λ�ò��Ϸ���");
		return -1;   
	}
	if(L.length>=L.listsize){    //Ԫ�ظ����ﵽ����ʱ�����·����ڴ棬���ӱ�
		L.elem = (ElemType*)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType));
		if(!L.elem) exit(1);   //�ڴ����·���ʧ��
		L.listsize += LISTINCREMENT;
	}

	insert = L.elem+i;   //�õ�����λ�õĵ�ַ
	for(p = L.elem+(L.length-1);p >= insert;--p){  //����λ�ú��Ԫ�غ���1
		*(p+1) = *p;
	}
	*insert = e;
	++L.length;  //��ǰԪ�ظ���
	return 0;
}

//ɾ��һ��Ԫ�أ������ش�Ԫ��ֵ
//������������Ա���ʼ��ַL��Ҫɾ���Ĳ���λ��i(0<=i<=(L.length-1))
ElemType ListDelete_Sq(Sqlist &L,int i){

	ElemType e;
	e = *(L.elem+i);    //��¼��ɾ��Ԫ�ص�ֵ

	if(i<0||i>(L.length-1)){
		printf("ɾ��λ�ò��Ϸ���");
		return -1;
	}

	for(;i <= (L.length-1);++i){         //��ɾ��Ԫ��֮���Ԫ��ǰ��1
		*(L.elem+i) = *(L.elem+(i+1));
	}
	--L.length;           //��-1

	return e;
}


//�������в�����e����compare������ϵ��_��һ��_Ԫ��
//����������λ�ã�0-(L.length-1)��
//�������ڣ��򷵻�-1
//��ϵ����ʱ��compare����Ӧ����1�����򷵻�0
int LocateElem_Sq(Sqlist &L,ElemType e,int (*compare)(ElemType,ElemType)){
	int i = 0;
	while((i <= (L.length-1))&&!(compare(*(L.elem+i),e))) ++i;
	if(i <= (L.length-1)) return i;
	else return -1;
}
//�Ƚ���������ֵ�Ƿ����
int compare(ElemType a,ElemType b){
	if(a == b) return 1;
	else return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ElemType e;
	int i;

	Sqlist sqlist1;        //����һ��Sqlist�͵�����sqlist1
	InitList_Sq(sqlist1);   //��ʼ��sqlist1

	for(i = 0;i <= 14;++i){       //��sqlist1������ֵ 0��14
		ListInsert_Sq(sqlist1,i,i);
	}
	for(i = 0;i <= (sqlist1.length-1);++i){     //��ʾ��ֵ���
		printf("˳�����Ա�ĵ�%d��Ԫ��Ϊ%d\n",i,*(sqlist1.elem+i));
	}

/*	
	e = ListDelete_Sq(sqlist1,7);      //ɾ��һ��Ԫ��
	printf("��ɾ����Ԫ��Ϊ%d\n",e);
	for(i = 0;i <= (sqlist1.length-1);++i){    //��ʾɾ����Ľ��
		printf("˳�����Ա�ĵ�%d��Ԫ��Ϊ%d\n",i,*(sqlist1.elem+i));
	}
*/

	typedef int(*cmp)(ElemType,ElemType);
	cmp cmp1;
	cmp1 = &compare;
	printf("Ԫ�ص�λ��Ϊ%d",LocateElem_Sq(sqlist1,15,cmp1));

	getchar();

	return 0;
}


