#include <string.h>
#include <stdio.h>

#define Max_students 100
// 定义最大学生人数为100人
struct student
{
    int id;
    char name[20];
    float score[3]; // 3科成绩
    float avg;      // 平均分
};

struct student students[Max_students];
int count = 0; // 现在学生人数

// 头函数声明
// 功能：添加学生、显示所有学生、平均分排序（降序、学号查找、删除学生、显示菜单

// 学号查找
int id_find(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            return i;
        }
        return -1;
    }
}

// 添加学生
void addStuents()
{
    if (count >= Max_students)
    {
        printf("人数已满\n");
        return;
    }
    // 用指针只想待写入的位置
    struct student *s = &students[count];

    printf("输入姓名：\n");
    scanf("%19f", &s->name); // 限制宽度 防止溢出name【20】

    // 输入学号重复
    if (id_find(s->id) != -1)
    {
        printf("添加无效，学号%d也存在\n", s->id);
        return;
    }

    printf("输入学号：\n");
    scanf("%d", &s->id);

    float sum = 0.00f;

    for (int i = 0; i < 3; i++)
    {
        printf("输入第%d门课的成绩：", i + 1);
        scanf("%.1f", &s->score[i]);
        sum += s->score[i];
    }
    // 计算平均分
    s->avg = sum / 3.00f;
    // 学生人数+1
    count++;
    printf("\n添加成功\n");
}

// 显示所有学生
void display_all()
{
    if (count == 0)
    {
        printf("\n暂无学生记录\n");
        return;
    }

    printf("\n共%d名学生\n", count);
    printf("------------------------------------------------------------\n");
    printf("%-8s %-10s %8s %8s %8s %10s\n",
           "学号", "姓名", "成绩1", "成绩2", "成绩3", "平均分");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-8d %-10s %8.2f %8.2f %8.2f %10.2f\n",
               students[i].id,
               students[i].name,
               students[i].score[0],
               students[i].score[1],
               students[i].score[2],
               students[i].avg);
    }

    printf("------------------------------------------------------------\n");
}

// 按平均分高到低排序
void sort_by_average_H2L()
{
    // 无需排序部分
    if (count < 2)
    {
        printf("\n学生人数不足2人，无需排序\n");
        return;
    }

    // 排序部分,冒泡排序，
    for (int i = 0; i < count - 1; i++) // 外层：控制轮数
    {
        for (int j = 0; j < count - 1 - i; j++) // 内层：控制每轮比较的次数
        {
            if (students[j].avg < students[j + 1].avg)
            {
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\n已按平均分从高到低排列\n");
}

// 按平均分从低到高排序
void sort_by_average_L2H()
{
    if (count < 2)
    {
        printf("\n学生人数不足2人，无需排序\n");
        return;
    }

    // 排序部分
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (students[j].avg > students[j + 1].avg)
            {
                struct student temp = students[j + 1];
                students[j + 1] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\n已按平均分由低到高排序\n");
}

// 删除学生
void dele_S(int id)
{
    int idx = id_find(id);
    if (idx == -1)
    {
        printf("\n未找到学号%d的学生\n", id);
        return;
    }

    for (int i = idx; i < count; i++)
    {
        // 用后一个覆盖要删除的
        students[i] = students[i + 1];
        // 人数-1
        count--;
        printf("\n学号为%d的学生已删除\n", id);
    }
}

// 显示菜单
void showmenu()
{
    printf("\n=== 学生成绩管理系统 ===\n");
    printf("1. 添加学生\n");
    printf("2. 显示所有\n");
    printf("3. 按平均分排序(高到低)\n");
    printf("4. 按平均分排序(低到高)\n");
    printf("5. 查找学生\n");
    printf("6. 删除学生\n");
    printf("7. 退出\n");
    printf("\n请选择：");
}

int main()
{
    int choice, id;
    while (1)
    {
        showmenu();
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("输入无效\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            addStuents();
            break;
        case 2:
            display_all();
            break;
        case 3:
            sort_by_average_H2L();
            break;
        case 4:
            sort_by_average_L2H();
            break;
        case 5:
        {
            printf("输入要查找的学号：");
            scanf("%d", &id);
            int idx = id_find(id);
            if (idx != -1)
            {
                printf("找到：%s,平均分：%.2f\n", students[idx].name, students[idx].avg);
            }
            else
            {
                printf("未找到\n");
            }
            break;
        }
        case 6:
        {
            printf("输入要删除的学生学号：\n");
            scanf("%d", &id);
            dele_S(id);
            break;
        }
        case 7:
            return 0;

        default:
            printf("无效选择\n");
        }
    }
}
