#ifndef PROJECT_ABS_MENU_H
#define PROJECT_ABS_MENU_H

#include<iostream>

class menu{
public:
    void display_welcome(){
        std::cout<<"---------------------------��ӭʹ��ѧ�ֹ���ϵͳ----------------------------------"<<std::endl;
        std::cout<<"���벻ͬ���ֽ��벻ͬģʽ:"<<std::endl;
        std::cout<<"0:�˳�ϵͳ"<<std::endl;
        std::cout<<"1:��ѯģʽ"<<std::endl;
        std::cout<<"2:�༭ģʽ"<<std::endl;
        std::cout<<"3:����ģʽ"<<std::endl;
        std::cout<<">";
    }

    void display_consult(){
        std::cout<<"--------------------------------------��ѯģʽ---------------------------------"<<std::endl;
        std::cout<<"0:�˳�ģʽ"<<std::endl;
        std::cout<<"1:��ѧ�Ų�ѯѧ��������\"1 ѧ��\"��( 1 114514)"<<std::endl;
        std::cout<<"2:���༶����ð༶ȫ��ѧ����������\"2 �༶\"��(2 5)"<<std::endl;
        std::cout<<">";
    }

    void display_change(){
        std::cout<<"--------------------------------------�༭ģʽ---------------------------------"<<std::endl;
        std::cout<<"0:�˳�ϵͳ"<<std::endl;
        std::cout<<"1:������\"����\"??????????????????(??: 114514 10 10 10 10 10)"<<std::endl;
//        std::cout<<"????\"2 ??\"??????????????????????(??: 2 5)"<<std::endl;
        std::cout<<">";
    }

    void display_sort(){
        std::cout<<"--------------------------------------??????---------------------------------"<<std::endl;
        std::cout<<"0:???????"<<std::endl;
        std::cout<<"????1-5,??????????? ???? ???? ??????��? ?????��????????????????"<<std::endl;
        std::cout<<">";
    }

};

#endif