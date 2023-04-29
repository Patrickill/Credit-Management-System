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
            count--;
            return true;
        }
        nowNode = nowNode->next;
    }
    if(nowNode->stu.name == key || nowNode->stu.num ==key){
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
        double x = student[(l+r)/2].base;
        while(i < j) {
            do i++;while(student[i].base*order < x*order);
            do j--;while(student[j].base*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }
    else if(choice == 2){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].major;
        while(i < j) {
            do i++;while(student[i].major*order < x*order );
            do j--;while(student[j].major*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }
    else if(choice == 3){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].electives;
        while(i < j) {
            do i++;while(student[i].electives*order < x*order );
            do j--;while(student[j].electives*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }
    else if(choice == 4){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].humanity;
        while(i < j) {
            do i++;while(student[i].humanity*order < x*order );
            do j--;while(student[j].humanity*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }
    else if (choice == 5){
        if(l >= r) return;
        int i = l - 1,j = r + 1;
        double x = student[(l+r)/2].partical;
        while(i < j) {
            do i++;while(student[i].partical*order < x*order );
            do j--;while(student[j].partical*order > x*order );
            if(i<j) swap_(student[i],student[j]);
        }
        sortStudent(student,l,j,choice,order), sortStudent(student,j+1,r,choice,order);
        return ;
    }

}

void link::swap_(student & pre,student & next){
    student tmp = pre;
    pre = next;
    next = tmp;
}