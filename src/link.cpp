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
        if (nowNode->stu.getId() == key || nowNode->stu.getName() == key) {
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
        if(nowNode->stu.getCla() == cla) {
            nowNode->stu.showStudentScore();
            ct++;
        }
        nowNode = nowNode->next;
    }
    if(nowNode->stu.getCla() == cla) {
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
        if(nowNode->stu.getName() == key || nowNode->stu.getName() ==key){
            nowNode->prev->next = nowNode->next;
            count--;
            return true;
        }
        nowNode = nowNode->next;
    }
    if(nowNode->stu.getName() == key || nowNode->stu.getName() ==key){
        nowNode->prev->next = nowNode->next;
        count--;
        return true;
    }
    return false;
}

void link::writeToFile() const {
    ofs.open("../data/student.text", std::ios::trunc);
    Node *nowNode = head->next;
    while (nowNode->next != nullptr) {
        ofs << nowNode->stu.getName() << " " << nowNode->stu.getNum() << " " << nowNode->stu.getCla() << " " << nowNode->stu.getBase()<<" "
            << nowNode->stu.getMajor() << " " << nowNode->stu.getElectives() << " " << nowNode->stu.getHumanity() << " "
            << nowNode->stu.getPartical() << std::endl;
        nowNode = nowNode->next;
    }
    ofs << nowNode->stu.getName() << " " << nowNode->stu.getNum() << " " << nowNode->stu.getCla() << " " << nowNode->stu.getBase()<<" "
        << nowNode->stu.getMajor() << " " << nowNode->stu.getElectives() << " " << nowNode->stu.getHumanity() << " "
        << nowNode->stu.getPartical() << std::endl;
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
    count++;
}

void link::toArray(student* students) const{
     Node* newNode = head->next;
     int len = 0;
     while (newNode->next!= nullptr) {
        students[len ++] = newNode->stu;
        newNode = newNode->next;
    }
    students[len ++] = newNode->stu;
}

void link::sortStudent(student *student, int l, int r, int choice,int order) {
    if(choice == 1){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].getBase();
        while(i < j) {
            do i++;while(student[i].getBase()*order < x*order);
            do j--;while(student[j].getBase()*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }
    else if(choice == 2){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].getMajor();
        while(i < j) {
            do i++;while(student[i].getMajor()*order < x*order );
            do j--;while(student[j].getMajor()*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }
    else if(choice == 3){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].getElectives();
        while(i < j) {
            do i++;while(student[i].getElectives()*order < x*order );
            do j--;while(student[j].getElectives()*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }
    else if(choice == 4){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].getHumanity();
        while(i < j) {
            do i++;while(student[i].getHumanity()*order < x*order );
            do j--;while(student[j].getHumanity()*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }
    else if (choice == 5){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].getPartical();
        while(i < j) {
            do i++;while(student[i].getPartical()*order < x*order );
            do j--;while(student[j].getPartical()*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }

}

bool link::isStudent(std::string account){
    Node *nowNode = head->next;
    while (nowNode->next != nullptr) {
        if(nowNode->stu.getNum() == account)
            return true;
        nowNode = nowNode->next;
    }
    if(nowNode->stu.getNum() == account)
        return true;
    return false;
}

void link::swap_(student & pre,student & next){
    student tmp = pre;
    pre = next;
    next = tmp;
}