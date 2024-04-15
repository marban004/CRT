#pragma once
#ifndef RESULTSCENECTR_H
#define RESULTSCENECTR_H
#include "Scene.h"
#include "CongruenceEquation.h"
#include <list>

class ResultSceneCTR : public Scene
{
    public:
        ResultSceneCTR(int, int*, int*, std::list<CongruenceEquation>*);
        virtual ~ResultSceneCTR();
        void ShowScene();
        bool SetEquationList(std::list<CongruenceEquation>*);
        int GetSceneWidth();
        bool SetSolutionPointer(int*);
        bool SetNPointer(int*);

    protected:

    private:
        std::list<CongruenceEquation>* EquationListPointer;
        int* SolutionPointer;
        int* NPointer;
        size_t SceneWidth;
};

#endif // RESULTSCENECTR_H
