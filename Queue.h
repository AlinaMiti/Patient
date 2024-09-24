#pragma once
#include <iostream>
#include "Patient.h"

class Queue{    //'очередь'
private:
    Patient** _top_patient;//если топ заполнена то перекидываем вниз в начало, если мидл,то в топ в конец, если общ,то первого в конец мидла
    Patient** _middle_patient;
    Patient** _general_patient;
    size_t _sT;
    size_t _sM;
    size_t _sG;
    size_t _cT;
    size_t _cM;
    size_t _cG;
public:
    Queue(){
        _top_patient = new Patient*[_sT];
        _middle_patient = new Patient*[_sM];
        _general_patient = new Patient*[_sG];
        _cT = 0;
        _cM = 0;
        _cG = 0;
        _sT = 10;
        _sM = 10;
        _sG = 10;
    };
    Patient* Get_next_patient();

    void Append_patient(Patient* pat){
        if(pat->Get_estate()==I){
            if(_cT==_sT){
                _middle_patient[0] = pat;
            }
            else{
                _top_patient[_cT] = pat;
                _cT ++;
            }

        }
        if(pat->Get_estate()==II){
            if(_cM==_sM){

            }
            else{
                _middle_patient[_cM] = pat;
            }
            
        }
        if(pat->Get_estate()==III){
            if(_cG==_sG){

            }
            else{
               _general_patient[_cG] = pat;
            }        
        }
    }

    ~Queue(){
        for(size_t i = 0; i < _sT; i++){
            delete [] _top_patient[i];
            delete [] _middle_patient[i];
            delete [] _general_patient[i];
        }
    }



};