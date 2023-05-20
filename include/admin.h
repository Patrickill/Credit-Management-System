//
// Created by 86137 on 2023/5/20.
//

#ifndef TEST_ADMIN_H
#define TEST_ADMIN_H
#include "user.h"
#include <fstream>
class admin:public user{
  public:
    void init(){
        std::ifstream input;
        input.open("../data/admin.text");
        input >> account >> pwd;
    }
    std::string getAccount(){return account;}
    std::string getPwd(){return pwd;}
};
#endif //TEST_ADMIN_H
