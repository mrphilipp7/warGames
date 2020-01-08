//
//  main.cpp
//  Global ThermoNuclear Warfare
//
//  Created by Zachary Philipp on 4/27/17.
//  Copyright © 2017 Zachary Philipp. All rights reserved.
//

#include <iostream>
#include <string>
#include "Maps.h"
#include "Cities.h"
#include "Missles.h"

using namespace std;
//intro begining stuff

//global scope class objects for cities
Cities Moscow(70845, 0 , 75,"Moscow");
Cities St_Petersburg(40629, 0, 60,"St. Petersburg");
Cities Magadan(25956,0,50,"Magadan");
Cities Seattle(70845, 0 , 75,"Seattle");
Cities Denver(40629, 0, 60,"Denver");
Cities Atlanta(25956,0,50,"Atlanta");

//global scope for class objects for missles
Missle CPU_ICBM(0,1000,100,"I.C.B.M.");
Missle CPU_Nuke(0,5000,400,"Nuclear Bomb");
Missle CPU_ChemNuke(0,10000,1000,"Chem. Hydrogen Bomb");
Missle PLY_ICBM(0,1000,100,"I.C.B.M.");
Missle PLY_Nuke(0,5000,400,"Nuclear Bomb");
Missle PLY_ChemNuke(0,10000,1000,"Chem. Hydrogen Bomb");

//global variables for program
int money=0;
int cpu_money = 0;
int totalpopulation=1;
int cpu_totalpopulation=1;
int totalweapons=0;

void wargames()
{
    string introgame = "error";
    while(introgame != "joshua")
    {
    
    cout<<"Password: ";
    cin>>introgame;
        if(introgame == "joshua" || introgame == "Joshua")
        {
            break;
        }
        else
        {
            cout<<"INCORRECT PASSWORD"<<endl;
            cout<<"**** hint \"joshua\" ****"<<endl;
            cout<<"Press enter and try again"<<endl;
            cin.ignore();
            cin.get();
            system("clear");
            //change for windows
        }
    }
}

void manual()
{
    //fill in later
    cout<<"**Global Thermonuclear Warfare Manual**"<<endl;
    cout<<"GTW is a turn based two player game. It simulates a nuclear conflict between two powerfull nations."<<endl;
    cout<<"The main menu gives 4 options, [1]fire weapons, [2]buy weapons, [3]view enemy map, [4] end turn"<<endl;
    cout<<"[1] takes you to the missle launch menu displaying enemy map with pop. info"<<endl;
    cout<<"[2] takes you to the market to purchase weapons."<<endl;
    cout<<"[3] displays info about enemy to help form a strategy"<<endl;
    cout<<"[4] ends turn letting your oppent have their turn"<<endl;
    cout<<"Buying weapons cost money which is made by cities every turn. The bigger the city's population the more money they produce"<<endl;
    cout<<"The game ends when one side has 0 pop. left."<<endl;
    cin.get();
    cin.ignore();
}

void gamebegin()
{
    system("clear");
    string yes = "no";
    char game;
    cout<<"Welcome back Mr. Falken, want to play a game?"<<endl;
    while(yes != "yes")
    {
        cin>>yes;
        if(yes == "yes" || yes == "Yes")
        {
            cout<<"What would you like to play?"<<endl;
        }
        else
        {
            cout<<"Please can we play a game Mr. Falken"<<endl;
        }
    }
    cout<<"Falken's games: "<<endl;
    cout<<"[a] <Global Thermonuclear Warfare>"<<endl;
    while (true)
    {
        //cin.ignore();
        cin>>game;
        if(game == 'a' || game == 'A')
        {
            //change for windows
            char man;
            system("clear");
            cout<<"Read manual before game begin?[y,n]"<<endl;
            cin>>man;
            if(man == 'y' || man == 'Y')
            {
                manual();
            }
            cout<<"Launching game...please wait"<<endl;
            cin.ignore();
            cout<<"press 'enter' to begin game..."<<endl;
            cin.get();
            system("clear");
            break;
        }
        else
        {
            cout<<"That game isn't in this directory, please choose a valid game"<<endl;
        }
    }
    
}

int beginGame()
{
    char user_playas = 'a';
    cout<<"player 1 choose a super-power to play as \n[a] USSR\n[b] USA"<<endl;
    while(true)
    {
        cin>>user_playas;
        if(user_playas == 'a' || user_playas == 'A')
        {
            //ussr = 1
            return 1;
        }
        else if (user_playas == 'b' || user_playas == 'B')
        {
            //usa =0
            return 0;
        }
        else
        {
            cout<<"Not a choice, pick again"<<endl;
        }
    }
}

