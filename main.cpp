#include <iostream>
#include "Patient.h"
#include <chrono>
#include "Queue.h"
#include "Doctor.h"
using namespace std::chrono;

int main(){
    Patient* patients = new Patient[10];
    int count = 0;
    while (count < 10){
        std::cin; //name surname patro born  создать и положить
    }

    Patient p1 = Patient("la", "nana", "rara", {std::chrono::month(1)/10/2024});
    Patient p2 = Patient("la nana rara", std::chrono::year_month_day{});
    Queue patient_queue; //очередь
    Doctor doc;
    
    while (true){
        Patient* current = patient_queue.Get_next_patient();  // "текущий" пациент
        doc.Next(current );
        delete current;
    }

    return 0;
}