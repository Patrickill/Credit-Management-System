#include <iostream>
#include "../include/menu.h"
#include "../include/link.h"
int main() {
    link link;
    link.getData();
//    std::cout<<"姓名  学号  班级  基础课学分 专业课学分 选修课学分 人文类学分 实践性课程学分"<<std::endl;

//    while(nowNode->next != nullptr) {
//        nowNode->stu.showStudentScore();
//        nowNode = nowNode->next;
//    }
    menu menu;
    menu.display_welcome();
    int op;
    while(std::cin>>op && op!=0) {
        if(op == 1){
           menu.display_consult();
        }
        else if(op == 2){
            menu.display_change();
        }
        else if(op == 3){
            menu.display_sort();
        }
    }
    std::cout << "退出成功!" << std::endl;
    return 0;

}
