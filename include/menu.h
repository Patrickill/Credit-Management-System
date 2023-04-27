
#include<iostream>

class menu{
public:
     bool display_welcome(){
        std::cout<<"---------------------------欢迎使用学分管理系统----------------------------------"<<std::endl;
        std::cout<<"输入不同数字进入不同模式:"<<std::endl;
        std::cout<<"0:退出系统"<<std::endl;
        std::cout<<"1:查询模式"<<std::endl;
        std::cout<<"2:编辑模式"<<std::endl;
        std::cout<<"3:排序模式"<<std::endl;
        std::cout<<">";
        return true;
    }

    void display_consult(){
        std::cout<<"--------------------------------------查询模式---------------------------------"<<std::endl;
        std::cout<<"0:退出模式"<<std::endl;
        std::cout<<"1:按学号查询学分完成情况\"1 学号\"如( 1 114514)"<<std::endl;
        std::cout<<"2:按班级输出该班级全部学生的完成情况\"2 班级\"如(2 5)"<<std::endl;
        std::cout<<">";
    }

    bool display_change(){
        std::cout<<"--------------------------------------编辑模式---------------------------------"<<std::endl;
        std::cout<<"0:退出模式"<<std::endl;
        std::cout<<"1:添加学生 输入(1 姓名 学号 班级 基础课学分 专业课学分 选修课学分 人文类学分 实践性课程学分)添加学生"<<std::endl;
        std::cout<<"2:删除学生 输入(2 姓名或者学号)即可删除该学生"<<std::endl;
        std::cout<<"3:修改学生学分 输入(3 姓名或者学号)后确认学生信息后再输入(基础课学分 专业课学分 选修课学分 人文类学分 实践性课程学分)修改学分数据"<<std::endl;
        std::cout<<">";
        return true;
    }

    bool display_sort(){
        std::cout<<"--------------------------------------??????---------------------------------"<<std::endl;
        std::cout<<"0:???????"<<std::endl;
        std::cout<<"????1-5,??????????? ???? ???? ??????γ? ?????γ????????????????"<<std::endl;
        std::cout<<">";
        return true;
    }

};
