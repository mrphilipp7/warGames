//
//  Missles.h
//  Global ThermoNuclear Warfare
//
//  Created by Zachary Philipp on 4/28/17.
//  Copyright © 2017 Zachary Philipp. All rights reserved.
//
#include <string>
using namespace std;

#ifndef Missles_h
#define Missles_h


class Missle
{
private:
    int quantity;
    int killquantity;
    int cost;
    string name;
public:
    //default constructor
    Missle();
    //overload constructor
    Missle(int,int,int,string);
    //accessor functions
    int get_quantity()const;
    int get_killquantity()const;
    int get_cost()const;
    string get_name()const;
    //mutator funcitons
    void set_quantity(int);
    //regular class functions
    bool check_quantity();
};

#endif /* Missles_h */
