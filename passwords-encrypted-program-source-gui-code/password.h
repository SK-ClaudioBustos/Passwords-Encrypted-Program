#ifndef PASSWORD_H
#define PASSWORD_H
#include <fstream>
#include <string.h>

class Password
{
private:
    std::string password = "";
public:
    Password();
    std::string getPassword();
    void setPassword(std::string password);
    bool existenceOfFile();
    void savePassword();
    void recoveryPassword();
};

#endif // PASSWORD_H
