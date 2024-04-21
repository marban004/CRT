#pragma once
#ifndef RESULTSCENEFACTORIALFACTORIZATION_H
#define RESULTSCENEFACTORIALFACTORIZATION_H
#include "Scene.h"
#include <map>


class ResultSceneFactorialFactorization : public Scene
{
    public:
        ResultSceneFactorialFactorization(int, int*, std::map<int, int>*);
        virtual ~ResultSceneFactorialFactorization();
        bool SetNPointer(int*);
        bool SetFactorialFactorization(std::map<int, int>*);
        void ShowScene();

    protected:

    private:
        int* NPointer;
        std::map<int, int>* FactorialFactorizationPointer;
};

#endif // RESULTSCENEFACTORIALFACTORIZATION_H
