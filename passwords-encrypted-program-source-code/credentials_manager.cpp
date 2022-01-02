#include "credentials_manager.h"

Credentials_Manager::Credentials_Manager()
{

}

void Credentials_Manager::setCredential(std::pair <std::string,Credential> newP)
{
    this->credentials.insert(newP);
}

Credential Credentials_Manager::getCredential(std::string origin)
{
    return this->credentials[origin];
}

bool Credentials_Manager::credentialExistence(std::string origin)
{
    auto itr = this->credentials.find(origin);
    if(itr != this->credentials.end())
        return true;
    else
        return false;

}

std::string Credentials_Manager::encrypt(std::string word)
{
    char w[word.size()];
    strcpy(w,word.c_str());
    for(int i = 0; (i < 100 && w[i] != '\0'); i++)
                w[i] = w[i] + 69 * 2;
    return w;
}

std::string Credentials_Manager::decrypt(std::string word)
{
    char w[word.size()];
    strcpy(w,word.c_str());
    for(int i = 0; (i < 100 && w[i] != '\0'); i++)
        w[i] = w[i] - 69 * 2;
    return w;
}

void Credentials_Manager::saveCredentials()
{
    std::ofstream file("num.dat",std::ios::binary | std::ios::out | std::ios::trunc);
    if (this->credentials.size() != 0){     
        if(file.is_open()){
            for(auto i = this->credentials.begin(); i != this->credentials.end(); ++i){
                data_credential struD;
                strcpy(struD.origin,encrypt(i->first).c_str());
                strcpy(struD.user,encrypt(i->second.getUser()).c_str());
                strcpy(struD.password,encrypt(i->second.getPassword()).c_str());
                file.write((char*)&struD,sizeof(data_credential));
            }
        }
    }
    file.close();
}

void Credentials_Manager::recoveryOfCredentials()
{
    std::ifstream file("num.dat",std::ios::binary | std::ios::in);
    if(file.is_open()){
        data_credential aux;
        std::string a1,a2,a3;
        while(file.read((char*)&aux,sizeof(data_credential))){
            a1 = this->decrypt(std::string(aux.origin));
            a2 = this->decrypt(std::string(aux.user));
            a3 = this->decrypt(std::string(aux.password));
            this->credentials.insert(make_pair(a1,Credential(a2,a3)));
        }
    }
    file.close();
}

void Credentials_Manager::eraseCredential(std::string origin)
{
    this->credentials.erase(origin);
}
