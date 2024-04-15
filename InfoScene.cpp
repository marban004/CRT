#include "InfoScene.h"
#include <iostream>
#include <iomanip>
InfoScene::InfoScene() : Scene()
{

}

InfoScene::InfoScene(size_t Width, std::string Text) : InfoScene()
{
    SetSceneWidth(Width);
    SetSceneText(Text);
}

InfoScene::~InfoScene()
{
    //dtor
}

void InfoScene::ShowScene()
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

        std::cout << std::left << std::setfill(' ') << std::setw(SceneWidth - 1) << "|Wcisnij dowolny przycisk by kontynuowac" << "|" << std::endl;
        std::cout << std::left << std::setfill('-') << std::setw(SceneWidth - 1) << "+" << "+" << std::endl;
}

