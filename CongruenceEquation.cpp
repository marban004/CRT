#include "CongruenceEquation.h"

CongruenceEquation::CongruenceEquation(int Divisor, int Rest) : Divisor(1), Rest(0)
{
    SetEquationContent(Divisor, Rest);
}

CongruenceEquation::~CongruenceEquation()
{
    //dtor
}

bool CongruenceEquation::SetEquationContent(int Divisor, int Rest)
{
    if (Divisor < 1 || Rest < 0 || Rest >= Divisor)
    {
        return false;
    }
    this -> Divisor = Divisor;
    this -> Rest = Rest;
    return true;
}

int CongruenceEquation::GetDivisor()
{
    return Divisor;
}

int CongruenceEquation::GetRest()
{
    return Rest;
}
