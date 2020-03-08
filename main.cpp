#include <iostream>
#include <string.h>

using namespace std;

class Identity {
public:
    Identity(void) {                             //构造函数
        cout << "constructor" << endl;
    }
    ~Identity(void) {                            //析构函数
        cout << "distructor" << endl;
    }
    Identity(const Identity& source) {           //拷贝构造函数
        strcpy_s(number_, source.number_);
        strcpy_s(name_, source.name_);
        cout << "copy constructor" << endl;
    }
    char* getnumber(void) {                     //身份证号读取函数
        return number_;
    }
    char* getname(void) {                       //姓名读取函数
        return name_;
    }
    void setnumber(char* m) {                   //身份证号设置函数
        strcpy_s(number_, m);
    }
    void setname(char* m) {                    //姓名设置函数
        strcpy_s(name_, m);
    }
protected:
    char number_[19] = "000000000000000000";       //考虑到身份证号可能含有字母，顾改用char型
    char name_[33] = "name";  //姓名
};

class student {
protected:
    Identity id_;
    string school_ = "void";
public:
    student(void) {  //构造函数
        cout << "constructor" << endl;
    }
    ~student(void) {  //析构函数
        cout << "distructor" << endl;
    }
    student(const student& source) { //拷贝构造函数
        id_ = source.id_;
        school_ = source.school_;
        cout << "copy constructor" << endl;
    }
    char* getstunumber(void) {
        return id_.getnumber();
    }
    char* getstuname(void) {
        return id_.getname();
    }
    string getschool(void) {
        return school_;
    }
    void setstunumber(char* n) {
        id_.setnumber(n);
        return;
    }
    void setstuname(char* n) {
        id_.setname(n);
        return;
    }
    void setschool(string sch) {
        school_ = sch;
        return;
    }
};
student MakeStudent(char*, char*, string);

int main() {
    Identity a;
    char temp[33];
    cout << "请输入姓名：" << endl;
    cin >> temp;
    a.setname(temp);                         //使用setname函数读入姓名
    cout << "请输入身份证号："<<endl;
    cin >> temp;
    a.setnumber(temp);         //使用setnumber函数读入身份证号
    cout << "生成拷贝类b" << endl;
    Identity b = a;          //通过赋值调用拷贝构造函数
    cout << "【类a】" << endl << "姓名:" << a.getname() << endl << "身份证号：" << a.getnumber() << endl;
    cout << "【类b】" << endl << "姓名:" << b.getname() << endl << "身份证号：" << b.getnumber() << endl;
    cout << "构造学生信息类stu1:" << endl;
    student stu1;
    cout << "使用a中的信息设置stu1:" << endl;
    stu1.setstuname(a.getname());
    stu1.setstunumber(a.getnumber());
    cout << "学校名称：";
    string schtep;
    cin >> schtep;
    stu1.setschool(schtep);
    student stu2 = stu1;
    student stu3 = MakeStudent(stu1.getstunumber(), stu1.getstuname(), stu1.getschool());//通过子函数MakeStudent创建学生信息类stu3(参数从stu1中调用)
    cout << "【类stu1】" << endl << "姓名:" << stu1.getstuname() << endl << "身份证号：" << stu1.getstunumber() << endl << "校名:" << stu1.getschool() << endl;
    cout << "【类stu2】" << endl << "姓名:" << stu2.getstuname() << endl << "身份证号：" << stu2.getstunumber() << endl << "校名:" << stu2.getschool() << endl;
    cout << "【类stu3】" << endl << "姓名:" << stu3.getstuname() << endl << "身份证号：" << stu3.getstunumber() << endl << "校名:" << stu3.getschool() << endl;
    cout << "类将析构:" << endl;

    return 0;
}

student MakeStudent(char* number, char* name, string school) {
    student* temp = new student;
    temp->setstunumber(number);
    temp->setstuname(name);
    temp->setschool(school);
    return *temp;
}