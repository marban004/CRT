#pragma once
#ifndef INFOSCENE_H
#define INFOSCENE_H
#include "Scene.h"
#include <string>

class InfoScene : public Scene
{
    public:
        InfoScene();
        InfoScene(size_t, std::string);
        virtual ~InfoScene();
        void ShowScene();

    protected:

    private:

};

#endif // INFOSCENE_H
