#pragma once
#include <string>
#include <chrono>
#include <cstring>
#include <iostream>
#pragma comment(lib, "rpcrt4.lib")
#include <windows.h>
using namespace std::chrono;
using namespace std;

enum Gender{male, female};
enum Estate{I, II, III};//первый в первую и тп  //имущество?? (очереди)

struct Diagnos
{
    std::string disease;
    std::string drugs;
};

class Patient{
private:
    std::string _name;
    std::string _surname;
    std::string _patronymic;
    std::chrono::year_month_day _borh_date;
    UUID _uuid;
    Diagnos* _diagnos; //струкрура с 2мя полями 1 - описание 2 - лекарства
    Gender _gender;
    Estate _state;  //состояние??
    std::string _healfProblem;
    void Define_Gender(){
        if(_patronymic.back()=='a')
            _gender = female;
        else _gender = male;
    }
    void GenerateID();
    void DeterMineFIO(std::string FIO){
        int index1 = FIO.find(" ");
        int index2 = FIO.find(" ", index1+1);
        _name = FIO.substr(0, index1);
        _surname = FIO.substr(index1 + 1, index2-index1);
        _patronymic = FIO.substr(index2 + 1);
    }
public:
    Patient();

    Patient(std::string surname, std::string name, std::string patr, std::chrono::year_month_day born_date){
        _name = name;
        _surname = surname;
        _patronymic = patr;
        _borh_date = born_date;
        Define_Gender();
    }

    Patient(std::string FIO, std::chrono::year_month_day born_date){
        DeterMineFIO(FIO);
        _borh_date = born_date;
        Define_Gender();
    }

    std::string Get_health_problem(){
        int a = rand()%3;
        if (a == 1)
            _healfProblem = 'Super';
        if (a == 2)
            _healfProblem = 'Ok';
        if (a == 3)
            _healfProblem = 'Not ok';

        return _healfProblem;

    }
    Estate Get_estate(){
        if(_diagnos->disease == "Super")
            _state = III;
        if(_diagnos->disease == "Ok")
            _state = II;
        if(_diagnos->disease == "Not ok")
            _state = I;
            
        return _state;

    }

};