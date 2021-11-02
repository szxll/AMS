#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define MAX 1000
//����ṹ

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
//��װ��ʾ�˵�����
void showmenu()
{
    cout << "*****  ��ѡ���ܣ�             *****" << endl;
    cout << "*****      1.�����ϵ��         *****" << endl;
    cout << "*****      2.��ʾ��ϵ��         *****" << endl;
    cout << "*****      3.������ϵ��         *****" << endl;
    cout << "*****      4.�޸���ϵ��         *****" << endl;
    cout << "*****      5.ɾ����ϵ��         *****" << endl;
    cout << "*****      6.�����ϵ��         *****" << endl;
    cout << "*****      7.�˳���ϵͳ         *****" << endl;
}
//��װ�����ϵ�˺���
void addperson(struct addressbook *str)
{
    cout << "������������" << endl;
    string name;
    cin >> name;
    str->oneperson[str->size_A].name = name;
    cout << "���������䣺" << endl;
    int age;
    cin >> age;
    str->oneperson[str->size_A].age = age;
    cout << "������绰��" << endl;
    int call;
    cin >> call;
    str->oneperson[str->size_A].call = call;
    cout << "��ӳɹ���" << endl;
    str->size_A++;
    system("pause");
    system("cls");
}
//��װ��ʾ��ϵ�˺���
void showperson(struct addressbook *str)
{
    cout << "������ϵ��������" << str->size_A << endl;
    for (int i = 0; i <= str->size_A - 1; i++)
    {
        cout << "������" << str->oneperson[i].name << "\t";
        cout << "���䣺" << str->oneperson[i].age << "\t";
        cout << "�绰:" << str->oneperson[i].call << "\t" << endl;
    }
    system("pause");
    system("cls");
}
//��װ������ϵ�˺���
void schperson(struct addressbook *str)
{
    cout << "������Ҫ���ҵ���ϵ��������" << endl;
    string name;
    int index = 0;
    cin >> name;
    for (int i = 0; i <= str->size_A - 1; i++)
    {
        if (name == str->oneperson[i].name)
        {
            cout << "������" << str->oneperson[i].name << "\t";
            cout << "���䣺" << str->oneperson[i].age << "\t";
            cout << "�绰:" << str->oneperson[i].call << "\t" << endl;
            index++;
        }
    }
    if (index == 0)
    {
        cout << "���޴��ˣ�" << endl;
    }
    system("pause");
    system("cls");
}
//��װ�޸���ϵ�˺���
void resetperson(struct addressbook *str)
{
    cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
    string name;
    int index = 0;
    cin >> name;
    for (int i = 0; i <= str->size_A - 1; i++)
    {
        if (name == str->oneperson[i].name)
        {
            cout << "�������޸ĺ����Ϣ��" << endl;
            cout << "������" << endl;
            string name;
            cin >> name;
            str->oneperson[i].name = name;
            cout << "���䣺" << endl;
            int age;
            cin >> age;
            str->oneperson[i].age = age;
            cout << "�绰��" << endl;
            int call;
            cin >> call;
            str->oneperson[i].call = call;
            cout << "�޸���ɣ�" << endl;
            index++;
        }
    }
    if (index == 0)
        cout << "���޴���!" << endl;
    system("pause");
    system("cls");
}
//��װɾ����ϵ�˺���
void delperson(struct addressbook *str)
{
    cout << "������Ҫɾ������ϵ��������" << endl;
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
                cout << "ɾ����ɣ�" << endl;
            }
            str->size_A--;
        }
    }
    if (index == 0)
        cout << "���޴���!" << endl;
    system("pause");
    system("cls");
}
//��װ�����ϵ�˺���
void resetsystem(struct addressbook *str)
{
    cout << "��ĹǰͨѶ¼���� " << str->size_A << " λ���ѣ���ȷ��Ҫ���ͨѶ¼��" << endl;
    cout << "������ Y/N ������" << endl;
    string sign;
    cin >> sign;
    if (sign == "Y")
    {
        str->size_A = 0;
        cout << "������ϵ����ɾ����" << endl;
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
            cout << "��ӭ�´�ʹ�ã�" << endl;
            goto exit;
            break;
        }
    }
exit:
    system("pause");
    return 0;
}