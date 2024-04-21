#include "ModelCTR.h"
#include <cmath>

ModelCTR::ModelCTR() : X(0), N(0)
{
    //ctor
}

ModelCTR::~ModelCTR()
{
    //dtor
}

void ModelCTR::LoadValues(std::list<CongruenceEquation>* EquationList)
{
    //system("CLS");
    Divisors.clear();
    Rests.clear();
    for (auto it = EquationList -> begin(); it != EquationList -> end(); it++)
    {
        Divisors.push_back(it -> GetDivisor());
        Rests.push_back(it -> GetRest());
        //std::cout << "Rest appended = " << std::to_string(it -> GetRest()) << std::endl;
    }
    //system("PAUSE");
}

bool ModelCTR::VerifyValues()
{
    N = 1;
    int Divisor = 0;
    int M = 0;
    int Temp = 0;
    for (auto it1 = Divisors.begin(); it1 != Divisors.end(); it1++)
    {
        for (auto it2 = Divisors.begin(); it2 != Divisors.end(); it2++)
        {
            if(it1 == it2)
            {
                continue;
            }
            this -> ExtEuclideanAlg((*it1), (*it2), &Divisor, &M, &Temp);
            if(Divisor != 1)
            {
                return false;
            }
        }
        N *= (*it1);
    }
    return true;
}

int ModelCTR::SolveEquation()
{
//    system("CLS");
    int TempHoldingGCD = 0;
    int TempHoldingCM = 0;
    int TempHoldingM = 0;
    auto it2 = Rests.begin();
    for(auto it1 = Divisors.begin(); it1 != Divisors.end(); it1++)
    {
        this -> ExtEuclideanAlg((N / (*it1)), (*it1), &TempHoldingGCD, &TempHoldingCM, &TempHoldingM);
        /*
        NFactors.push_back((N / (*it));
        Ms.push_back(TempHoldingCM);
        */
        X += (*it2) * (N / (*it1)) * TempHoldingCM;
        //std::cout << "r = " + std::to_string(*it2) + " N = " + std::to_string((N / (*it1))) + " M = " + std::to_string(TempHoldingCM) << std::endl;
        it2++;
    }
    /*
    auto it2 = NFactors.begin();
    auto it3 = Ms.begin();
    X = 0;
    for(auto it1 = Rests.begin(); it1 != Rests.end(); it1++)
    {
        X += (*it1) * (*it2) * (*it3);
        it2++;
        it3++;
    }*/
    X = X % N;
    if(X < 0)
    {
        X += N;
    }
    /*
    TempHoldingCM = 1;
    for (it2 = Rests.begin(); it2 != Rests.end() ; it2++ )
    {
        TempHoldingCM *= *it2;
    }
    X += TempHoldingCM;
    system("PAUSE");*/

    return X;
}

bool ModelCTR::FactorizeFactorial(std::map<int, int>* FactorialFactorization, int Factorial)
{
    if(Factorial < 2)
    {
        return false;
    }
    FactorialFactorization -> clear();
    int CurrentPrimeNumber = 2;
    int CurrentPrimeNumberTemp = 2;
    int CurrentPrimeNumberExponent = 0;
    int TempHoldingVar = 0;
    do
    {
        CurrentPrimeNumberExponent = 0;
        CurrentPrimeNumberTemp = CurrentPrimeNumber;
        while((TempHoldingVar = Factorial/CurrentPrimeNumberTemp))
        {
            CurrentPrimeNumberExponent += TempHoldingVar;
            CurrentPrimeNumberTemp *= CurrentPrimeNumber;
        }
        FactorialFactorization -> insert(std::make_pair(CurrentPrimeNumber, CurrentPrimeNumberExponent));
        CurrentPrimeNumber = GetNextPrime(CurrentPrimeNumber);

    }
    while(CurrentPrimeNumber < Factorial);
    return true;
}

void ModelCTR::ExtEuclideanAlg(int a, int b, int* GCD, int* M, int* SM)
{
    int x = 1;
    int y = 0;
    int r = 0;
    int s = 1;
    int c = 0;
    int q = 0;
    int rp = 0;
    int sp = 0;
    while(b != 0)
    {
        c = a % b;
        q = a / b;
        a = b;
        b = c;

        rp = r;
        sp = s;
        r = x - q * r;
        s = y - q * s;
        x = rp;
        y = sp;
        //std::cout << "x = " + std::to_string(x) + " y = " + std::to_string(y) + " r = " + std::to_string(r) + " s = " + std::to_string(s) + " c = " + std::to_string(c) + " q = " + std::to_string(q) + " rp = " + std::to_string(rp) + " sp = " + std::to_string(sp) + "\n\n";
    }

    *GCD = a;
    *M = x;
    *SM = y;
}

bool ModelCTR::IsPrime(int Number)
{
bool Result = true;
int i;
for(i = 2; i <= (int)sqrt((double)Number); i ++)
    if (Number % i == 0)
        {
        Result = false;
        break;
        }
return Result;
}

int ModelCTR::GetNextPrime(int Prevprime)
{
int i;
for(i = Prevprime+1; /* !isPrime(i) */;i ++)
    if (IsPrime(i))
    {
        break;
    }
return i;
}

int ModelCTR::GetN()
{
    return N;
}
