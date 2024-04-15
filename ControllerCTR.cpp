#include "ControllerCTR.h"
#include "CongruenceEquation.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>

ControllerCTR::ControllerCTR() : Option(-1), Input(0), View(ViewCTR()), Model(ModelCTR())
{

}

ControllerCTR::~ControllerCTR()
{
    //dtor
}

int ControllerCTR::Start(std::map<int, Menu>* MenuMap)
{
    this -> RunMenu(1, MenuMap);
    return Option;
}

void ControllerCTR::RunMenu(int MenuNumber, std::map<int, Menu>* MenuMap)
{
    Option = -1;
    View.ShowMenu(MenuNumber, MenuMap);
    do
    {
        Input = getch();
        if (Input == -32)
        { // if the first value is esc
            //getch(); // skip the [
            switch(getch())
            { // the real value
                case 'H':
                    Option--;
                    if(!View.SetMenuOption(MenuNumber, Option, MenuMap))
                    {
                        Option++;
                    }
                    break;
                case 'P':
                    Option++;
                    if(!View.SetMenuOption(MenuNumber, Option, MenuMap))
                    {
                        Option--;
                    }
            }
        }
    }while (Input != 13 || Option < 0);

    //std::cout << "Selected option: " << std::to_string(Option);
}

bool ControllerCTR::SolveEquation(std::map<int, std::shared_ptr<Scene>>* SceneMap, std::list<CongruenceEquation>* EquationList, int* Solution, int* N)
{
    /*
    View.ShowScene(1, SceneMap);
    getch();
    */
    *Solution = 0;
    Model.LoadValues(EquationList);
    if(!Model.VerifyValues())
    {
        return false;
    }
    *Solution = Model.SolveEquation();
    *N = Model.GetN();
    return true;
}

void ControllerCTR::ShowSolution(std::map<int, std::shared_ptr<Scene>>* SceneMap)
{
    View.ShowScene(7, SceneMap);
    getch();
}

void ControllerCTR::ShowEquationError(std::map<int, std::shared_ptr<Scene>>* SceneMap)
{
    View.ShowScene(4, SceneMap);
    getch();
}

void ControllerCTR::Option1GetInput(std::map<int, std::shared_ptr<Scene>>* SceneMap, std::list<CongruenceEquation>* EquationList, std::map<int, Menu>* MenuMap)
{
    EquationList -> clear();

    CongruenceEquation Equation = CongruenceEquation(1, 0);

    GetCongruenceEquation(&Equation, SceneMap);
    EquationList -> push_back(Equation);

    GetCongruenceEquation(&Equation, SceneMap);
    EquationList -> push_back(Equation);

    this -> RunMenu(2, MenuMap);

    while(Option == 0)
    {
        GetCongruenceEquation(&Equation, SceneMap);
        EquationList -> push_back(Equation);
        this -> RunMenu(2, MenuMap);
    }
}


int ControllerCTR::GetValueInt()
{
    int Value = 0;
    std::stringstream ss1;
    std::string input = "";
    getline(std::cin, input, '\n');
    ss1 << input;
    ss1 >> Value;
    ss1.clear();
    ss1.str("");
    return Value;
}

void ControllerCTR::GetCongruenceEquation(CongruenceEquation* Equation, std::map<int, std::shared_ptr<Scene>>* SceneMap)
{
    while(true)
    {
        int Divisor = 0;
        int Rest = 0;
        int Value = 0;
        while(Value == 0)
        {
            View.ShowScene(1, SceneMap);
            Value = this -> GetValueInt();
            if (Value == 0)
            {
                View.ShowScene(5, SceneMap);
                getch();
            }
        }
        Divisor = Value;

        Value = 0;
        while(Value == 0)
        {
            View.ShowScene(2, SceneMap);
            Value = this -> GetValueInt();
            if (Value == 0)
            {
                View.ShowScene(5, SceneMap);
                getch();
            }
        }
        Rest = Value;

        if (Equation -> SetEquationContent(Divisor, Rest))
        {
            //std::cout << std::to_string(Equation -> GetDivisor()) + "-" + std::to_string(Equation -> GetRest()) << std::endl;
            //system("PAUSE");
            break;
        }

        View.ShowScene(6, SceneMap);
        getch();
    }
}
