#include <stdio.h>
#include "my.h"
#include <stdlib.h>
int count;
static struct student student[N];

int main()
{
    int k,choice,n;
    char zi;
    while(1)
    {
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("������Ҫ�½���ѧ������:");
                            scanf("%d",&n);
                            input(student,n);
                            write(student,n);
                            break;
            case 2: read(student);
					output(student);
					break;
            case 3: printf("��ѡ��:\n1 ���������� 2 ��Ӣ������  3 ����ѧ����  4 ����������  5 ��ƽ��������\n");
                            scanf("%d",&k);
                            read(student);
                            order(student,k);
                            output(student);
                            break;
            case 4: read(student);
                            average(student);
                            output(student);
                            write(student,count);
                            break;
            case 5: read(student);
                            printf("���Ա�ɸѡ�밴 1   ��ƽ����ɸѡ�밴 2\n");
                            scanf("%d",&k);
                            getchar();
                            switch(k)
                            {
                                case 1: printf("ɸѡŮ���밴 f  ɸѡ�����밴 m\n");
                                        scanf("%c",&zi);
                                        if(zi=='f') screening_sex(student,'f');
                                        else if (zi=='m') screening_sex(student,'m');
                                        break;
                                case 2:printf("������ɸѡ��ƽ���ִ��ڶ��ٷ֣�");
                                        scanf("%d",&zi);
                                        getchar();
                                        break;
                            }
            case 6: printf("������Ҫ���ӵ�ѧ������:");
                    scanf("%d",&n);
                            //δ���

                    break;
            case 7: printf("��ѡ��\n1 ��ѧ�Ų��� 2 ���༶����");
                           //δ���
                    break;
            case 8: exit(0);
        }
    }
    return 0;
}


void menu()
{
    printf("\n\n\t\t\tѧ���ɼ��������\n");
    printf("\n�˵�:\n1.�½�ѧ����¼�ļ�\t 2.��ʾѧ����¼\t    3.����\t\t 4.��ƽ��ֵ\t\n5.ɸѡ\t\t\t 6.����ѧ����¼\t    7.����ѧ����¼\t 8.�˳�\n");
    printf("���������ѡ��Ȼ��enter:");
}
