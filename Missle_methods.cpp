//
//  Missle_methods.cpp
//  Global ThermoNuclear Warfare
//
//  Created by Zachary Philipp on 4/28/17.
//  Copyright © 2017 Zachary Philipp. All rights reserved.
//

#include <stdio.h>
#include "Missles.h"
#include <string>
#include <iostream>
using namespace std;


//default constructor
Missle::Missle()
{
    quantity =0;
    killquantity =0;
    cost =0;
}

//overload constructor
Missle::Missle(int quant,int kill,int price, string names)
{
    quantity = quant;
    killquantity = kill;
    cost = price;
    name = names;
}

//accessor functions
int Missle::get_quantity()const
{
    return quantity;
}

int Missle::get_killquantity()const
{
    return killquantity;
}

int Missle::get_cost()const
{
    return cost;
}

string Missle::get_name()const
{
    return name;
}

//mutator functions
void Missle::set_quantity(int amount)
{
    quantity += amount;
}

//regular class functions
bool Missle::check_quantity()
{
    if(quantity > 0)
    {
        cout<<name;
        return true;
    }
    else
    {
        return false;
    }
}

