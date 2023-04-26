#include <string>
class student{
   public:
     void setStudent(std::string name_, std::string num_,int cla_,double base_,double major_,double electives_,double humanity_,double partical_){
         name = name_;
         num = num_;
         cla = cla_;
         base = base_;
         major = major_;
         electives = electives_;
         humanity = humanity_;
         partical = partical_;
     };

     void showStudentScore(){
         std::cout<<name<<" "<<num<<" "<<cla<<" "<<base<<" "<<major<<" "<<electives<<" "<<humanity<<" "<<partical<<" "<<std::endl;
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