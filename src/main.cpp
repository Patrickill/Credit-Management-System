#include <iostream>
#include "../include/menu.h"
#include "../include/link.h"
int main() {
    link link;
    link.getData();
//    std::cout<<"����  ѧ��  �༶  ������ѧ�� רҵ��ѧ�� ѡ�޿�ѧ�� ������ѧ�� ʵ���Կγ�ѧ��"<<std::endl;

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
    std::cout << "�˳��ɹ�!" << std::endl;
    return 0;

}
