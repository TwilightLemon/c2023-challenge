//
// Created by cz241 on 9/28/2023.
//

#include "StoreHelper.h"

vector<string> IdList;
vector<Item> DataList;

void CreateDataFile(){
    //create data file..
    ofstream fs;
    fs.open(path,ios::app);
    if(fs.is_open())fs.close();
    else cout<<"failed to access file."<<endl;
}

vector<string> stringSplit(const string& strIn, char delim) {
    char* str = const_cast<char*>(strIn.c_str());
    string s;
    s.append(1, delim);
    vector<string> elems;
    char* splitted = strtok(str, s.c_str());
    while (splitted != NULL) {
        elems.push_back(string(splitted));
        splitted = strtok(NULL, s.c_str());
    }
    return elems;
}

string DataBuilder(Item item) {
    return item.id+spilt+item.name+spilt+item.count;
}
string ItemString(Item item){
    return "����:"+item.id+" ����:"+item.name+" ����:"+item.count+"\r\n";
}
bool isIDExist(string id){
    for(string i :IdList)
        if(i==id)return true;
    return false;
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
            vector data=stringSplit(str,spilt);
            IdList.push_back(data[0]);
            DataList.push_back(Item{data[0],data[1],data[2]});
        }
        fs.close();
    }
}

void ShowList(){
    for(Item i:DataList)
        cout<<ItemString(i)<<endl;
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
        fs<<DataBuilder(Item{id,name,count})<<"\r\n";
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
    Item result;
    if(fs.is_open()){
        string str;
        while(getline(fs,str)){
            vector data=stringSplit(str,'|');
            Item dt{data[0],data[1],data[2]};
            if(data[0]!=id)
                filedata+= DataBuilder(dt)+"\r\n";
            else {
                found=true;
                result=dt;
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