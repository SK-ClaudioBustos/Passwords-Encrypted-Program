#ifndef CREDENTIALS_MANAGER_H
#define CREDENTIALS_MANAGER_H
#include <map>
#include <credential.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string.h>

struct data_credential{
    char origin[100];
    char user[100];
    char password[100];
};

class Credentials_Manager
{
private:
    std::map<std::string,Credential> credentials;
public:
    Credentials_Manager();
    void setCredential(std::pair<std::string, Credential> newP);
    Credential getCredential(std::string origin);
    bool credentialExistence(std::string origin);
    std::string encrypt(std::string word);
    std::string decrypt(std::string word);
    void saveCredentials();
    void recoveryOfCredentials();
    void eraseCredential(std::string origin);
    std::map<std::string,Credential> getMap(){return credentials;}
};

#endif // CREDENTIALS_MANAGER_H
