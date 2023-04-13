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
string remove_ws(string s1){
	int len = s1.length()-1;
	while(s1[len]==' '){
		s1 = s1.erase(len);
		len = s1.length()-1;
	}
	return s1;
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


/*
parse_opt : This function takes user typed answer from given options
and call other desired behavior.
*/

void parse_opt(string userans, vector<studb> &students){
	string lname ="";
	vector<string> ans_contents;
	get_contents(userans, ans_contents);
	int anslen = ans_contents.size();		
	string ag0;
	string ag1;
	string ag2;
	if(ans_contents.size() == 1){
		query_info(students);
		//Do Info
	}else if (ans_contents.size() ==2){
		//do query_sl , query_tl , query_gn, query_bn, query_gn, query_an
		ag0 = ans_contents[0];
		ag1 = ans_contents[1];
		if(ag0 == "S" || ag0 == "Student"){
			//Student query
			query_sl(students,ag1);
		}else if(ag0 =="T" || ag0 =="Teacher"){
			query_tl(students,ag1);	
		}else if(ag0 =="G" || ag0 =="Grade"){
			query_grade(students,ag1);
		}else if(ag0 =="B" || ag0 == "Bus"){
			query_bus(students,ag1);
		}else if(ag0 == "A" || ag0 == "Average"){
			query_average(students, ag1);
		}
		
	}else if(ans_contents.size() == 3){
		ag0 = ans_contents[0];
		ag1 = ans_contents[1];
		ag2 = ans_contents[2];
		if((ag0 =="S" || ag0 =="Student") && (ag2=="B" || ag2=="Bus")){
			query_slb(students,ag1);
		}else if(ag0 =="G" || ag0 =="Grade"){
			if(ag2 == "L" || ag2 == "Low"|| ag2 =="H" || ag2 == "High"){
				query_go(students,ag1, ag2);
			}else{
				cout<<"Somthing Wrong ..."<<endl;
				cout<<"Usage : G[rade]: <Number> [H[igh]] || [L[ow]]"<<endl;
			}
		}
	}else{
		cout<< "No query command found ...";
	}



}


void print_student(studb i){
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

void get_contents(string userans, vector<string> &ans_contents){
	int i=0,j;
	int len = userans.length();
	for(int k = 0; k<len; k++){
		if(!(isdigit(userans[k])) &&!(isalpha(userans[k])) && !(isspace(userans[k]))){
			i++;
		}
	}
	if(i != 1){
		cout<<"This is invalid User Input :"<<endl;
		cout<<"Usage : <querycommand> : [querytarget1] [querytarget2]"<<endl;
		exit(1);
	}
	string parse1 ="";
	string parse2 ="";
	string parse3 ="";
	for(i = 0; i< len; i++){
		if(userans[i]==':'){
			break;
		}
	}
	parse1 = userans.substr(0,i);
	ans_contents.push_back(remove_ws(parse1));
	i++;		
	while(isspace(userans[i++]));
	j = i-1;
	while(i<len && !(isspace(userans[i++])));
	parse2=userans.substr(j,i-j);
	ans_contents.push_back(remove_ws(parse2));
	if(i<userans.length()){
		while(i<len && isspace(userans[i++]));
		j = i-1;
		while(i<len && isspace(userans[i++]));
		parse3=userans.substr(j,i);
		ans_contents.push_back(remove_ws(parse3));
	}
	if(ans_contents[ans_contents.size()-1].length() == 0){
		ans_contents.pop_back();
	}
}

int main(int argc, char *argv[]){
	string ty;
	string q1("Quit");
	string q2("Q");
    vector<studb> students_db;
    ifstream infile("students.txt");
    string stu_db;
    int index = 0; 
    while(infile){
        getline(infile, stu_db);
        fill_db(students_db, stu_db);
    }
	cout<<"Program starts running..."<<endl;
	cout<<"Query Range :" << students_db.size() << " Students."<<endl;
	cout<<endl;
	do{   
    cout<<"S[tudent]: <lastname> "<<endl;
    cout<<"S[tudent]: <lastname> [B[us]] "<<endl;
    cout<<"T[eacher]: <lastname>"<<endl;
    cout<<"G[rade]  : <Number>"<<endl;
    cout<<"B[us]    : <Number>"<<endl;
    cout<<"G[rade]  : <Number> H[igh]"<<endl;
    cout<<"G[rade]  : <Number> L[ow]"<<endl;
    cout<<"A[verage]: <Number>" <<endl;
    cout<<"I[nfo] : " <<endl;
	cout<<"Q[uit] :" <<endl;
	cout<<endl;
	getline(cin, ty);
	if(!ty.compare(q1) || !ty.compare(q2)){
		break;
	}else{
		parse_opt(ty, students_db);	
	}
	cout<<endl;

	}while(true);


    return 0;
}
