#pragma once
#ifndef CONTROLLERCTR_H
#define CONTROLLERCTR_H
#include "ViewCTR.h"
#include "CongruenceEquation.h"
#include "ModelCTR.h"


class ControllerCTR
{
    public:
        ControllerCTR();
        virtual ~ControllerCTR();
        int Start(std::map<int, Menu>* MenuMap);
        void SolveEquation(std::map<int, std::shared_ptr<Scene>>*, std::list<CongruenceEquation>*);
        void Option1GetInput(std::map<int, std::shared_ptr<Scene>>*, std::list<CongruenceEquation>*, std::map<int, Menu>*);
        bool Option2GetInput(std::map<int, std::shared_ptr<Scene>>*, int*, std::map<int, int>*);
        bool SolveEquation(std::map<int, std::shared_ptr<Scene>>*, std::list<CongruenceEquation>*, int*, int*);
        void ShowSolution(std::map<int, std::shared_ptr<Scene>>*);
        void ShowFactorialFactorization(std::map<int, std::shared_ptr<Scene>>*);
        void ShowFactorialFactorizationError(std::map<int, std::shared_ptr<Scene>>*);
        void ShowEquationError(std::map<int, std::shared_ptr<Scene>>*);

    protected:

    private:
        int Option;
        char Input;
        ViewCTR View;
        ModelCTR Model;

        void RunMenu(int, std::map<int, Menu>*);
        int GetValueInt();
        void GetCongruenceEquation(CongruenceEquation*, std::map<int, std::shared_ptr<Scene>>*);
};

#endif // CONTROLLERCTR_H
