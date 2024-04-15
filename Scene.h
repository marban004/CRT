#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <cstddef>
#include <string>
#include <windows.h>


class Scene
{
    public:
        Scene();
        virtual void ShowScene() = 0;
        virtual COORD GetCOORDForInput();
        virtual bool SetSceneWidth(size_t);
        virtual void SetSceneText(std::string);
    protected:
        size_t SceneWidth;
        size_t TextLines;
        std::string SceneText;
        virtual std::string SplitToLines(std::string);
        virtual size_t GetNumberOfLines(std::string);

};

#endif // SCENE_H
