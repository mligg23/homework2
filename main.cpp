#include <iostream>
#include <string.h>

using namespace std;

class Identity {
public:
    Identity(void) {                             //���캯��
        cout << "constructor" << endl;
    }
    ~Identity(void) {                            //��������
        cout << "distructor" << endl;
    }
    Identity(const Identity& source) {           //�������캯��
        strcpy_s(number_, source.number_);
        strcpy_s(name_, source.name_);
        cout << "copy constructor" << endl;
    }
    char* getnumber(void) {                     //���֤�Ŷ�ȡ����
        return number_;
    }
    char* getname(void) {                       //������ȡ����
        return name_;
    }
    void setnumber(char* m) {                   //���֤�����ú���
        strcpy_s(number_, m);
    }
    void setname(char* m) {                    //�������ú���
        strcpy_s(name_, m);
    }
protected:
    char number_[19] = "000000000000000000";       //���ǵ����֤�ſ��ܺ�����ĸ���˸���char��
    char name_[33] = "name";  //����
};

class student {
protected:
    Identity id_;
    string school_ = "void";
public:
    student(void) {  //���캯��
        cout << "constructor" << endl;
    }
    ~student(void) {  //��������
        cout << "distructor" << endl;
    }
    student(const student& source) { //�������캯��
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
    cout << "������������" << endl;
    cin >> temp;
    a.setname(temp);                         //ʹ��setname������������
    cout << "���������֤�ţ�"<<endl;
    cin >> temp;
    a.setnumber(temp);         //ʹ��setnumber�����������֤��
    cout << "���ɿ�����b" << endl;
    Identity b = a;          //ͨ����ֵ���ÿ������캯��
    cout << "����a��" << endl << "����:" << a.getname() << endl << "���֤�ţ�" << a.getnumber() << endl;
    cout << "����b��" << endl << "����:" << b.getname() << endl << "���֤�ţ�" << b.getnumber() << endl;
    cout << "����ѧ����Ϣ��stu1:" << endl;
    student stu1;
    cout << "ʹ��a�е���Ϣ����stu1:" << endl;
    stu1.setstuname(a.getname());
    stu1.setstunumber(a.getnumber());
    cout << "ѧУ���ƣ�";
    string schtep;
    cin >> schtep;
    stu1.setschool(schtep);
    student stu2 = stu1;
    student stu3 = MakeStudent(stu1.getstunumber(), stu1.getstuname(), stu1.getschool());//ͨ���Ӻ���MakeStudent����ѧ����Ϣ��stu3(������stu1�е���)
    cout << "����stu1��" << endl << "����:" << stu1.getstuname() << endl << "���֤�ţ�" << stu1.getstunumber() << endl << "У��:" << stu1.getschool() << endl;
    cout << "����stu2��" << endl << "����:" << stu2.getstuname() << endl << "���֤�ţ�" << stu2.getstunumber() << endl << "У��:" << stu2.getschool() << endl;
    cout << "����stu3��" << endl << "����:" << stu3.getstuname() << endl << "���֤�ţ�" << stu3.getstunumber() << endl << "У��:" << stu3.getschool() << endl;
    cout << "�ཫ����:" << endl;

    return 0;
}

student MakeStudent(char* number, char* name, string school) {
    student* temp = new student;
    temp->setstunumber(number);
    temp->setstuname(name);
    temp->setschool(school);
    return *temp;
}