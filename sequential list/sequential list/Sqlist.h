#pragma once  //��ֹͷ�ļ������include����ɴ���

//˳��ṹ���Ա�Ķ�̬����洢�ṹ
#define LIST_INIT_SIZE 10 //˳�����Ա�ĳ�ʼ����
#define LISTINCREMENT 5  //���ռ䲻��ʱ��˳�����Ա�����ӳ���
#define ElemType int  //˳�����Ա�Ԫ������

struct Sqlist{
	ElemType *elem;        //�洢�ռ��ַ
	int length;            //��ǰԪ�ظ���
	int listsize;          //�ܱ�����װ����Ԫ�أ�
};