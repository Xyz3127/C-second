#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
}stu,*pstu;//stu�ṹ�����,*pstu�ṹ��ָ�����

//1002 zxy M 25 95.50 shuozhou
//1005 zxy M 25 95.50 shuozhou
//1008 zxy M 25 95.50 shuozhou

typedef int INTEGER;//��int�����

int main()
{
	stu s = { 1001,"zxy",'M',25,95.5,"shuozhou" };
	stu sarr[3];
	printf("1-----%d %s %c %d %5.2f %s\n", s.num, s.name, s.sex, s.age, s.score, s.addr);
	for (INTEGER i = 0; i < 3; i++) {
		scanf("%d%s %c%d%f%s", &sarr[i].num, &sarr[i].name, &sarr[i].sex,
			&sarr[i].age, &sarr[i].score, &sarr[i].addr);
	}
	for (INTEGER i = 0; i < 3; i++) {
		printf("2-----%d %s %c %d %5.2f %s\n", sarr[i].num, sarr[i].name, sarr[i].sex,
			sarr[i].age, sarr[i].score, sarr[i].addr);
	}

	pstu p = &sarr;//���ýṹ��ָ���������ָ�룬��ͬ��stu *p = &sarr;
	printf("3-----%d %s %c %d %5.2f %s\n", (*p).num, (*p).name, (*p).sex,
		(*p).age, (*p).score, (*p).addr);//������ȼ������ǣ���˻�������㣬������Ҫ������
	printf("3-----%d %s %c %d %5.2f %s\n", p->num, p->name, p->sex,
		p->age, p->score, p->addr);//������ȼ�
	int num = p->num++;//->�����ȼ�����++����˵���++ȥ��������ִ��->��=��
	//����ٶ�p->num����++
	printf("%d %d\n", num, p->num);//num=1002,ͬʱp->num��ֵ��һΪ1003
	num = p++->num;		//��ִ��->��=���ٶ�p ++
	printf("%d %d", num, p->num);//num=1003(��Ϊǰ���һ��)������pָ��++��ָ��1005
}