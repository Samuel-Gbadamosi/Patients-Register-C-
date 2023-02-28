#include <iostream>
#include <string>
#include <mysqlx/xdevapi.h>

class Patient {
public:

  std::string name;
  std::string surname;
  std::string address;
  std::string sickness;
  int folder_number;

};
//adding patient with mysql session
int addPatient(mysqlx::Session& session , const Patient&patient){

    mysqlx::Schema schema = session.getSchema("my_database");
    mysqlx::Table patientTable = schema.getTable("patientTable");
    mysqlx::RowValues newPatient = patient.Table.newRow()
      .set("name" , patient.name)
      .set("surname" , patient.surname);
      .set("address" , patient.address);
      .set("sickness" , patient.sickness);
      .set("folder_number" , patient.folder_number);
    mysqlx::Result result = patientTable.insert(newPatient).execute();
    if(result.getAffectedItemsCount() != 1){
        std::cerr << "Error add patient to database: " << result.getErrorMessages() << std::endl;
        return 1;
    } else{
        std::cout << "Patient added successfully." << std::endl;
        return 0;
    } 
}

int main(){
    mysqlx::Session session("localhost" ,33060 , "user" , "password");
    int result = addPatient(session,{"john" , "Doe" , "123 main str" ,"Flue" , 12345});
    if(result != 0){
        std::cer << "Failed to add patient to database." <<std::endl;
        return 1
    }
    return 0;
}