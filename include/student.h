#ifndef PROJECT_ABS_STUDENT_H
#define PROJECT_ABS_STUDENT_H
#include <string>
#include <iostream>
#include <utility>

class student{ ;
   public:
     void setStudent(std::string name_, std::string num_,int cla_,double base_,double major_,double electives_,double humanity_,double partical_){
         name = std::move(name_);
         num = std::move(num_);
         cla = cla_;
         base = base_;
         major = major_;
         electives = electives_;
         humanity = humanity_;
         partical = partical_;
     };

     void showStudentScore() const{
         std::cout<<"����  ѧ��  �༶  ������ѧ�� רҵ��ѧ�� ѡ�޿�ѧ�� ������ѧ�� ʵ���Կγ�ѧ��"<<std::endl;
         std::cout<<name<<" "<<num<<"    "<<cla<<"        "<<base<<"           "<<major<<"         "<<electives<<"          "<<humanity<<"         "<<partical<<" "<<std::endl;
     }



     std::string getId() const{
         return num;
     }
      std::string name;
      std::string num;
      int cla;
      double base;
      double major;
      double electives;
      double humanity;
      double partical;

};

#endif