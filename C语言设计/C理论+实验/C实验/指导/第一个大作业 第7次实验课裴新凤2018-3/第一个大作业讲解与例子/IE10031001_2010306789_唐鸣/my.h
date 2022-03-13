#ifndef _MY_H
#define _MY_H

extern int count;
#define N 30

struct student
{ char name[20];
  int xuhao;
  int xuehao;
  char sex;
  float mark[5];// 语文 英语 数学 物理 平均
};

void menu();
void input(struct student  *p,int n);
void output(struct student *p);
void average(struct student *p);
void order (struct student stu[],int m);
void screening_average(struct student *p,int m);
void write(struct student *p,int n);
void screening_sex(struct student *p,char male);
void read(struct student *p);
void add(struct student *p,int n);

#endif


