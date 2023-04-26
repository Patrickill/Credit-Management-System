#ifndef PROJECT_ABS_MENU_H
#define PROJECT_ABS_MENU_H

#include<iostream>

class menu{
public:
    void display_welcome(){
        std::cout<<"---------------------------欢迎使用学分管理系统----------------------------------"<<std::endl;
        std::cout<<"输入不同数字进入不同模式:"<<std::endl;
        std::cout<<"0:退出系统"<<std::endl;
        std::cout<<"1:查询模式"<<std::endl;
        std::cout<<"2:编辑模式"<<std::endl;
        std::cout<<"3:排序模式"<<std::endl;
        std::cout<<">";
    }

    void display_consult(){
        std::cout<<"--------------------------------------查询模式---------------------------------"<<std::endl;
        std::cout<<"0:退出模式"<<std::endl;
        std::cout<<"1:按学号查询学分完成情况\"1 学号\"如( 1 114514)"<<std::endl;
        std::cout<<"2:按班级输出该班级全部学生的完成情况\"2 班级\"如(2 5)"<<std::endl;
        std::cout<<">";
    }

    void display_change(){
        std::cout<<"--------------------------------------编辑模式---------------------------------"<<std::endl;
        std::cout<<"0:退出系统"<<std::endl;
        std::cout<<"1:输入如\"张三\"??????????????????(??: 114514 10 10 10 10 10)"<<std::endl;
//        std::cout<<"????\"2 ??\"??????????????????????(??: 2 5)"<<std::endl;
        std::cout<<">";
    }

    void display_sort(){
        std::cout<<"--------------------------------------??????---------------------------------"<<std::endl;
        std::cout<<"0:???????"<<std::endl;
        std::cout<<"????1-5,??????????? ???? ???? ??????γ? ?????γ????????????????"<<std::endl;
        std::cout<<">";
    }

};

#endif