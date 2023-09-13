#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
/*
 * �������c++��ֱ����json/xml/ini�ģ����ǵ��ִ�һ��������
 * �Ͳ��ٱ���������Χ��(��Ҫ��C# �ַ��ӵ�����...)
 * ����ֱ�Ӵֱ��ض�д�ļ� �ܴ�һ����һ��..
 *
 * */
vector<string> IdList;//index
vector<string> DataList;//data
const char spilt='|';
string DataBuilder(string id,string name,string count) {
    return id+spilt+name+spilt+count;
}
string ItemString(vector<string> result){
    return "����:"+result[0]+" ����:"+result[1]+" ����:"+result[2]+"\r\n";
}
bool isIDExist(string id){
    for(int i=0;i<IdList.size();i++){
        if(IdList[i]==id)return true;
    }
    return false;
}

string path="data.tw";
vector<string> stringSplit(const std::string& strIn, char delim) {
    char* str = const_cast<char*>(strIn.c_str());
    string s;
    s.append(1, delim);
    vector<string> elems;
    char* splitted = strtok(str, s.c_str());
    while (splitted != NULL) {
        elems.push_back(std::string(splitted));
        splitted = strtok(NULL, s.c_str());
    }
    return elems;
}

void IndexList(){
    DataList.clear();
    IdList.clear();
    fstream fs;
    fs.open(path,ios::in);
    if(fs.is_open()){
        string str;
        while(getline(fs,str)){
            //ִ��strtok�Ὣspilt->\0..
            DataList.push_back(str);
            vector data=stringSplit(str,spilt);
            IdList.push_back(data[0]);
        }
        fs.close();
    }
}
void ShowList(){
    for(int i=0;i<DataList.size();i++)
        cout<<ItemString(stringSplit(DataList[i],spilt))<<endl;
}
void WriteLine(){
    cout<<"�������:"<<endl;
    string id;
    cin>>id;
    if(isIDExist(id)){
        cout<<"This id has existed!"<<endl;
        return;
    }
    cout<<"��������:"<<endl;
    string name;
    cin>>name;
    cout<<"����:"<<endl;
    string count;
    cin>>count;

    fstream fs;
    fs.open(path,ios::app);
    if(fs.is_open()){
        fs<<DataBuilder(id,name,count)<<"\r\n";
        fs.close();
    }
}
//ʹ�ø�д����������emmm..
void PopOut(){
    cout<<"�������:"<<endl;
    string id;
    cin>>id;

    string filedata;
    fstream fs;
    fs.open(path,ios::in);
    bool found=false;
    vector<string> result;
    if(fs.is_open()){
        string str;
        while(getline(fs,str)){
            vector data=stringSplit(str,'|');
            if(data[0]!=id)
                filedata+= DataBuilder(data[0],data[1],data[2])+"\r\n";
            else {
                found=true;
                result=data;
            }
        }
        fs.close();
    }
    if(found) {
        fstream writer;
        writer.open(path, ios::out);
        if (writer.is_open()) {
            writer << filedata;
            writer.close();
        }
        cout<<"�ѳ��⣺ "<<ItemString(result)<<endl;
    }else cout<<"??�Ҳ����˻���..\r\n"<<endl;
}

int main() {
    //create data file..
    ofstream fs;
    fs.open(path,ios::app);
    if(fs.is_open())fs.close();
    else cout<<"failed to access file."<<endl;

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