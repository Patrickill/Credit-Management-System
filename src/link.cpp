#include "../include/link.h"
std::ofstream ofs;
void link::getData() {
    std::ifstream infile;
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
        newNode->prev = tail;
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
        count++;
    }
}

student & link::findStudent(std::string key) const {
    Node* nowNode = head->next;
    while(nowNode->next != nullptr) {
        if (nowNode->stu.getId() == key || nowNode->next->stu.name == key) {
            return nowNode->stu;
        }
        nowNode = nowNode->next;
    }
        return nowNode->stu;

}

bool link::showByClass(int cla) {
    Node* nowNode = head->next;
    int ct = 0;
    while(nowNode->next != nullptr) {
        if(nowNode->stu.cla == cla) {
            nowNode->stu.showStudentScore();
            ct++;
        }
        nowNode = nowNode->next;
    }
    if(nowNode->stu.cla == cla) {
        nowNode->stu.showStudentScore();
        ct++;
    }
    if(!ct)
         return false;
    else
        return true;
}


bool link::deleteStudent(std::string key){
    Node* nowNode = head->next;
    while(nowNode->next != nullptr){
        if(nowNode->stu.name == key || nowNode->stu.num ==key){
            nowNode->prev->next = nowNode->next;
            return true;
        }
        nowNode = nowNode->next;
    }
    if(nowNode->stu.name == key || nowNode->stu.num ==key){
        nowNode->prev->next = nowNode->next;
        return true;
    }
    return false;
}

void link::writeToFile() const {
    ofs.open("../data/student.text", std::ios::trunc);
    Node *nowNode = head->next;
    while (nowNode->next != nullptr) {
        ofs << nowNode->stu.name << " " << nowNode->stu.num << " " << nowNode->stu.cla << " " << nowNode->stu.base<<" "
            << nowNode->stu.major << " " << nowNode->stu.electives << " " << nowNode->stu.humanity << " "
            << nowNode->stu.partical << std::endl;
        nowNode = nowNode->next;
    }
    ofs << nowNode->stu.name << " " << nowNode->stu.num << " " << nowNode->stu.cla << " " << nowNode->stu.base<<" "
        << nowNode->stu.major << " " << nowNode->stu.electives << " " << nowNode->stu.humanity << " "
        << nowNode->stu.partical << std::endl;
    ofs<<"0";
}

void link::addStudent(std::string name_, std::string num_,int cla_,double base_,double major_,double electives_,double humanity_,double partical_) {
    newNode = new Node;
    student newStu;
    newStu.setStudent(name_, num_, cla_, base_, major_, electives_, humanity_, partical_);
    newNode->stu = newStu;
    newNode->prev = tail;
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}