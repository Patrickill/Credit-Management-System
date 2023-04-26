#include "student.h"
#include <iostream>
#include <fstream>
std::ifstream infile;

struct Node{
    public:
      Node* next;
      student stu;
};

class link{
    public:
      Node *head,*tail,*newNode;
      int count = 0;
      link(){
           newNode = new Node;
           head = new Node;
           head->next = nullptr;
           tail = head;
           count = 0;
           std::cout<<"build"<<std::endl;
      }

      void getData(){
          infile.open("../data/student.text");
          std::string name;
          while(infile>>name && name!= "0"){
              std::string num;
              infile >> num;
              double base,major,electives,humanity,partical;
              int cla;
              infile>>cla>>base>>major>>electives>>humanity>>partical;
              student newStudent;
              newStudent.setStudent(name,num,cla,base,major,electives,humanity,partical);
              newNode = new Node;
              newNode->stu = newStudent;
              newNode->next = tail->next;
              tail->next = newNode;
              count++;
          }
      }
};// FIXME: 不知道这里的节点用不用引用会不会出bug