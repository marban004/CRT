#pragma once
#ifndef CONGRUENCEEQUATION_H
#define CONGRUENCEEQUATION_H


class CongruenceEquation
{
    public:
        CongruenceEquation(int, int);
        virtual ~CongruenceEquation();
        bool SetEquationContent(int, int);
        int GetDivisor();
        int GetRest();

    protected:

    private:
        int Divisor;
        int Rest;
};

#endif // CONGRUENCEEQUATION_H
