#ifndef _LAB1_H
#define _LAB1_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

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


#endif
