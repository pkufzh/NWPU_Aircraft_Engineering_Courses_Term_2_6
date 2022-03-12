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
            case 1: printf("请输入要新建的学生个数:");
                            scanf("%d",&n);
                            input(student,n);
                            write(student,n);
                            break;
            case 2: read(student);
					output(student);
					break;
            case 3: printf("请选择:\n1 按语文排序 2 按英语排序  3 按数学排序  4 按物理排序  5 按平均分排序\n");
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
                            printf("按性别筛选请按 1   按平均分筛选请按 2\n");
                            scanf("%d",&k);
                            getchar();
                            switch(k)
                            {
                                case 1: printf("筛选女生请按 f  筛选男生请按 m\n");
                                        scanf("%c",&zi);
                                        if(zi=='f') screening_sex(student,'f');
                                        else if (zi=='m') screening_sex(student,'m');
                                        break;
                                case 2:printf("请输入筛选的平均分大于多少分？");
                                        scanf("%d",&zi);
                                        getchar();
                                        break;
                            }
            case 6: printf("请输入要增加的学生个数:");
                    scanf("%d",&n);
                            //未完成

                    break;
            case 7: printf("请选择：\n1 按学号查找 2 按班级查找");
                           //未完成
                    break;
            case 8: exit(0);
        }
    }
    return 0;
}


void menu()
{
    printf("\n\n\t\t\t学生成绩管理程序\n");
    printf("\n菜单:\n1.新建学生记录文件\t 2.显示学生记录\t    3.排序\t\t 4.求平均值\t\n5.筛选\t\t\t 6.增加学生记录\t    7.查找学生记录\t 8.退出\n");
    printf("请输入你的选则，然后按enter:");
}
