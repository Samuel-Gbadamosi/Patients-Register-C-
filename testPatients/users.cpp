#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//class patients without connecting to db
class Patient {
    public:
    std::string name;
    std::string surname;
    std::string address;
    std::string sickness;
    std::string codicefis;
    int folder_number;
};

//add patients functions
void addPatient(std::vector<Patient> & patients){
    Patient patient;
    std::cout << "Please enter patient's name:";
    std::getline(std::cin , patient.name);
    std::cout << "Please enter patient's surname: ";
    std::getline(std::cin ,patient.surname);
    std::cout << "Please enter patient's address: ";
    std::getline(std::cin , patient.address);
    std::cout << "Please enter patient's sickness:";
    std::getline(std::cin , patient.sickness);
    std::cout << "Please enter patient's codice fiscale:";
    std::getline(std::cin , patient.codicefis);
    std::cout << "Please enter patient's folder number";
    std::cin >> patient.folder_number;
    std::cin.ignore(); //clear input buffer
    patients.push_back(patient);
}

//function search names of patients
void searchByName(const std::vector<Patient>& patients, const std::string& name){
    std::vector<Patient> results;

    for(const auto& patient : patients){
        if(patient.name == name){
            results.push_back(patient);
        }
    }
//if empty no result found
    if(results.empty()){
        std::cout << "No results found." << std::endl;
    }  else{
        std::cout << "Search results for " << name << ":" << std::endl;
       //else give results depending on whats in the rray
        for(const Patient& patient : results){
            std::cout << "Name: " << patient.name << std::endl;
            std::cout << "Surname: " << patient.surname << std::endl;
            std::cout << "Address: " << patient.address << std::endl;
            std::cout << "Sickness:" << patient.sickness << std::endl;
            std::cout << "Codice_fiscale" << patient.codicefis << std::endl;
            std::cout << "Folder number: " << patient.folder_number << std::endl;
            std::cout << std::endl;
        }
    }
} 
//search by folder name 
void searchByFolderNumber(const std::vector<Patient> & patients, int folder_number){
    std::vector<Patient> results;
//run a foreach on all patients
    for(const Patient& patient : patients){
        if(patient.folder_number == folder_number){
            results.push_back(patient);
        }
    }

//if empty no result found
    if(results.empty()){
        std::cout << "No results found." << std::endl;
    } else{
        std::cout << "Search results for folder number" << folder_number << ":" << std::endl;
   //patients array
    for(const Patient& patient : results){
        std::cout << "Name:" << patient.name << std::endl;
        std::cout << "Surname:" << patient.surname << std::endl;
        std::cout << "Address:" << patient.address << std::endl;
        std::cout << "Sickness:" << patient.sickness << std::endl;
        std::cout << "codice_fiscale:" << patient.codicefis << std::endl;
        std::cout << "Folder number:" << patient.folder_number << std::endl;
        std::cout << std::endl;

    }
    
    
    }
}
//main account where functions will start run.
int main(){
    std::vector<Patient> patients;

    while(true){
        std::cout << "Enter a command (add , search by name , search by folder number , exit): ";
        std::string command;
        std::getline(std::cin , command);
     
     if(command == "add"){
         //add patient function
         addPatient(patients);
     } else if (command == "search by name"){
         std::cout << "Enter patient's name";
         std::string name;
         std::getline(std::cin , name);
         //search by name
         searchByName(patients , name);
     } else if (command == "search by folder number"){
         std::cout << "Enter folder number: ";
         int folder_number;
         std::cin >> folder_number;
         std::cin.ignore(); //clear input buffer
         //search by folder
         searchByFolderNumber(patients , folder_number);
     }else if (command == "exit"){
         break;
     }else {
         std::cout << "Invalid command." << std::endl;
     }



    }

    return 0;
}