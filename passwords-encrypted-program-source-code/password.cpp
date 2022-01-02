#include "password.h"
#include <iostream>
Password::Password()
{

}

std::string Password::getPassword()
{
    return this->password;
}

void Password::setPassword(std::string password)
{
    this->password = password;
}

bool Password::existenceOfFile()
{
    std::ifstream file("contr.dat",std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.close();
        return true;
    }
    return false;
}


void Password::savePassword()
{
    std::ofstream file("contr.dat",std::ios::binary | std::ios::out);
    if(file.is_open()){
        int aux = stoi(this->password) + 69;
        file.write((char*)&aux,sizeof(int));
    }
    file.close();
}

void Password::recoveryPassword()
{
    std::ifstream file("contr.dat",std::ios::binary | std::ios::in);
    if(file.is_open()){
        int aux;
        file.read((char*)&aux,sizeof(int));
        this->password = std::to_string(aux - 69);
    }
    file.close();
}