void USSR_gameplay()
{
    //change for windows version
    system("clear");
        char user_pick;
        money = money + Moscow.get_money_generated() + St_Petersburg.get_money_generated() + Magadan.get_money_generated();
        totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
        while(true)
        {
            system("clear");
            cout<<"USSR turn..."<<endl;
            display_USSR();
            cout<<"Cities: "<<endl;
            cout<<Moscow.get_city_name()<<"\t\t\t pop: "<<Moscow.get_total_population()<<"\tMoney generated: "<<Moscow.get_money_generated()<<endl;
            cout<<St_Petersburg.get_city_name()<<"\t\t pop: "<<St_Petersburg.get_total_population()<<"\tMoney generated: "<<St_Petersburg.get_money_generated()<<endl;
            cout<<Magadan.get_city_name()<<"\t\t\t pop: "<<Magadan.get_total_population()<<"\tMoney generated: "<<Magadan.get_money_generated()<<endl;
            cout<<"Total population: "<<totalpopulation<<"\t Total cash: "<<money<<endl<<endl;
            cout<<"Weapons: "<<endl;
            cout<<PLY_ICBM.get_name()<<"\t\t Amount: "<<PLY_ICBM.get_quantity()<<endl;
            cout<<PLY_Nuke.get_name()<<"\t\t Amount: "<<PLY_Nuke.get_quantity()<<endl;
            cout<<PLY_ChemNuke.get_name()<<"\t Amount: "<<PLY_ChemNuke.get_quantity()<<endl;
            cout<<"Options: [a]Fire Weapons [b]purchase weapons [c]view enemy map [d]end turn"<<endl;
            cin>>user_pick;
            if(user_pick == 'a' || user_pick == 'A')
            {
                //fire weapons//START HERE
                while(true)
                {
                    system("clear");
                    display_USA();
                    cout<<"Select target to attack"<<endl;
                    cout<<"[a] Seattle\tPop:"<<Seattle.get_total_population()<<endl;
                    cout<<"[b] Denver\tPop:"<<Denver.get_total_population()<<endl;
                    cout<<"[c] Atlanta\tPop:"<<Atlanta.get_total_population()<<endl;
                    cout<<"[d] Exit targeting system"<<endl;
                    cin>>user_pick;
                    if (user_pick == 'a' || user_pick == 'A')
                    {
                        //asdfads
                        while (true)
                        {
                            system("clear");
                            cout<<"What shall we launch at Seattle"<<endl;
                            cout<<"[a] "<<PLY_ICBM.get_name()<<": "<<PLY_ICBM.get_quantity()<<endl;
                            cout<<"[b] "<<PLY_Nuke.get_name()<<": "<<PLY_Nuke.get_quantity()<<endl;
                            cout<<"[c] "<<PLY_ChemNuke.get_name()<<": "<<PLY_ChemNuke.get_quantity()<<endl;
                            cin>>user_pick;
                            if ((user_pick == 'a' || user_pick =='A')&&(PLY_ICBM.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an ICBM at Seattle!"<<endl;
                                Seattle.set_dead_population(Seattle.get_dead_population()+PLY_ICBM.get_killquantity());
                                Seattle.set_total_population((Seattle.get_total_population())-(PLY_ICBM.get_killquantity()));
                                PLY_ICBM.set_quantity(-1);
                                if(Seattle.get_total_population() <= 0)
                                {
                                    Seattle.set_total_population(0);
                                    cout<<"You destroyed Seattle comrade"<<endl;
                                    Seattle.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_sea();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }
                            else if ((user_pick == 'b' || user_pick =='B')&&(PLY_Nuke.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an Nuclear warhead at Seattle!"<<endl;
                                Seattle.set_dead_population(Seattle.get_dead_population()+PLY_Nuke.get_killquantity());
                                Seattle.set_total_population((Seattle.get_total_population())-(PLY_Nuke.get_killquantity()));
                                PLY_Nuke.set_quantity(-1);
                                if(Seattle.get_total_population() <= 0)
                                {
                                    Seattle.set_total_population(0);
                                    cout<<"You destroyed Seattle comrade"<<endl;
                                    Seattle.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_sea();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }
                            else if ((user_pick == 'c' || user_pick =='C')&&(PLY_ChemNuke.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an Chemical warhead at Seattle!"<<endl;
                                Seattle.set_dead_population(Seattle.get_dead_population()+PLY_ChemNuke.get_killquantity());
                                Seattle.set_total_population((Seattle.get_total_population())-(PLY_ChemNuke.get_killquantity()));
                                PLY_ChemNuke.set_quantity(-1);
                                if(Seattle.get_total_population() <= 0)
                                {
                                    Seattle.set_total_population(0);
                                    cout<<"You destroyed Seattle comrade"<<endl;
                                    Seattle.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_sea();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }

                            else
                            {
                                cout<<"You don't have the weaponry to launch that attack"<<endl;
                                cin.get();
                                cin.ignore();
                                break;
                            }
                        }
                        
                    }
                    else if (user_pick == 'b'||user_pick=='B')
                    {
                        //asdfads
                        while (true)
                        {
                            system("clear");
                            cout<<"What shall we launch at Denver"<<endl;
                            cout<<"[a] "<<PLY_ICBM.get_name()<<": "<<PLY_ICBM.get_quantity()<<endl;
                            cout<<"[b] "<<PLY_Nuke.get_name()<<": "<<PLY_Nuke.get_quantity()<<endl;
                            cout<<"[c] "<<PLY_ChemNuke.get_name()<<": "<<PLY_ChemNuke.get_quantity()<<endl;
                            cin>>user_pick;
                            if ((user_pick == 'a' || user_pick =='A')&&(PLY_ICBM.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an ICBM at Denver!"<<endl;
                                Denver.set_dead_population(Denver.get_dead_population()+PLY_ICBM.get_killquantity());
                                Denver.set_total_population((Denver.get_total_population())-(PLY_ICBM.get_killquantity()));
                                PLY_ICBM.set_quantity(-1);
                                if(Denver.get_total_population() <= 0)
                                {
                                    Denver.set_total_population(0);
                                    cout<<"You destroyed Denver comrade"<<endl;
                                    Denver.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_sea();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }
                            else if ((user_pick == 'b' || user_pick =='B')&&(PLY_Nuke.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an Nuclear warhead at Denver!"<<endl;
                                Denver.set_dead_population(Denver.get_dead_population()+PLY_Nuke.get_killquantity());
                                Denver.set_total_population((Denver.get_total_population())-(PLY_Nuke.get_killquantity()));
                                PLY_Nuke.set_quantity(-1);
                                if(Denver.get_total_population() <= 0)
                                {
                                    Denver.set_total_population(0);
                                    cout<<"You destroyed Denver comrade"<<endl;
                                    Denver.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_sea();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }
                            else if ((user_pick == 'c' || user_pick =='C')&&(PLY_ChemNuke.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an Chemical warhead at Denver!"<<endl;
                                Denver.set_dead_population(Denver.get_dead_population()+PLY_ChemNuke.get_killquantity());
                                Denver.set_total_population((Denver.get_total_population())-(PLY_ChemNuke.get_killquantity()));
                                PLY_ChemNuke.set_quantity(-1);
                                if(Denver.get_total_population() <= 0)
                                {
                                    Denver.set_total_population(0);
                                    cout<<"You destroyed Denver comrade"<<endl;
                                    Denver.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_den();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }
                            
                            else
                            {
                                cout<<"You don't have the weaponry to launch that attack"<<endl;
                                cin.get();
                                cin.ignore();
                                break;
                            }
                        }

                    }
                    else if(user_pick == 'c' ||user_pick=='C')
                    {
                        //asdfasf
                        //asdfads
                        while (true)
                        {
                            system("clear");
                            cout<<"What shall we launch at Atlanta"<<endl;
                            cout<<"[a] "<<PLY_ICBM.get_name()<<": "<<PLY_ICBM.get_quantity()<<endl;
                            cout<<"[b] "<<PLY_Nuke.get_name()<<": "<<PLY_Nuke.get_quantity()<<endl;
                            cout<<"[c] "<<PLY_ChemNuke.get_name()<<": "<<PLY_ChemNuke.get_quantity()<<endl;
                            cin>>user_pick;
                            if ((user_pick == 'a' || user_pick =='A')&&(PLY_ICBM.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an ICBM at Atlanta!"<<endl;
                                Atlanta.set_dead_population(Atlanta.get_dead_population()+PLY_ICBM.get_killquantity());
                                Atlanta.set_total_population((Atlanta.get_total_population())-(PLY_ICBM.get_killquantity()));
                                PLY_ICBM.set_quantity(-1);
                                if(Atlanta.get_total_population() <= 0)
                                {
                                    Atlanta.set_total_population(0);
                                    cout<<"You destroyed Atlanta comrade"<<endl;
                                    Atlanta.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_atl();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }
                            else if ((user_pick == 'b' || user_pick =='B')&&(PLY_Nuke.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an Nuclear warhead at Atlanta!"<<endl;
                                Atlanta.set_dead_population(Atlanta.get_dead_population()+PLY_Nuke.get_killquantity());
                                Atlanta.set_total_population((Atlanta.get_total_population())-(PLY_Nuke.get_killquantity()));
                                PLY_Nuke.set_quantity(-1);
                                if(Atlanta.get_total_population() <= 0)
                                {
                                    Atlanta.set_total_population(0);
                                    cout<<"You destroyed Atlanta comrade"<<endl;
                                    Atlanta.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_sea();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }
                            else if ((user_pick == 'c' || user_pick =='C')&&(PLY_ChemNuke.get_quantity() > 0))
                            {
                                cout<<"Russia has launched an Chemical warhead at Atlanta!"<<endl;
                                Atlanta.set_dead_population(Atlanta.get_dead_population()+PLY_ChemNuke.get_killquantity());
                                Atlanta.set_total_population((Atlanta.get_total_population())-(PLY_ChemNuke.get_killquantity()));
                                PLY_ChemNuke.set_quantity(-1);
                                if(Atlanta.get_total_population() <= 0)
                                {
                                    Atlanta.set_total_population(0);
                                    cout<<"You destroyed Atlanta comrade"<<endl;
                                    Atlanta.set_money_generated(0);
                                    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                                    destroy_atl();
                                }
                                cin.get();
                                cin.ignore();
                                break;
                            }
                            
                            else
                            {
                                cout<<"You don't have the weaponry to launch that attack"<<endl;
                                cin.get();
                                cin.ignore();
                                break;
                            }
                        }
                    }
                    else if(user_pick == 'd' || user_pick == 'D')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"That is not an option comrade"<<endl;
                        cin.get();
                        cin.ignore();
                    }
                }
                //break;
            }
            else if(user_pick =='b' || user_pick == 'B')
            {
                //buy weapons
                system("clear");//change for windows
                cout<<"Welcome to the Russian market place! Would you like to buy some bombs?"<<endl;
                cout<<"Your money: "<<money<<endl;
                cout<<"[a] I.C.B.M.\t\t\t\t cost: 100"<<endl;
                cout<<"[b] Nuclear Warhead\t\t\t cost: 400"<<endl;
                cout<<"[c] Chemical Hydrogen Bomb\t\t cost: 1000"<<endl;
                cout<<"[d] Exit the USSR nuclear shop..."<<endl;
                bool again = true;
                while(again)
                {
                    cin.ignore();
                    cin>>user_pick;
                    int amount;
                    if (user_pick == 'a' || user_pick==  'A')
                    {
                        cout<<"How many I.C.B.M. missles would you like?"<<endl;
                        cin>>amount;
                        if(money >= amount*(PLY_ICBM.get_cost()))
                        {
                            money -= amount*100;
                            PLY_ICBM.set_quantity(amount);
                            cout<<"You purchased "<<amount<<" I.C.B.M. missles"<<endl;
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else
                        {
                            cout<<"You cannot afford that comrade"<<endl;
                            cin.get();
                            cin.ignore();
                        }
                    }
                    else if(user_pick =='b' || user_pick=='B')
                    {
                        cout<<"How many Nuclear missles would you like?"<<endl;
                        cin>>amount;
                        if(money >= amount*(PLY_Nuke.get_cost()))
                        {
                            money -= amount*400;
                            PLY_Nuke.set_quantity(amount);
                            cout<<"You purchased "<<amount<<" Nuclear missles"<<endl;
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else
                        {
                            cout<<"You cannot afford that comrade"<<endl;
                            cin.get();
                            cin.ignore();
                        }
                    }
                    else if (user_pick =='c' || user_pick =='C')
                    {
                        cout<<"How many Chemical missles would you like?"<<endl;
                        cin>>amount;
                        if(money >= amount*(PLY_ChemNuke.get_cost()))
                        {
                            money -= amount*1000;
                            PLY_ChemNuke.set_quantity(amount);
                            cout<<"You purchased "<<amount<<" Chemical missles"<<endl;
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else
                        {
                            cout<<"You cannot afford that comrade"<<endl;
                            cin.get();
                            cin.ignore();
                        }
                    
                    }
                    else if (user_pick == 'd' || user_pick == 'D')
                    {
                        //exit shop
                        again = false;
                    }
                    else
                    {
                        cout<<"That is not an option comrade"<<endl;
                        cin.get();
                        cin.ignore();
                    }
                }
                //break;
            }
            else if(user_pick == 'c' ||user_pick=='C')
            {
                system("clear");
                cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
                display_USA();
                cout<<endl;
                cout<<"Cities: "<<endl;
                cout<<Seattle.get_city_name()<<"\t\t\t pop: "<<Seattle.get_total_population()<<endl;
                cout<<Denver.get_city_name()<<"\t\t\t pop: "<<Denver.get_total_population()<<endl;
                cout<<Atlanta.get_city_name()<<"\t\t\t pop: "<<Atlanta.get_total_population()<<endl;
                cout<<"Total population: "<<cpu_totalpopulation<<endl;
                cout<<"enter 'enter' to exit usa viewing map and head back to menu...\n";
                cin.get();
                cin.ignore();
            }
            else if(user_pick == 'd' || user_pick == 'D')
            {
                break;
            }
            else
            {
                cout<<"That is not a choice comrade"<<endl;
                cin.get();
                cin.ignore();
            }
        }
}

void USA_gameplay()
{
    //change for windows version
    system("clear");
    char user_pick;
    cpu_money = cpu_money + Seattle.get_money_generated() + Denver.get_money_generated() + Atlanta.get_money_generated();
    cpu_totalpopulation = Seattle.get_total_population() + Denver.get_total_population() + Atlanta.get_total_population();
    while(true)
    {
        system("clear");
        cout<<"USA turn..."<<endl;
        display_USA();
        cout<<"Cities: "<<endl;
        cout<<Seattle.get_city_name()<<"\t\t\t pop: "<<Seattle.get_total_population()<<"\tMoney generated: "<<Seattle.get_money_generated()<<endl;
        cout<<Denver.get_city_name()<<"\t\t\t pop: "<<Denver.get_total_population()<<"\tMoney generated: "<<Denver.get_money_generated()<<endl;
        cout<<Atlanta.get_city_name()<<"\t\t\t pop: "<<Atlanta.get_total_population()<<"\tMoney generated: "<<Atlanta.get_money_generated()<<endl;
        cout<<"Total population: "<<cpu_totalpopulation<<"\t Total cash: "<<cpu_money<<endl<<endl;
        cout<<"Weapons: "<<endl;
        cout<<CPU_ICBM.get_name()<<"\t\t Amount: "<<CPU_ICBM.get_quantity()<<endl;
        cout<<CPU_Nuke.get_name()<<"\t\t Amount: "<<CPU_Nuke.get_quantity()<<endl;
        cout<<CPU_ChemNuke.get_name()<<"\t Amount: "<<CPU_ChemNuke.get_quantity()<<endl;
        cout<<"Options: [a]Fire Weapons [b]purchase weapons [c]view enemy map [d]end turn"<<endl;
        cin>>user_pick;
        if(user_pick == 'a' || user_pick == 'A')
        {
            //fire weapons//START HERE
            while(true)
            {
                system("clear");
                display_USSR();
                cout<<"Select target to attack"<<endl;
                cout<<"[a] Moscow\t\tPop:"<<Moscow.get_total_population()<<endl;
                cout<<"[b] St. Petersburg\tPop:"<<St_Petersburg.get_total_population()<<endl;
                cout<<"[c] Magadan\t\tPop:"<<Magadan.get_total_population()<<endl;
                cout<<"[d] Exit targeting system"<<endl;
                cin>>user_pick;
                if (user_pick == 'a' || user_pick == 'A')
                {
                    //asdfads
                    while (true)
                    {
                        system("clear");
                        cout<<"What shall we launch at Moscow"<<endl;
                        cout<<"[a] "<<CPU_ICBM.get_name()<<": "<<CPU_ICBM.get_quantity()<<endl;
                        cout<<"[b] "<<CPU_Nuke.get_name()<<": "<<CPU_Nuke.get_quantity()<<endl;
                        cout<<"[c] "<<CPU_ChemNuke.get_name()<<": "<<CPU_ChemNuke.get_quantity()<<endl;
                        cin>>user_pick;
                        if ((user_pick == 'a' || user_pick =='A')&&(CPU_ICBM.get_quantity() > 0))
                        {
                            cout<<"America has launched an ICBM at Moscow!"<<endl;
                            Moscow.set_dead_population(Moscow.get_dead_population()+CPU_ICBM.get_killquantity());
                            Moscow.set_total_population((Moscow.get_total_population())-(CPU_ICBM.get_killquantity()));
                            CPU_ICBM.set_quantity(-1);
                            if(Moscow.get_total_population() <= 0)
                            {
                                Moscow.set_total_population(0);
                                cout<<"You destroyed Moscow"<<endl;
                                Moscow.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_mos();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else if ((user_pick == 'b' || user_pick =='B')&&(CPU_Nuke.get_quantity() > 0))
                        {
                            cout<<"America has launched an Nuclear warhead at Moscow!"<<endl;
                            Moscow.set_dead_population(Moscow.get_dead_population()+CPU_Nuke.get_killquantity());
                            Moscow.set_total_population((Moscow.get_total_population())-(CPU_Nuke.get_killquantity()));
                            CPU_Nuke.set_quantity(-1);
                            if(Moscow.get_total_population() <= 0)
                            {
                                Moscow.set_total_population(0);
                                cout<<"You destroyed Moscow"<<endl;
                                Moscow.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_mos();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else if ((user_pick == 'c' || user_pick =='C')&&(CPU_ChemNuke.get_quantity() > 0))
                        {
                            cout<<"America has launched an Chemical warhead at Moscow!"<<endl;
                            Moscow.set_dead_population(Moscow.get_dead_population()+CPU_ChemNuke.get_killquantity());
                            Moscow.set_total_population((Moscow.get_total_population())-(CPU_ChemNuke.get_killquantity()));
                            CPU_ChemNuke.set_quantity(-1);
                            if(Moscow.get_total_population() <= 0)
                            {
                                Moscow.set_total_population(0);
                                cout<<"You destroyed Moscow"<<endl;
                                Moscow.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_mos();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        
                        else
                        {
                            cout<<"You don't have the weaponry to launch that attack"<<endl;
                            cin.get();
                            cin.ignore();
                            break;
                        }
                    }
                    
                }
                else if (user_pick == 'b'||user_pick=='B')
                {
                    //asdfads
                    while (true)
                    {
                        system("clear");
                        cout<<"What shall we launch at St. Petersburg"<<endl;
                        cout<<"[a] "<<CPU_ICBM.get_name()<<": "<<CPU_ICBM.get_quantity()<<endl;
                        cout<<"[b] "<<CPU_Nuke.get_name()<<": "<<CPU_Nuke.get_quantity()<<endl;
                        cout<<"[c] "<<CPU_ChemNuke.get_name()<<": "<<CPU_ChemNuke.get_quantity()<<endl;
                        cin>>user_pick;
                        if ((user_pick == 'a' || user_pick =='A')&&(CPU_ICBM.get_quantity() > 0))
                        {
                            cout<<"America has launched an ICBM at St. Petersburg!"<<endl;
                            St_Petersburg.set_dead_population(St_Petersburg.get_dead_population()+CPU_ICBM.get_killquantity());
                            St_Petersburg.set_total_population((St_Petersburg.get_total_population())-(CPU_ICBM.get_killquantity()));
                            CPU_ICBM.set_quantity(-1);
                            if(St_Petersburg.get_total_population() <= 0)
                            {
                                St_Petersburg.set_total_population(0);
                                cout<<"You destroyed St. Petersburg"<<endl;
                                St_Petersburg.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_spb();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else if ((user_pick == 'b' || user_pick =='B')&&(CPU_Nuke.get_quantity() > 0))
                        {
                            cout<<"America has launched an Nuclear warhead at St. Petersburg"<<endl;
                            St_Petersburg.set_dead_population(St_Petersburg.get_dead_population()+CPU_Nuke.get_killquantity());
                            St_Petersburg.set_total_population((St_Petersburg.get_total_population())-(CPU_Nuke.get_killquantity()));
                            CPU_Nuke.set_quantity(-1);
                            if(St_Petersburg.get_total_population() <= 0)
                            {
                                St_Petersburg.set_total_population(0);
                                cout<<"You destroyed St. Petersburg"<<endl;
                                St_Petersburg.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_spb();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else if ((user_pick == 'c' || user_pick =='C')&&(CPU_ChemNuke.get_quantity() > 0))
                        {
                            cout<<"America has launched an Chemical warhead at St. Petersburg!"<<endl;
                            St_Petersburg.set_dead_population(St_Petersburg.get_dead_population()+CPU_ChemNuke.get_killquantity());
                            St_Petersburg.set_total_population((St_Petersburg.get_total_population())-(CPU_ChemNuke.get_killquantity()));
                            CPU_ChemNuke.set_quantity(-1);
                            if(St_Petersburg.get_total_population() <= 0)
                            {
                                St_Petersburg.set_total_population(0);
                                cout<<"You destroyed St. Petersburg"<<endl;
                                St_Petersburg.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_spb();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        
                        else
                        {
                            cout<<"You don't have the weaponry to launch that attack"<<endl;
                            cin.get();
                            cin.ignore();
                            break;
                        }
                    }
                    
                }
                else if(user_pick == 'c' ||user_pick=='C')
                {
                    //asdfasf
                    //asdfads
                    while (true)
                    {
                        system("clear");
                        cout<<"What shall we launch at Magadan"<<endl;
                        cout<<"[a] "<<CPU_ICBM.get_name()<<": "<<CPU_ICBM.get_quantity()<<endl;
                        cout<<"[b] "<<CPU_Nuke.get_name()<<": "<<CPU_Nuke.get_quantity()<<endl;
                        cout<<"[c] "<<CPU_ChemNuke.get_name()<<": "<<CPU_ChemNuke.get_quantity()<<endl;
                        cin>>user_pick;
                        if ((user_pick == 'a' || user_pick =='A')&&(CPU_ICBM.get_quantity() > 0))
                        {
                            cout<<"America has launched an ICBM at Magadan!"<<endl;
                            Magadan.set_dead_population(Magadan.get_dead_population()+CPU_ICBM.get_killquantity());
                            Magadan.set_total_population((Magadan.get_total_population())-(CPU_ICBM.get_killquantity()));
                            CPU_ICBM.set_quantity(-1);
                            if(Magadan.get_total_population() <= 0)
                            {
                                Magadan.set_total_population(0);
                                cout<<"You destroyed Magadan"<<endl;
                                Magadan.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_mag();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else if ((user_pick == 'b' || user_pick =='B')&&(CPU_Nuke.get_quantity() > 0))
                        {
                            cout<<"America has launched an Nuclear warhead at Magadan!"<<endl;
                            Magadan.set_dead_population(Magadan.get_dead_population()+CPU_Nuke.get_killquantity());
                            Magadan.set_total_population((Magadan.get_total_population())-(CPU_Nuke.get_killquantity()));
                            CPU_Nuke.set_quantity(-1);
                            if(Magadan.get_total_population() <= 0)
                            {
                                Magadan.set_total_population(0);
                                cout<<"You destroyed Magadan"<<endl;
                                Magadan.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_mag();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        else if ((user_pick == 'c' || user_pick =='C')&&(CPU_ChemNuke.get_quantity() > 0))
                        {
                            cout<<"America has launched an Chemical warhead at Magadan!"<<endl;
                            Magadan.set_dead_population(Magadan.get_dead_population()+CPU_ChemNuke.get_killquantity());
                            Magadan.set_total_population((Magadan.get_total_population())-(CPU_ChemNuke.get_killquantity()));
                            CPU_ChemNuke.set_quantity(-1);
                            if(Magadan.get_total_population() <= 0)
                            {
                                Magadan.set_total_population(0);
                                cout<<"You destroyed Magadan"<<endl;
                                Magadan.set_money_generated(0);
                                totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
                                destroy_mag();
                            }
                            cin.get();
                            cin.ignore();
                            break;
                        }
                        
                        else
                        {
                            cout<<"You don't have the weaponry to launch that attack"<<endl;
                            cin.get();
                            cin.ignore();
                            break;
                        }
                    }
                }
                else if(user_pick == 'd' || user_pick == 'D')
                {
                    break;
                }
                else
                {
                    cout<<"That is not an option"<<endl;
                    cin.get();
                    cin.ignore();
                }
            }
            //break;
        }
        else if(user_pick =='b' || user_pick == 'B')
        {
            //buy weapons
            system("clear");//change for windows
            cout<<"Welcome to the American market place! Would you like to buy some bombs?"<<endl;
            cout<<"Your money: "<<cpu_money<<endl;
            cout<<"[a] I.C.B.M.\t\t\t\t cost: 100"<<endl;
            cout<<"[b] Nuclear Warhead\t\t\t cost: 400"<<endl;
            cout<<"[c] Chemical Hydrogen Bomb\t\t cost: 1000"<<endl;
            cout<<"[d] Exit the USSR nuclear shop..."<<endl;
            bool again = true;
            while(again)
            {
                cin.ignore();
                cin>>user_pick;
                int amount;
                if (user_pick == 'a' || user_pick==  'A')
                {
                    cout<<"How many I.C.B.M. missles would you like?"<<endl;
                    cin>>amount;
                    if(cpu_money >= amount*(CPU_ICBM.get_cost()))
                    {
                        cpu_money -= amount*100;
                        CPU_ICBM.set_quantity(amount);
                        cout<<"You purchased "<<amount<<" I.C.B.M. missles"<<endl;
                        cin.get();
                        cin.ignore();
                        break;
                    }
                    else
                    {
                        cout<<"You cannot afford that"<<endl;
                        cin.get();
                        cin.ignore();
                    }
                }
                else if(user_pick =='b' || user_pick=='B')
                {
                    cout<<"How many Nuclear missles would you like?"<<endl;
                    cin>>amount;
                    if(cpu_money >= amount*(PLY_Nuke.get_cost()))
                    {
                        cpu_money -= amount*400;
                        CPU_Nuke.set_quantity(amount);
                        cout<<"You purchased "<<amount<<" Nuclear missles"<<endl;
                        cin.get();
                        cin.ignore();
                        break;
                    }
                    else
                    {
                        cout<<"You cannot afford that"<<endl;
                        cin.get();
                        cin.ignore();
                    }
                }
                else if (user_pick =='c' || user_pick =='C')
                {
                    cout<<"How many Chemical missles would you like?"<<endl;
                    cin>>amount;
                    if(cpu_money >= amount*(CPU_ChemNuke.get_cost()))
                    {
                        cpu_money -= amount*1000;
                        CPU_ChemNuke.set_quantity(amount);
                        cout<<"You purchased "<<amount<<" Chemical missles"<<endl;
                        cin.get();
                        cin.ignore();
                        break;
                    }
                    else
                    {
                        cout<<"You cannot afford that"<<endl;
                        cin.get();
                        cin.ignore();
                    }
                    
                }
                else if (user_pick == 'd' || user_pick == 'D')
                {
                    //exit shop
                    again = false;
                }
                else
                {
                    cout<<"That is not an option"<<endl;
                    cin.get();
                    cin.ignore();
                }
            }
            //break;
        }
        else if(user_pick == 'c' ||user_pick=='C')
        {
            system("clear");
            totalpopulation = Moscow.get_total_population() + St_Petersburg.get_total_population() + Magadan.get_total_population();
            display_USSR();
            cout<<endl;
            cout<<"Cities: "<<endl;
            cout<<Moscow.get_city_name()<<"\t\t\t pop: "<<Moscow.get_total_population()<<endl;
            cout<<St_Petersburg.get_city_name()<<"\t\t pop: "<<St_Petersburg.get_total_population()<<endl;
            cout<<Magadan.get_city_name()<<"\t\t\t pop: "<<Magadan.get_total_population()<<endl;
            cout<<"Total population: "<<totalpopulation<<endl;
            cout<<"enter 'enter' to exit ussr viewing map and head back to menu...\n";
            cin.get();
            cin.ignore();
        }
        else if(user_pick == 'd' || user_pick == 'D')
        {
            break;
        }
        else
        {
            cout<<"That is not a choice"<<endl;
            cin.get();
            cin.ignore();
        }
    }
}



int main()
{
    system("clear");//change for windows
    //wargames();
    gamebegin();
    if( beginGame() == 1)
    {
        //ussr path
        while(true)
        {
            USSR_gameplay();
            if(cpu_totalpopulation <=0)
            {
                cout<<"USA has fallen, the motherland reins supreme!\n";
                cout<<"Player 1: USSR wins";
                return 0;
            }
            USA_gameplay();
            if(totalpopulation <= 0)
            {
                cout<<"Russia has collapsed, they can no longer fight\n";
                cout<<"Player 2: USA wins";
                return 0;
            }

        }
    }
    else
    {
        //usa path
        while(true)
        {
            USA_gameplay();
            if(totalpopulation <=0)
            {
                cout<<"Russia has collapsed, they can no longer fight\n";
                cout<<"Player 2: USA wins";
                return 0;
            }
            USSR_gameplay();
            if(cpu_totalpopulation <= 0)
            {
                cout<<"USA has fallen, the motherland reins supreme!\n";
                cout<<"Player 1: USSR wins";
                return 0;
            }

        }
    }
    
}
