#pragma once
#ifndef VIEWCTR_H
#define VIEWCTR_H
#include "Menu.h"
#include "Scene.h"
#include <map>
#include <memory>

class ViewCTR
{
    public:
        ViewCTR();
        virtual ~ViewCTR();
        bool SetMenuOption(int, int, std::map<int, Menu>* MenuMap);
        void ShowMenu(int, std::map<int, Menu>*);
        void ShowScene(int, std::map<int, std::shared_ptr<Scene>>*);

    protected:

    private:
        HANDLE u;
};

#endif // VIEWCTR_H
