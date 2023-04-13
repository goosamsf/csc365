

#include"lab1.h"

bool compareBygrade(const studb &a, const studb &b){
    return a.gpa < b.gpa;
}


void query_sl(vector<studb> & students, string lname){
	for(int i = 0; i< students.size();i++){
		if(students[i].slname== lname){
			print_all(students[i]);
		}
	}
}


void query_slb(vector<studb> & students, string lname){
	for(int i = 0; i< students.size();i++){
		if(students[i].slname== lname){
			print_slb(students[i]);
		}
	}
}

void query_tl(vector<studb> & students, string lname){

	for(int i = 0; i< students.size();i++){
		if(students[i].tlname== lname){
			print_sfl(students[i]);
		}
	}
}


void query_grade(vector<studb> & students, string number){
	for(int i = 0; i< students.size();i++){
		if(students[i].grade == stoi(number)){
			print_sfl(students[i]);
		}
	}
}

void query_bus(vector<studb> & students, string number){
	for(int i = 0; i< students.size();i++){
		if(students[i].bus == stoi(number)){
			print_sflgc(students[i]);
		}
	}
}

void query_go(vector<studb> &students, string num, string lh){
	vector<studb> temp;
	for(int i =0; i< students.size(); i++){
		if(students[i].grade == stoi(num) ){
			temp.push_back(students[i]);
		}
	}
	sort(temp.begin(), temp.end(), compareBygrade);
	if(lh == "L" || lh =="Low"){
		print_gradeorder(temp[0]);
	}else if(lh =="H" || lh =="High"){
		print_gradeorder(temp[temp.size()-1]);
	}
}

void query_average(vector<studb> &students, string num){
	vector<studb> temp;
	float avg = 0;
	int counter =0;
	for(int i = 0; i< students.size(); i++){
		if(students[i].grade==stoi(num)){
			counter++;
			avg += students[i].gpa;
		}	
	}
	if(counter==0){
		cout<< "Average Calculation wasn't done because of no elements"<<endl;
	}else{
		cout<<"Average GPA for grade "<< num<< " is "<<avg/counter<<endl;
	}
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
	return a.second < b.second;
}
void query_info(vector<studb> &students){
	vector<int> temp(6,0);
	vector<pair<int,int>> res;
	for(int i = 0 ; i< students.size(); i++){
		temp[students[i].grade-1]++;
	}
	for(int i = 0; i< temp.size(); i++){
		res.push_back({i+1, temp[i]});
	}
	sort(res.begin(), res.end(), sortbysec);
	for(int i =0; i< res.size(); i++){
		cout<<"grade: " <<res[i].first<< ", number of students : "<< res[i].second<<endl;
	}
}

void print_gradeorder(studb k){
	cout<<k.slname<<","<<k.sfname<<",";
	cout<<k.gpa<<",";
	cout<<k.bus<<",";
	cout<<k.tlname<<","<<k.tfname<<endl;

}

void print_sflgc(studb i){
	cout<<i.slname<<","<<i.sfname<<","<<i.grade<<","<<i.classroom<<endl;
}

void print_all(studb i){
	cout<<i.slname<<","<<i.sfname<<","<<i.grade<<","<<i.classroom<<","<<i.gpa<<","<<i.tlname<<","<<i.tfname<<endl;
}

void print_sfl(studb i){
	cout<<i.slname<<","<<i.sfname<<endl;
}
void print_slb(studb i){
	cout<<i.slname<<","<<i.sfname <<"," << i.bus<<endl;
}

