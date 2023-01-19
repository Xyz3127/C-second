#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
};//结构体所占空间为68个字节，存在对齐，是为了提高效率

//1002 zxy M 25 95.50 shuozhou
//1005 zxy M 25 95.50 shuozhou
//1008 zxy M 25 95.50 shuozhou
int main()
{
	struct student s = { 1001,"zxy",'M',25,95.5,"shuozhou" };
	struct student sarr[3];
	printf("1-----%d %s %c %d %5.2f %s\n", s.num, s.name, s.sex, s.age, s.score, s.addr);
	for (int i = 0; i < 3; i++) {
		scanf("%d%s %c%d%f%s", &sarr[i].num, &sarr[i].name, &sarr[i].sex,
			&sarr[i].age, &sarr[i].score, &sarr[i].addr);
	}
	for (int i = 0; i < 3; i++) {
		printf("2-----%d %s %c %d %5.2f %s\n", sarr[i].num, sarr[i].name, sarr[i].sex,
			sarr[i].age, sarr[i].score, sarr[i].addr);
	}

	struct student* p;//结构体指针
	p = &sarr;
	printf("3-----%d %s %c %d %5.2f %s\n", (*p).num, (*p).name, (*p).sex, 
		(*p).age, (*p).score, (*p).addr);//点的优先级高于星，因此会先运算点，所以需要加括号
	printf("3-----%d %s %c %d %5.2f %s\n", p->num, p->name, p->sex,
		p->age, p->score, p->addr);//与上面等价
	int num = p->num++;//->的优先级大于++，因此当把++去掉后，是先执行->和=，
						//最后再对p->num整体++
	printf("%d %d\n", num, p->num);//num=1002,同时p->num的值加一为1003
	num = p++->num;		//先执行->和=，再对p ++
	printf("%d %d", num, p->num);//num=1003(因为前面加一了)，后面p指针++，指向1005
}