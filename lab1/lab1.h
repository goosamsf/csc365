#ifndef _LAB1_H
#define _LAB1_H
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <iomanip>
using namespace std;

struct studb{
    string slname;
    string sfname;
    int grade;
    int classroom;
    int bus;
    float gpa;
    string tlname;
    string tfname;
};

//Function Prototype
void fill_db(vector<studb>& vect, string str);
vector<string> parse_comma(string mystr, char c);
studb str2struct(vector<string> &myparse,  studb student);
string get_bus(string userans);
void get_contents(string userans, vector<string> &ans_contents);
void query_sl(vector<studb> & students, string lname);
void query_slb(vector<studb> & students, string lname);
void query_tl(vector<studb> & students, string lname);
void print_sfl(studb i);
void print_all(studb i);
void query_bus(vector<studb> & students, string number);
void query_grade(vector<studb> & students, string number);
void print_gradeorder(studb i);
void query_go(vector<studb> &students,string num,  string order);
bool compareBygrade(const studb &a, const studb &b);
void print_slb(studb i);
void print_sflgc(studb i);
void query_info(vector<studb> &students);
void query_average(vector<studb> &students, string number);

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b);
#endif
