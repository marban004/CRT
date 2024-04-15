#pragma once
#ifndef INPUTSCENE_H
#define INPUTSCENE_H
#include "Scene.h"
#include <string>

class InputScene : public Scene
{
    public:
        InputScene();
        InputScene(size_t, std::string);
        virtual ~InputScene();
        void ShowScene();
        COORD GetCOORDForInput();

    protected:

    private:
};

#endif // INPUTSCENE_H
