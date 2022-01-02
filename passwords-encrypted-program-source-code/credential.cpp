#include "credential.h"


Credential::Credential()
{

}

Credential::Credential(std::string u, std::string p)
{
    this->user = u;
    this->password = p;
}

std::string Credential::getUser()
{
    return this->user;
}

std::string Credential::getPassword()
{
    return this->password;
}
