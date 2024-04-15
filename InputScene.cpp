#include "InputScene.h"
#include <iostream>
#include <iomanip>
InputScene::InputScene() : Scene()
{
    //ctor
}

InputScene::InputScene(size_t Width, std::string Text) : InputScene()
{
    SetSceneWidth(Width);
    SetSceneText(Text);
}

InputScene::~InputScene()
{
    //dtor
}

void InputScene::ShowScene()
{
        system("CLS");
        size_t StartPos = 0;
        std::string Line = "";

        std::cout << std::left << std::setfill('-') << std::setw(SceneWidth - 1) << "+" << "+" << std::endl;

        for (size_t i = 0; i < TextLines; i++)
        {
            Line = SceneText.substr(StartPos, SceneText.find("\n", StartPos) - StartPos);
            StartPos = SceneText.find("\n", StartPos) + 1;
            std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|" + Line << "|" << std::endl;
        }

        std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|Wpisz wartosc i kliknij enter: " << "|" << std::endl; //32, TextLines + 1
        std::cout << std::left << std::setfill('-') << std::setw(SceneWidth - 1) << "+" << "+" << std::endl;
}

COORD InputScene::GetCOORDForInput()
{
    return {32, TextLines + 1};
}
