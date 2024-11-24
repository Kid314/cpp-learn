#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char id[20];
    char name[20];
    char sex[2];
    float chinese;
    float math;
    float english;
    float physics;
    float chemistry;
    float biology;
    float politics;
    float history;
    float geography;
    float computer_science; 
    char selected_subjects[3][20]; // 选择的三门科目
    struct Student *next;
} Student;

Student *head = NULL;

// 获取科目名称
const char* get_subject_name(int subject_code) {
    switch (subject_code) {
        case 1: return "physics";
        case 2: return "chemistry";
        case 3: return "biology";
        case 4: return "politics";
        case 5: return "history";
        case 6: return "geography";
        case 7: return "computer_science";
        default: return "";
    }
}

// 添加学生信息
void addstu() {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    printf("请输入学生基本信息 (学号 姓名 性别): ");
    scanf("%s %s %s", newStudent->id, newStudent->name, newStudent->sex);

    int subject_codes[3];
    printf("请输入选择的三门科目编号 (1: 物理, 2: 化学, 3: 生物, 4: 政治, 5: 历史, 6: 地理, 7: 技术): ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &subject_codes[i]);
        strcpy(newStudent->selected_subjects[i], get_subject_name(subject_codes[i]));
    }

    printf("请输入学生的成绩 (语文 数学 英语 %s %s %s): ",
           newStudent->selected_subjects[0], newStudent->selected_subjects[1], newStudent->selected_subjects[2]);
    float selected_scores[3];
    scanf("%f %f %f %f %f %f", 
          &newStudent->chinese, &newStudent->math, &newStudent->english,
          &selected_scores[0], &selected_scores[1], &selected_scores[2]);

    // 将选考科目的成绩存储在相应的字段中
    for (int i = 0; i < 3; i++) {
        if (strcmp(newStudent->selected_subjects[i], "physics") == 0) {
            newStudent->physics = selected_scores[i];
        } else if (strcmp(newStudent->selected_subjects[i], "chemistry") == 0) {
            newStudent->chemistry = selected_scores[i];
        } else if (strcmp(newStudent->selected_subjects[i], "biology") == 0) {
            newStudent->biology = selected_scores[i];
        } else if (strcmp(newStudent->selected_subjects[i], "politics") == 0) {
            newStudent->politics = selected_scores[i];
        } else if (strcmp(newStudent->selected_subjects[i], "history") == 0) {
            newStudent->history = selected_scores[i];
        } else if (strcmp(newStudent->selected_subjects[i], "geography") == 0) {
            newStudent->geography = selected_scores[i];
        } else if (strcmp(newStudent->selected_subjects[i], "computer_science") == 0) {
            newStudent->computer_science = selected_scores[i];
        }
    }

    // 检查是否已有相同学号的学生
    Student *current = head;
    while (current != NULL) {
        if (strcmp(current->id, newStudent->id) == 0) {
            printf("插入失败: 学号已存在\n");
            free(newStudent);
            return;
        }
        current = current->next;
    }

    newStudent->next = head;
    head = newStudent;

    printf("插入成功:\n%s %s %s\n", newStudent->id, newStudent->name, newStudent->sex);
    printf("选择的三门科目: %s %s %s\n", newStudent->selected_subjects[0], newStudent->selected_subjects[1], newStudent->selected_subjects[2]);
    printf("成绩:\n语文: %.1f 数学: %.1f 英语: %.1f %s: %.1f %s: %.1f %s: %.1f\n", 
           newStudent->chinese, newStudent->math, newStudent->english,
           newStudent->selected_subjects[0], selected_scores[0],
           newStudent->selected_subjects[1], selected_scores[1],
           newStudent->selected_subjects[2], selected_scores[2]);
}

// 显示学生信息
void displaystu() {
    printf("学生列表:\n");
    Student *current = head;
    Student *students[100];
    int count = 0;

    while (current != NULL) {
        students[count++] = current;
        current = current->next;
    }

    // 按学号排序
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j]->id, students[j + 1]->id) > 0) {
                Student *temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s %s %s %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", 
               students[i]->id, students[i]->name, students[i]->sex, 
               students[i]->chinese, students[i]->math, students[i]->english,
               students[i]->physics, students[i]->chemistry, students[i]->biology,
               students[i]->politics, students[i]->history, students[i]->geography, students[i]->computer_science);
        printf("选择的三门科目: %s %s %s\n", students[i]->selected_subjects[0], students[i]->selected_subjects[1], students[i]->selected_subjects[2]);
    }
}

