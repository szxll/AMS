#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define MAX 1000
//定义结构

struct info_A
{
    string name;
    int age;
    int call;
};
struct addressbook
{
    struct info_A oneperson[MAX];
    int size_A;
};
//封装显示菜单函数
void showmenu()
{
    cout << "*****  请选择功能：             *****" << endl;
    cout << "*****      1.添加联系人         *****" << endl;
    cout << "*****      2.显示联系人         *****" << endl;
    cout << "*****      3.查找联系人         *****" << endl;
    cout << "*****      4.修改联系人         *****" << endl;
    cout << "*****      5.删除联系人         *****" << endl;
    cout << "*****      6.清空联系人         *****" << endl;
    cout << "*****      7.退出本系统         *****" << endl;
}
//封装添加联系人函数
void addperson(struct addressbook *str)
{
    cout << "请输入姓名：" << endl;
    string name;
    cin >> name;
    str->oneperson[str->size_A].name = name;
    cout << "请输入年龄：" << endl;
    int age;
    cin >> age;
    str->oneperson[str->size_A].age = age;
    cout << "请输入电话：" << endl;
    int call;
    cin >> call;
    str->oneperson[str->size_A].call = call;
    cout << "添加成功！" << endl;
    str->size_A++;
    system("pause");
    system("cls");
}
//封装显示联系人函数
void showperson(struct addressbook *str)
{
    cout << "现有联系人人数：" << str->size_A << endl;
    for (int i = 0; i <= str->size_A - 1; i++)
    {
        cout << "姓名：" << str->oneperson[i].name << "\t";
        cout << "年龄：" << str->oneperson[i].age << "\t";
        cout << "电话:" << str->oneperson[i].call << "\t" << endl;
    }
    system("pause");
    system("cls");
}
//封装查找联系人函数
void schperson(struct addressbook *str)
{
    cout << "请输入要查找的联系人姓名：" << endl;
    string name;
    int index = 0;
    cin >> name;
    for (int i = 0; i <= str->size_A - 1; i++)
    {
        if (name == str->oneperson[i].name)
        {
            cout << "姓名：" << str->oneperson[i].name << "\t";
            cout << "年龄：" << str->oneperson[i].age << "\t";
            cout << "电话:" << str->oneperson[i].call << "\t" << endl;
            index++;
        }
    }
    if (index == 0)
    {
        cout << "查无此人！" << endl;
    }
    system("pause");
    system("cls");
}
//封装修改联系人函数
void resetperson(struct addressbook *str)
{
    cout << "请输入要修改的联系人姓名：" << endl;
    string name;
    int index = 0;
    cin >> name;
    for (int i = 0; i <= str->size_A - 1; i++)
    {
        if (name == str->oneperson[i].name)
        {
            cout << "请输入修改后的信息：" << endl;
            cout << "姓名：" << endl;
            string name;
            cin >> name;
            str->oneperson[i].name = name;
            cout << "年龄：" << endl;
            int age;
            cin >> age;
            str->oneperson[i].age = age;
            cout << "电话：" << endl;
            int call;
            cin >> call;
            str->oneperson[i].call = call;
            cout << "修改完成！" << endl;
            index++;
        }
    }
    if (index == 0)
        cout << "查无此人!" << endl;
    system("pause");
    system("cls");
}
//封装删除联系人函数
void delperson(struct addressbook *str)
{
    cout << "请输入要删除的联系人姓名：" << endl;
    string name;
    int index = 0;
    cin >> name;
    for (int i = 0; i < str->size_A; i++)
    {
        if (str->oneperson[i].name == name)
        {
            for (; i < (str->size_A - i); i++)
            {
                str->oneperson[i].name = str->oneperson[i + 1].name;
                str->oneperson[i].age = str->oneperson[i + 1].age;
                str->oneperson[i].call = str->oneperson[i + 1].call;
                index++;
                cout << "删除完成！" << endl;
            }
            str->size_A--;
        }
    }
    if (index == 0)
        cout << "查无此人!" << endl;
    system("pause");
    system("cls");
}
//封装清空联系人函数
void resetsystem(struct addressbook *str)
{
    cout << "您墓前通讯录中有 " << str->size_A << " 位好友，您确定要清空通讯录？" << endl;
    cout << "请输入 Y/N 继续：" << endl;
    string sign;
    cin >> sign;
    if (sign == "Y")
    {
        str->size_A = 0;
        cout << "所有联系人已删除！" << endl;
    }
    system("pause");
    system("cls");
}
int main()
{
    int select = 0;
    struct addressbook abs;
    abs.size_A = 0;
    while (1)
    {
        showmenu();
        cin >> select;
        switch (select)
        {
        case 1:
            addperson(&abs);
            break;
        case 2:
            showperson(&abs);
            break;
        case 3:
            schperson(&abs);
            break;
        case 4:
            resetperson(&abs);
            break;
        case 5:
            delperson(&abs);
            break;
        case 6:
            resetsystem(&abs);
            break;
        case 7:
            cout << "欢迎下次使用！" << endl;
            goto exit;
            break;
        }
    }
exit:
    system("pause");
    return 0;
}