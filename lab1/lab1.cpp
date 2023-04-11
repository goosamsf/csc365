/*
This Program read text file whose contents are dilimitered by ' , '
Read each line, parse by comma and do the query

*/


#include"lab1.h"


//Fill data base, read each line and convert it to proper data type.
void fill_db(vector<studb> &students_db, string mystr){
    
    studb student;
    char separator = ',';
    vector<string> myparse = parse_comma(mystr, separator);
    
    if(myparse.size()==8){
         students_db.push_back(str2struct(myparse, student));
    }
}

//Parse the line by comma
vector<string> parse_comma(string mystr, char separator){
    char c;
    string tmp = "";
    vector<string> strvec;
    int len = mystr.length();
    for(int i =0; i< len; i++){
        if(i == len-1){
            tmp+=mystr[i];
            strvec.push_back(tmp);
            continue;
        }
        if(mystr[i]==separator){
            strvec.push_back(tmp);
            tmp="";
            continue;
        }
        tmp+=mystr[i];
    }
   return strvec; 
}

//Convert all attributes to each datatype.
studb str2struct(vector<string> &myparse,  studb student){
   
   student.slname = myparse[0];
   student.sfname = myparse[1];
   student.grade = stoi(myparse[2]);
   student.classroom = stoi(myparse[3]);
   student.bus = stoi(myparse[4]);
   student.gpa = stof(myparse[5]);
   student.tlname = myparse[6];
   student.tfname = myparse[7];
   return student;
}

int main(int argc, char *argv[]){

    vector<studb> students_db;
    ifstream infile("students.txt");
    string stu_db;
    int index = 0; 
    while(infile){
        getline(infile, stu_db);
        fill_db(students_db, stu_db);
    }
    cout<<students_db.size()<<endl;    
    for(studb i : students_db){
        cout<<"Student's last name : " <<i.slname<<endl;
        cout<<"Student's first name : "<< i.sfname<<endl;
        cout<<"grade : "<< i.grade<<endl;
        cout<<"classroom : "<< i.classroom<<endl;
        cout<<"bus : "<< i.bus<<endl;
        cout<<"gpa : "<< i.gpa<<endl;
        cout<<"Teacher's last name : "<< i.tlname<<endl;
        cout<<"Teacher's first name : "<< i.tfname<<endl;
        cout<<"-----------------------------------"<<endl;
    }

    return 0;
}
