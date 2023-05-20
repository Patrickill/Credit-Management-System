#include <iostream>
#include "../include/menu.h"
#include "../include/link.h"
#include "../include/admin.h"
int main() {
    link link;
    menu menu;
    admin admin;
    int op,identity,success=0;
    admin.init();
    link.getData();
    menu.display_begin();
    std::string account,pwd;
    std::cin >> identity;
    while( identity != 1 && identity != 2){
        std::cout << "Υ�����룬����������"<<std::endl;
        std::cin >> identity;
    }
    while (!success){
        std::cout << "�������˺�:" << std::endl;
        std::cin >> account;
        std::cout << "����������" << std::endl;
        std::cin >> pwd;
        if(identity == 1){
            if(link.isStudent(account))
                success = 1;
        }
        else if(identity == 2){
            if(pwd == admin.getPwd() && account == admin.getAccount())
                success = 1;
        }
        if(!success)
            std::cout<<"��½ʧ�ܣ�������˺Ŵ���"<<std::endl;

    }
    std::cout<<"��½�ɹ�!"<<std::endl;
    while(  identity == 1 ? menu.display_welcome_student() : menu.display_welcome_admin() && std::cin>>op && op!=0) {

        if(op == 1){
           menu.display_consult();
           while(std::cin>>op && op!=0) {
               if(op == 1){
                   std::string id;
                   std::cin >> id;
                   student& find = link.findStudent(id);
                   if(find.getId() == id || find.getName() == id){
                       find.showStudentScore();
                   }
                   else {
                       std::cout<<"�޸�ѧ��ѧ������Ϣ"<<std::endl;
                   }
               }
               else if (op == 2){
                   int cla;
                   std::cin >> cla;
                   if (!link.showByClass(cla)) std::cout<<"������༶����Ϣ"<<std::endl;
               }
           }
        }
        else if(op == 3 && identity == 2){

            while(menu.display_change() && std::cin>>op && op!=0) {
                if(op == 1){
                      std::string name,num;
                      int cla;
                      double base,major,electives,humanity,partical;
                      std::cin>>name>>num>>cla>>base>>major>>electives>>humanity>>partical;
                      link.addStudent(name,num,cla,base,major,electives,humanity,partical);
                      std::cout<<"��ӳɹ�!"<<std::endl;
                }
                else if (op == 2) {
                    std::string key;
                    std::cin >> key;
                    student& findStu = link.findStudent(key);
                    if(findStu.getNum() == key || findStu.getName() == key ) {
                        findStu.showStudentScore();
                        std::cout << "��ȷ���Ƿ�Ҫɾ����ѧ��: ��ȷ����1 ��������2" << std::endl;
                        std::cin >> op;
                        if (op == 1) {
                            if (link.deleteStudent(key))
                                std::cout << "ɾ���ɹ�!" << std::endl;
                            else
                                std::cout << "ɾ��ʧ��!" << std::endl;
                        } else if (op == 2) {
                            std::cout << "�����²���!" << std::endl;
                        }
                    }
                    else
                        std::cout << "ɾ��ʧ��:û�и�ѧ��" << std::endl;
                }

                else if (op == 3){
                    std::string key;
                    std::cin >>key;
                    student& findStu = link.findStudent(key);
                    if(findStu.getNum() == key || findStu.getName() == key ){
                        findStu.showStudentScore();
                        std::cout<<"��ȷ���Ƿ�Ҫ�޸ĸ�ѧ���ĳɼ�: ��ȷ����1 ��������2"<<std::endl;
                        std::cin>>op;
                        if(op == 1){
                            std::cout<<"�밴˳�����������ѧ�� רҵ��ѧ�� ѡ�޿�ѧ�� ������ѧ�� ʵ���Կγ�ѧ��"<<std::endl;
                            double base,major,electives,humanity,partical;
                            std::cin>>base>>major>>electives>>humanity>>partical;
                            findStu.setStudent(findStu.getName(),findStu.getNum(),findStu.getCla(),base,major,electives,humanity,partical);
                            std::cout<<"�޸ĳɹ�!"<<std::endl;
                        }
                        else if(op == 2){
                            std::cout<<"�����²���!"<<std::endl;
                        }
                    }
                    else {
                        std::cout<<"δ�ҵ���ѧ��!"<<std::endl;
                    }
                }
            }
        }
        else if(op == 2){
            student* students;
            students = new student[link.count];
            link.toArray(students);
            int len = link.count;
            while(menu.display_sort() && std::cin>>op && op!=0) {
                if(op == 1){
                    std::cin>>op;
                    link.sortStudent(students,0,len-1,op,-1);
                    for(int i=0;i<len;i++){
                        students[i].showStudentScore();
                    }
                }
                else if (op == 2){
                    std::cin>>op;
                    link.sortStudent(students,0,len-1,op,1);
                    for(int i=0;i<len;i++){
                        students[i].showStudentScore();
                    }
                }
            }
        }
    }
    link.writeToFile();
    std::cout << "�˳��ɹ�!" << std::endl;
    // TODO: �ѵ����ｻ������ѧ���ķ���,������a��b�ĵ�ַ����������Ӱ���ⲿa��b��ֵ
    // TODO: ���ҷ�������ԭʼ, ���ĩβ����û���ǣ�����Ϸ���ȷ��
    return 0;

}
