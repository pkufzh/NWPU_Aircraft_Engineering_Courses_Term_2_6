#include "my.h"
#include<stdio.h>

void screening_sex(struct student *p,char male)//按照性别筛选
{
    struct student *q;
    printf("姓名    序号    学号    性别    语文   英语    数学    物理    平均\n");
    for(q=p;q<p+count;q++)
        if(q->sex==male)
            printf("%-8s%-8d%-8d%-8c%-8.1f%-8.1f%-8.1f%-8.1f%-8.1f\n",
            q->name,q->xuhao,q->xuehao,q->sex,q->mark[0],q->mark[1],q->mark[2],q->mark[3],q->mark[4]);
}

 void screening_average(struct student *p,int m)//未实现的空函数
{

 }

void order (struct student stu[],int m)//按照某分数对学生排序
{
    int i,j;struct student t;
    m=m-1;
    for(j=0;j<count-1;j++)
        for(i=0;i<count-1-j;i++)
            if(stu[i].mark[m]>stu[i+1].mark[m]){
                 t=stu[i];
                stu[i]=stu[i+1];
                stu[i+1]=t;
                }
    for(i=0;i<count;i++)//将名次写入每个数组元素的成员xuhao
        stu[i].xuhao=count-i;
}

void average(struct student *p)
{
    struct student  *q;
    for(q=p;q<p+count;q++)
    q->mark[4]=(q->mark[0]+q->mark[1]+q->mark[2]+q->mark[3])/4;
}
