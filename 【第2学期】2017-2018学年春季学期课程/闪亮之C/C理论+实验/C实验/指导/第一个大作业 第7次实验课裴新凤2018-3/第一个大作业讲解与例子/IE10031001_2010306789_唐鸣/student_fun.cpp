#include "my.h"
#include<stdio.h>

void screening_sex(struct student *p,char male)//�����Ա�ɸѡ
{
    struct student *q;
    printf("����    ���    ѧ��    �Ա�    ����   Ӣ��    ��ѧ    ����    ƽ��\n");
    for(q=p;q<p+count;q++)
        if(q->sex==male)
            printf("%-8s%-8d%-8d%-8c%-8.1f%-8.1f%-8.1f%-8.1f%-8.1f\n",
            q->name,q->xuhao,q->xuehao,q->sex,q->mark[0],q->mark[1],q->mark[2],q->mark[3],q->mark[4]);
}

 void screening_average(struct student *p,int m)//δʵ�ֵĿպ���
{

 }

void order (struct student stu[],int m)//����ĳ������ѧ������
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
    for(i=0;i<count;i++)//������д��ÿ������Ԫ�صĳ�Աxuhao
        stu[i].xuhao=count-i;
}

void average(struct student *p)
{
    struct student  *q;
    for(q=p;q<p+count;q++)
    q->mark[4]=(q->mark[0]+q->mark[1]+q->mark[2]+q->mark[3])/4;
}
