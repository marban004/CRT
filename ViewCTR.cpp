#include "ViewCTR.h"
#include <iostream>

ViewCTR::ViewCTR() : u(GetStdHandle(STD_OUTPUT_HANDLE))
{
    SetConsoleTextAttribute(u, 15 + 16 * 1);
}

ViewCTR::~ViewCTR()
{
    //dtor
}

bool ViewCTR::SetMenuOption(int MenuNumber, int Option, std::map<int, Menu>* MenuMap)
{
    if((*MenuMap)[MenuNumber].SetOption(Option))
    {
        (*MenuMap)[MenuNumber].RefreshHighlight();
        return true;
    }
    return false;
}

void ViewCTR::ShowMenu(int MenuNumber, std::map<int, Menu>* MenuMap)
{
    system("CLS");
    (*MenuMap)[MenuNumber].ShowMenu();
}

void ViewCTR::ShowScene(int SceneNumber, std::map<int, std::shared_ptr<Scene>>* SceneMap)
{
    system("CLS");
    FlushConsoleInputBuffer(u);
    COORD InputPos = (*SceneMap)[SceneNumber] -> GetCOORDForInput();
    (*SceneMap)[SceneNumber] -> ShowScene();
    if(InputPos.X != -1 && InputPos.Y != -1)
        {
            SetConsoleCursorPosition(u, (*SceneMap)[SceneNumber] -> GetCOORDForInput());
        }
}
