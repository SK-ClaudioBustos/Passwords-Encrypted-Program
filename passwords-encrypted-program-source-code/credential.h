#ifndef CREDENTIAL_H
#define CREDENTIAL_H
#include <iostream>

class Credential
{
private:
    std::string user;
    std::string password;
public:
    Credential();
    Credential(std::string u, std::string p);
    std::string getUser();
    std::string getPassword();
};

#endif // CREDENTIAL_H