// 查询学生信息
void findstu() {
    char id[20];
    printf("请输入学生的学号: ");
    scanf("%s", id);

    Student *current = head;
    printf("查询结果:\n");

    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            printf("%s %s %s\n", current->id, current->name, current->sex);
            printf("选择的三门科目: %s %s %s\n", current->selected_subjects[0], current->selected_subjects[1], current->selected_subjects[2]);
            printf("成绩:\n语文: %.1f 数学: %.1f 英语: %.1f %s: %.1f %s: %.1f %s: %.1f\n", 
                   current->chinese, current->math, current->english,
                   current->selected_subjects[0], strcmp(current->selected_subjects[0], "physics") == 0 ? current->physics : strcmp(current->selected_subjects[0], "chemistry") == 0 ? current->chemistry : strcmp(current->selected_subjects[0], "biology") == 0 ? current->biology : strcmp(current->selected_subjects[0], "politics") == 0 ? current->politics : strcmp(current->selected_subjects[0], "history") == 0 ? current->history : strcmp(current->selected_subjects[0], "geography") == 0 ? current->geography : current->computer_science,
                   current->selected_subjects[1], strcmp(current->selected_subjects[1], "physics") == 0 ? current->physics : strcmp(current->selected_subjects[1], "chemistry") == 0 ? current->chemistry : strcmp(current->selected_subjects[1], "biology") == 0 ? current->biology : strcmp(current->selected_subjects[1], "politics") == 0 ? current->politics : strcmp(current->selected_subjects[1], "history") == 0 ? current->history : strcmp(current->selected_subjects[1], "geography") == 0 ? current->geography : current->computer_science,
                   current->selected_subjects[2], strcmp(current->selected_subjects[2], "physics") == 0 ? current->physics : strcmp(current->selected_subjects[2], "chemistry") == 0 ? current->chemistry : strcmp(current->selected_subjects[2], "biology") == 0 ? current->biology : strcmp(current->selected_subjects[2], "politics") == 0 ? current->politics : strcmp(current->selected_subjects[2], "history") == 0 ? current->history : strcmp(current->selected_subjects[2], "geography") == 0 ? current->geography : current->computer_science);
            return;
        }
        current = current->next;
    }
    printf("查询失败: 学生不存在\n");
}

