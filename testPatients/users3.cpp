#include <iostream>
#include <string>
#include <mysql.h>

//to connect to the database needed
//class patient to be declared here
class Patient{
    public:
    std::string name;
    std::string surname;
    std::string address;
    std::string sickness;
    int folder_number;
};

//add patient to db
int addPatient(MYSQL * conn , const Patient& patient){
    std::string query = "INSERT INTO patientTable(name ,surname ,address , sickness, folder_numer) VALUES ('";
    query += patient.name + "','";
    query += patient.surname + "','";
    query += patient.address + "','";
    query += patient.sickness + "','";
    query += std::to_string(patient.folder_number) + ");";
    int result = mysql_query(conn ,  query.c_str());
    if(result != 0){
        std::cerr << "Error adding patient to database:" << mysql_error(conn) << std::endl;
    }else{
        std::cout << "Patient added successfully." << std::endl;
    }
    return result;

}
//main starts
int main(){
    MYSQL* conn = mysql_init(nullptr);
    if(conn == nullptr){
        std::cerr << "Error initializing MYSQL connection" << mysql_error(conn) << std::endl;
        return 1;
    }
    conn = mysql_real_connect(conn , "localhost" , "username" , "password" , "database" , 3306 , nullptr, 0);
    if(conn == nullptr){
        std::cerr << "Error connecting to MySql server:" << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return 1;
    }


    Patient patient;
    std::cout << "Enter patient details:" << std::endl;
    std::cout << "Name: ";
    std::getline(std::cin, patient.name);
    std::cout << "Surname: ";
    std::getline(std::cin , patient.surname);
    std::cout << "Address: ";
    std::getline(std::cin , patient.address);
    std::cout << "Sickness: ";
    std::getline(std::cin , patient.sickness);
    std::cout << "Folder number: ";
    std::cin >> patient.folder_number;
    addPatient(conn, patient);

//close connection
    mysql_close(conn);
    return 0;
}