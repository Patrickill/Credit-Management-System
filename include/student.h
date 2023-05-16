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
         std::cout<<"姓名  学号  班级  基础课学分 专业课学分 选修课学分 人文类学分 实践性课程学分"<<std::endl;
         std::cout<<name<<" "<<num<<"    "<<cla<<"        "<<base<<"           "<<major<<"         "<<electives<<"          "<<humanity<<"         "<<partical<<" "<<std::endl;
     }
     std::string getName() const{return name;};
     std::string getNum() const{return num;};
     int getCla() const{return cla;};
     double getBase() const{return base;};
     double getMajor() const{return major;}
     double getElectives() const{return electives;}
     double getHumanity() const{return humanity;}
     double getPartical() const{return partical;}
     std::string getId() const{
         return num;
     }
   private:
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