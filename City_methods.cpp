//
//  City_methods.cpp
//  Global ThermoNuclear Warfare
//
//  Created by Zachary Philipp on 4/28/17.
//  Copyright © 2017 Zachary Philipp. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Cities.h"
using namespace std;

//default constructor and overload constructor
Cities::Cities()
{
    total_population = 0;
    dead_population = 0;
    money_generated = 0;
}

Cities::Cities(int alive,int dead, int money, string name)
{
    total_population = alive;
    dead_population = dead;
    money_generated = money;
    city_name = name;
}


//accessor functions defined
int Cities::get_total_population()const
{
    return total_population;
}

int Cities::get_dead_population()const
{
    return dead_population;
}

int Cities::get_money_generated()const
{
    return money_generated;
}

string Cities::get_city_name() const
{
    return city_name;
}


//mutator functions defined
void Cities::set_total_population(int pop)
{
    total_population = pop;
}

void Cities::set_dead_population(int death)
{
    dead_population = death;
}

void Cities::set_money_generated(int income)
{
    money_generated = income;
}

//regular class functions
//bool Cities::check_population()
/*
{
    if(total_population > 0)
    {
        cout<<city_name;
        return true;
    }
    else
    {
        Cities(0, dead_population, 0, city_name);
        return false;
    }
}
*/
