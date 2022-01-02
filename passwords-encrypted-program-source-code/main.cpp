#include <iostream>
#include <credential.h>
#include <credentials_manager.h>
#include <regex>
#include "password.h"
using namespace std;

//prototypes declaretion
pair <string,Credential> option1(Credentials_Manager & manager);
bool option2(Credentials_Manager & manager);
void option3(Credentials_Manager & manager);
void option4(Password & pass);

int main()
{
    //variables declaretion
    int option = 4; string password;
    Credentials_Manager manager;
    Password pass;

    while(true){
        if(pass.existenceOfFile()){
            pass.recoveryPassword();
            cout<<"Entry the Password: ";
            getline(cin,password);
            if(pass.getPassword() == password){
                break;
            }
            else{
                cout<<"\n\tERROR:WRONG PASSWORD\n\n";
            }
        }
        else{
            string second;
            regex str_expr("[0-9]+");
            cout<<"It is need it create a new password to use the program(use only numbers): ";
            getline(cin,password);
            cout<<"\nRepeat the password: ";
            getline(cin,second);

            if(regex_match(password,str_expr)){
                if(password == second){
                    pass.setPassword(password);
                    pass.savePassword();
                    break;
                }
                else{
                    cout<<"\n\tERROR:THE PASSWORDS DONT BE EQUAEL\n\n";
                }
            }
            else{
                cout<<"\n\tERROR: USE ONLY NUMBERS\n\n";
            }

        }
    }

    manager.recoveryOfCredentials();
    while(true){
        cout << "------------Credentials Encrypted and Recovery Program------------\n\n";
        cout <<"        Option 1: entry new credentials \n";
        cout <<"        Option 2: delete credentials \n";
        cout <<"        Option 3: show all credentials \n";
        cout <<"        Option 4: change password \n";
        cout <<"        Option 5: exit \n";

        cout <<"\n  Select a Option: ";
        cin >> option;
        cin.ignore();
        cout <<"\n";
        switch (option) {
            case 1:{
                pair newCr= option1(manager);
                manager.setCredential(newCr);
                cout<<"\n     CREDENTIAL ADDED SUCESSFLY\n\n";
                break;
            }
            case 2:{
                if(option2(manager))
                    cout<<"\n     CREDENTIAL ERASED SUCESSFLY\n\n";
                break;
            }
            case 3:{
                option3(manager);
                break;
            }
            case 4:{
                option4(pass);
                break;
            }
            default:{
                manager.saveCredentials();
                exit(1);
            }
        }
        cout<< string(65,'+') << "\n";
    }
    return 0;
}

pair <string,Credential> option1(Credentials_Manager &  manager){
    string origin,user,password;
    regex str_expr("[^ ].*");
    while(true){
        cout<<"     Enter Origin of the Credential(website,app,etc): ";
        getline(cin,origin);
        cout<<"     Enter User Name: ";
        getline(cin,user);
        cout<<"     Enter Password: ";
        getline(cin,password);

        if (regex_match(origin,str_expr)){
            if(manager.credentialExistence(origin)){
                cout<<"\n     Enter another origin, this already exist\n\n";
            }
            else
                break;//the input is valid
        }
        else
            cout<<"\n\t\tERROR: ENTER A VALID ORIGIN\n\n";
    }
    return make_pair(origin,Credential(user,password));
}

bool option2(Credentials_Manager &manager){
    string origin;
    cout <<"     Enter the Origin name of the Credential to Erase: ";
    getline(cin,origin);
    if(manager.credentialExistence(origin)){
        manager.eraseCredential(origin);
        return true;
    }
    else
        cout <<"     Origin name Invalid, does not exists";
    return false;
}

void option3(Credentials_Manager & manager){
    map<string,Credential> aux = manager.getMap();

    if(aux.size() == 0){
        cout<<"\tNOTHING TO SHOW, NO CREDENTIALS TO SHOW\n\n";
    }
    else{
        int repetitions = 29;
        cout<<"\n"<<string(repetitions,'-')<<"\n";
        cout<<"|  "<<"SHOWING THE CREDENTIALS"<<"  |\n";
        cout<<string(repetitions,'-')<<"\n";
        for(auto i = aux.begin(); i != aux.end(); ++i){
            cout<<"Origin:  "<< i->first <<"\n";
            cout<<"User:  "<<i->second.getUser()<<"\n";
            cout<<"Password:  "<<i->second.getPassword()<<"\n\n";
        }
    }
}

void option4(Password & pass){


    string aux;
    cout<<"\n\nEntry the last password used: ";
    getline(cin,aux);
    if(aux == pass.getPassword()){
        cout<<"\nEntry the new password: ";
        getline(cin,aux);
        pass.setPassword(aux);
        pass.savePassword();
        cout<<"\nPASSWORD CHANGED\n";
    }
    else
        cout<<"\nINCORRECT PASSWORD\n";
}
