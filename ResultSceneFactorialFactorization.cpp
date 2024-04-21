#include "ResultSceneFactorialFactorization.h"
#include <iostream>
#include <iomanip>

ResultSceneFactorialFactorization::ResultSceneFactorialFactorization(int Width, int* NPointer, std::map<int, int> *FactorialFactorizationPointer) :  NPointer(nullptr), FactorialFactorizationPointer(nullptr)
{
    SetSceneWidth(Width);
    SetFactorialFactorization(FactorialFactorizationPointer);
    SetNPointer(NPointer);
}


ResultSceneFactorialFactorization::~ResultSceneFactorialFactorization()
{
    //dtor
}

bool ResultSceneFactorialFactorization::SetFactorialFactorization(std::map<int, int>* FactorialFactorizationPointer)
{
    if (FactorialFactorizationPointer)
    {
        this -> FactorialFactorizationPointer = FactorialFactorizationPointer;
        return true;
    }
    return false;
}

bool ResultSceneFactorialFactorization::SetNPointer(int* NPointer)
{
    if (NPointer)
    {
        this -> NPointer = NPointer;
        return true;
    }
    return false;
}


void ResultSceneFactorialFactorization::ShowScene()
{
    std::cout << std::left << std::setfill('-') << std::setw(SceneWidth - 1) << "+Wynik" << "+" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|Rozklad !" + std::to_string(*NPointer) + " na czynniki pierwsze:" << "|" << std::endl;
    for (auto it = FactorialFactorizationPointer -> begin();it != FactorialFactorizationPointer -> end(); it++)
    {
        std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|" + std::to_string(it -> first) + " ^ " + std::to_string(it -> second) << "|" << std::endl;
    }
    std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|Wcisnij dowolny przycisk by kontynuowac" << "|" << std::endl;
    std::cout << std::left << std::setfill('-') << std::setw(SceneWidth - 1) << "+" << "+" << std::endl;
}
