#include "StoreHelper.h"
/*
 * �������c++��ֱ����json/xml/ini�ģ����ǵ��ִ�һ��������
 * �Ͳ��ٱ���������Χ��(��Ҫ��C# �ַ��ӵ�����...)
 * ����ֱ�Ӵֱ��ض�д�ļ� �ܴ�һ����һ��..
 *
 * */

const char spilt='|';
const string path="data.tw";

int main() {
    CreateDataFile();

    for(;;) {
    IndexList();
    string text = "1.��ʾ����б�\r\n"
                  "2.���\r\n"
                  "3.����\r\n"
                  "4.�˳�����\r\n";
    cout << text << endl;
    int ord;
    scanf("%d", &ord);

    switch (ord) {
        case 1:
            ShowList();
            break;
        case 2:
            WriteLine();
            break;
        case 3:
            PopOut();
            break;
        case 4:
            exit(0);
    }
    system("pause");
    system("cls");
}
    return 0;
}