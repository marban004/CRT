#pragma once
#ifndef MODELCTR_H
#define MODELCTR_H
#include "CongruenceEquation.h"
#include <list>

class ModelCTR
{
    public:
        ModelCTR();
        virtual ~ModelCTR();
        void LoadValues(std::list<CongruenceEquation>*);
        bool VerifyValues();
        int SolveEquation();
        int GetN();

    protected:

    private:
        void ExtEuclideanAlg(int, int, int*, int*, int*);
        std::list<int> Divisors;
        std::list<int> Rests;
        /*
        std::list<int> NFactors;
        std::list<int> Ms;
        std::list<long int> XSubstrats;
        */
        int X;
        int N;

};

#endif // MODELCTR_H
