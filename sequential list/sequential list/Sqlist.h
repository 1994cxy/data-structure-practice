#pragma once  //防止头文件被多次include，造成错误

//顺序结构线性表的动态分配存储结构
#define LIST_INIT_SIZE 10 //顺序线性表的初始长度
#define LISTINCREMENT 5  //当空间不足时，顺序线性表的增加长度
#define ElemType int  //顺序线性表元素类型

struct Sqlist{
	ElemType *elem;        //存储空间基址
	int length;            //当前元素个数
	int listsize;          //总表长（可装多少元素）
};