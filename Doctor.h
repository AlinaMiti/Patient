#pragma once
#include "Patient.h"
#include "Queue.h"

enum Drugs{med1,med2,med3,med4};

class Doctor{
private:

public:
    void Next(Patient* pat){   //осмотр пациента
        Check_patient(pat);
        Think(pat->Get_health_problem());
    };

    void Check_patient(Patient* pat){  //выявляем проблему пациента
        std::cout << pat->Get_health_problem()<<std::endl;
        
    }

    Diagnos Think(std::string diag){   //ставим диагноз
        Diagnos patient_diagnos;
        patient_diagnos.disease = diag;
        patient_diagnos.drugs = rand()%(sizeof(Drugs)/4);
        return patient_diagnos;
    }
};

