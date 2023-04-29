#include "student.h"
#include <iostream>
#include <fstream>


struct Node{
    public:
      Node* next;
      Node* prev;
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
           head->prev = nullptr;
           tail = head;
           count = 0;
      }

      void getData();

      student & findStudent(std::string id) const;

      bool showByClass(int cla);

      void writeToFile() const;

      bool deleteStudent(std::string key);

      void addStudent();

      void addStudent(std::string name_, std::string num_, int cla_, double base_, double major_, double electives_,
                    double humanity_, double partical_);

      void toArray(student *students) const;

      void sortStudent(student * student,int l,int r,int choice,int order);

      static void  swap_(student & pre ,student & next);
};// FIXME: 不知道这里的节点用不用引用会不会出bug