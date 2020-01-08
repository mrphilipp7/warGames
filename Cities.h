//
//  Cities.h
//  Global ThermoNuclear Warfare
//
//  Created by Zachary Philipp on 4/28/17.
//  Copyright © 2017 Zachary Philipp. All rights reserved.
//
#include <string>
using namespace std;


#ifndef Cities_h
#define Cities_h


class Cities
{
private:
    int total_population;
    int dead_population;
    int money_generated;
    string city_name;
public:
    //accessor functions to 'return' the private variables
    int get_total_population()const;
    int get_dead_population()const;
    int get_money_generated()const;
    string get_city_name()const;
    //mutator functions to change the value of the private variables
    void set_total_population(int);
    void set_dead_population(int);
    void set_money_generated(int);
    //default constructor
    Cities();
    //overload constructor
    Cities(int,int,int,string);
    //regular class functions
    //bool check_population();
};


#endif /* Cities_h */
