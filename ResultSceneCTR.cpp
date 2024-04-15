#include "ResultSceneCTR.h"
#include <iostream>
#include <iomanip>

ResultSceneCTR::ResultSceneCTR(int Width, int* SolutionPointer, int* NPointer, std::list<CongruenceEquation> *EquationListPointer) : EquationListPointer(nullptr), SolutionPointer(nullptr), NPointer(nullptr), SceneWidth(70)
{
    SetSceneWidth(Width);
    SetSolutionPointer(SolutionPointer);
    SetEquationList(EquationListPointer);
    SetNPointer(NPointer);
}

ResultSceneCTR::~ResultSceneCTR()
{
    //dtor
}
void ResultSceneCTR::ShowScene()
{
    system("CLS");
    std::cout << std::left << std::setfill('-') << std::setw(SceneWidth - 1) << "+Rozwiazanie" << "+" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|Rozwiazanie tego ukladu kongruencji: " + std::to_string(*SolutionPointer) + " + (K * " + std::to_string(*NPointer) + ")" << "|" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|Gdzie K to liczba calkowita" << "|" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|Kongruencje tego ukladu kongruencji: " << "|" << std::endl;
    for(auto it = EquationListPointer -> begin(); it != EquationListPointer -> end(); it++)
    {
        std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|X mod " + std::to_string(it -> GetDivisor()) + " = " + std::to_string(it -> GetRest()) << "|" << std::endl;
    }
    std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|Wcisnij dowolny przycisk by kontynuowac" << "|" << std::endl;
    std::cout << std::left << std::setfill('-') << std::setw(SceneWidth - 1) << "+" << "+" << std::endl;
}

bool ResultSceneCTR::SetEquationList(std::list<CongruenceEquation>* EquationListPointer)
{
    if (!EquationListPointer)
    {
        return false;
    }
    this -> EquationListPointer = EquationListPointer;
    return true;
}

bool ResultSceneCTR::SetNPointer(int* NPointer)
{
    if (!NPointer)
    {
        return false;
    }
    this -> NPointer = NPointer;
    return true;
}

int ResultSceneCTR::GetSceneWidth()
{
    return SceneWidth;
}

bool ResultSceneCTR::SetSolutionPointer(int* SolutionPointer)
{
    if (!SolutionPointer)
    {
        return false;
    }
    this -> SolutionPointer = SolutionPointer;
    return true;
}
