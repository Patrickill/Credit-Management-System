#include <iostream>
#include "../include/menu.h"
#include "../include/link.h"

int main() {
    link link;
    link.getData();
    menu menu;
    int op;
    while( menu.display_welcome() && std::cin>>op && op!=0) {

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
                       std::cout<<"无该学号学生的信息"<<std::endl;
                   }
               }
               else if (op == 2){
                   int cla;
                   std::cin >> cla;
                   if (!link.showByClass(cla)) std::cout<<"无这个班级的信息"<<std::endl;
               }
           }
        }
        else if(op == 2){

            while(menu.display_change() && std::cin>>op && op!=0) {
                if(op == 1){
                      std::string name,num;
                      int cla;
                      double base,major,electives,humanity,partical;
                      std::cin>>name>>num>>cla>>base>>major>>electives>>humanity>>partical;
                      link.addStudent(name,num,cla,base,major,electives,humanity,partical);
                      std::cout<<"添加成功!"<<std::endl;
                }
                else if (op == 2) {
                    std::string key;
                    std::cin >> key;
                    student& findStu = link.findStudent(key);
                    if(findStu.getNum() == key || findStu.getName() == key ) {
                        findStu.showStudentScore();
                        std::cout << "请确认是否要删除该学生: 正确输入1 错误输入2" << std::endl;
                        std::cin >> op;
                        if (op == 1) {
                            if (link.deleteStudent(key))
                                std::cout << "删除成功!" << std::endl;
                            else
                                std::cout << "删除失败!" << std::endl;
                        } else if (op == 2) {
                            std::cout << "请重新操作!" << std::endl;
                        }
                    }
                    else
                        std::cout << "删除失败:没有该学生" << std::endl;
                }

                else if (op == 3){
                    std::string key;
                    std::cin >>key;
                    student& findStu = link.findStudent(key);
                    if(findStu.getNum() == key || findStu.getName() == key ){
                        findStu.showStudentScore();
                        std::cout<<"请确认是否要修改该学生的成绩: 正确输入1 错误输入2"<<std::endl;
                        std::cin>>op;
                        if(op == 1){
                            std::cout<<"请按顺序输入基础课学分 专业课学分 选修课学分 人文类学分 实践性课程学分"<<std::endl;
                            double base,major,electives,humanity,partical;
                            std::cin>>base>>major>>electives>>humanity>>partical;
                            findStu.setStudent(findStu.getName(),findStu.getNum(),findStu.getCla(),base,major,electives,humanity,partical);
                            std::cout<<"修改成功!"<<std::endl;
                        }
                        else if(op == 2){
                            std::cout<<"请重新操作!"<<std::endl;
                        }
                    }
                    else {
                        std::cout<<"未找到该学生!"<<std::endl;
                    }
                }
            }
        }
        else if(op == 3){
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
    std::cout << "退出成功!" << std::endl;
    // TODO: 难点这里交换两个学生的方法,函数中a和b的地址交换并不会影响外部a和b的值
    // TODO: 查找方法过于原始
    return 0;

}
