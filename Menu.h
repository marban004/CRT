#pragma once
#ifndef MENU_H
#define MENU_H
#include <string>
#include <list>
#include <windows.h>

/* Only works if menu doesn't exceed console height.
If trying to attach option past console height AppendElement() returns false and doesn't append anything.*/
class Menu
{
    public:
        Menu();
        Menu(std::string);
        Menu(size_t);
        Menu(size_t, std::string);
        virtual ~Menu();
        int GetOption();
        bool SetOption(int);
        bool SetMenuWidth(size_t);
        size_t GetMenuWidth();
        bool SetMenuTitle(std::string);
        std::string GetMenuTitle();
        bool SetBannerText(std::string);
        std::string GetBannerText();
        bool SetMenuColor(int, int);
        bool AppendElement(std::string);
        void ShowMenu();
        bool RefreshHighlight();

    protected:

    private:
        std::list<size_t> MenuElemLength;
        std::list<std::string> MenuElem;
        size_t MenuWidth;
        size_t NumberOfBannerLines;
        int Option;
        std::string MenuTitle;
        std::string BannerText;
        HANDLE u;
        size_t ConsoleWidth;
        size_t ConsoleHeight;
        int HighlitedOption;
        int TextColor;
        int BackgroundColor;
        int TotalLines;

        std::string SplitToLines(std::string);
        size_t GetNumberOfLines(std::string);
};

#endif // MENU_H
