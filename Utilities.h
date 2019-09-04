//
// Created by gianluca on 02/09/19.
//
#define RUNNING_LINUX//only linux

#include <iostream>
#include <string>
#include <algorithm>

namespace Utils{

#ifdef RUNNING_LINUX
#include <unistd.h>
    inline std::string GetWorkingDirectory(){
       char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr){
        return std::string(cwd) + std::string("/");
    }
        return "";
    }
#endif //MELONE_UTILITIES_H

}