// 删除学生信息
void deletestu() 
{
    char id[20];
    printf("请输入要删除学生的学号: ");
    scanf("%s", id);

    Student *current = head;
    Student *prev = NULL;
    printf("删除结果:\n");

    while (current != NULL) 
    {
        if (strcmp(current->id, id) == 0) 
        {
            if (prev == NULL) 
            {
                head = current->next;
            } 
            else 
            {
                prev->next = current->next;
            }
            free(current);
            printf("删除成功\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("删除失败: 学生不存在\n");
}

// 修改学生信息
void modifystu() 
{
    char id[20];
    char newName[20];
    char newSex[2];
    float newChinese, newMath, newEnglish;
    float newSelectedScores[3];
    int newSubjectCodes[3];
    char newSelectedSubjects[3][20];

    printf("请输入要修改信息的学生学号: ");
    scanf("%s", id);

    Student *current = head;
    while (current != NULL) 
    {
        if (strcmp(current->id, id) == 0) 
        {
            printf("请输入修改后的学生信息 (新姓名 新性别 新选考科目编号1 新选考科目编号2 新选考科目编号3 新语文 新数学 新英语 %s %s %s): ",
                   get_subject_name(newSubjectCodes[0]), get_subject_name(newSubjectCodes[1]), get_subject_name(newSubjectCodes[2]));
            scanf("%s %s %d %d %d %f %f %f %f %f %f", 
                  newName, newSex, 
                  &newSubjectCodes[0], &newSubjectCodes[1], &newSubjectCodes[2],
                  &newChinese, &newMath, &newEnglish, 
                  &newSelectedScores[0], &newSelectedScores[1], &newSelectedScores[2]);

            strcpy(current->name, newName);
            strcpy(current->sex, newSex);
            for (int i = 0; i < 3; i++) {
                strcpy(current->selected_subjects[i], get_subject_name(newSubjectCodes[i]));
            }
            current->chinese = newChinese;
            current->math = newMath;
            current->english = newEnglish;

            // 将选考科目的成绩存储在相应的字段中
            for (int i = 0; i < 3; i++) {
                if (strcmp(current->selected_subjects[i], "physics") == 0) {
                    current->physics = newSelectedScores[i];
                } else if (strcmp(current->selected_subjects[i], "chemistry") == 0) {
                    current->chemistry = newSelectedScores[i];
                } else if (strcmp(current->selected_subjects[i], "biology") == 0) {
                    current->biology = newSelectedScores[i];
                } else if (strcmp(current->selected_subjects[i], "politics") == 0) {
                    current->politics = newSelectedScores[i];
                } else if (strcmp(current->selected_subjects[i], "history") == 0) {
                    current->history = newSelectedScores[i];
                } else if (strcmp(current->selected_subjects[i], "geography") == 0) {
                    current->geography = newSelectedScores[i];
                } else if (strcmp(current->selected_subjects[i], "computer_science") == 0) {
                    current->computer_science = newSelectedScores[i];
                }
            }

            printf("修改成功:\n%s %s %s\n", current->id, current->name, current->sex);
            printf("选择的三门科目: %s %s %s\n", current->selected_subjects[0], current->selected_subjects[1], current->selected_subjects[2]);
            printf("成绩:\n语文: %.1f 数学: %.1f 英语: %.1f %s: %.1f %s: %.1f %s: %.1f\n", 
                   current->chinese, current->math, current->english,
                   current->selected_subjects[0], newSelectedScores[0],
                   current->selected_subjects[1], newSelectedScores[1],
                   current->selected_subjects[2], newSelectedScores[2]);
            return;
        }
        current = current->next;
    }
    printf("修改失败: 学生不存在\n");
}

// 修改单门或多门指定科目成绩
void modifySingleOrMultipleSubjects() {
    char id[20];
    printf("请输入要修改成绩的学生学号: ");
    scanf("%s", id);

    Student *current = head;
    printf("修改结果:\n");

    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            char subject[20];
            float newScore;
            printf("请输入要修改的科目和新的成绩 (输入 'done' 结束): ");
            while (1) {
                scanf("%s", subject);
                if (strcmp(subject, "done") == 0) break;
                scanf("%f", &newScore);

                if (strcmp(subject, "chinese") == 0) current->chinese = newScore;
                else if (strcmp(subject, "math") == 0) current->math = newScore;
                else if (strcmp(subject, "english") == 0) current->english = newScore;
                else if (strcmp(subject, "physics") == 0) current->physics = newScore;
                else if (strcmp(subject, "chemistry") == 0) current->chemistry = newScore;
                else if (strcmp(subject, "biology") == 0) current->biology = newScore;
                else if (strcmp(subject, "politics") == 0) current->politics = newScore;
                else if (strcmp(subject, "history") == 0) current->history = newScore;
                else if (strcmp(subject, "geography") == 0) current->geography = newScore;
                else if (strcmp(subject, "computer_science") == 0) current->computer_science = newScore;
                else printf("未知科目: %s\n", subject);
            }
            printf("%s %s %s %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", 
                   current->id, current->name, current->sex, 
                   current->chinese, current->math, current->english,
                   current->physics, current->chemistry, current->biology,
                   current->politics, current->history, current->geography, current->computer_science);
            return;
        }
        current = current->next;
    }
    printf("修改失败: 学生不存在\n");
}

// 菜单
void Menu() 
{
    printf("学生信息管理系统\n");
    printf("-------------------------------\n");
    printf("|1、添加学生信息              |\n");
    printf("|2、显示学生信息              |\n");
    printf("|3、查询学生信息              |\n");
    printf("|4、删除学生信息              |\n");
    printf("|5、修改学生信息              |\n");
    printf("|6、修改单门或多门指定科目成绩|\n");
    printf("|7、退出                      |\n");
    printf("-------------------------------\n");
    printf("请输入相应的序号选择!\n");
}

int main() 
{
    int choice;
    while (1) 
    {
        Menu();
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                addstu();
                break;
            case 2:
                displaystu();
                break;
            case 3:
                findstu();
                break;
            case 4:
                deletestu();
                break;
            case 5:
                modifystu();
                break;
            case 6:
                modifySingleOrMultipleSubjects();
                break;
            case 7:
                printf("再见!\n");
                return 0;
            default:
                printf("无效的选择，请重新输入\n");
        }
    }
    return 0;
}
