#include "Menu.h"
#include <iostream>
#include <iomanip>

Menu::Menu() : MenuWidth(70), NumberOfBannerLines(0), Option(-1), MenuTitle("Menu"),  BannerText(""), u(GetStdHandle(STD_OUTPUT_HANDLE)), ConsoleWidth(80), ConsoleHeight(20), HighlitedOption(-1), TextColor(15), BackgroundColor(0), TotalLines(2)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(u, &csbi);
    ConsoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    ConsoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    TextColor = csbi.wAttributes % 16;
    BackgroundColor = (csbi.wAttributes - TextColor) / 16;
}

Menu::Menu(std::string Title) : Menu()
{
    Menu::SetMenuTitle(Title);
}

Menu::Menu(size_t Width) : Menu()
{
    Menu::SetMenuWidth(Width);
}

Menu::Menu(size_t Width, std::string Title) : Menu(Width)
{
    Menu::SetMenuTitle(Title);
}

Menu::~Menu()
{
    //dtor
}

int Menu::GetOption()
{
    return Option;
}

bool Menu::SetOption(int Option)
{
    if (Option >= 0 && Option < MenuElem.size())
    {
        this -> Option = Option;

        return true;
    }

    return false;
}

bool Menu::SetMenuWidth(size_t Width)
{
    if(Width > 2 && Width <= ConsoleWidth)
    {
        MenuWidth = Width;
        return true;
    }
    return false;
}

size_t Menu::GetMenuWidth()
{
    return MenuWidth;
}

bool Menu::SetMenuTitle(std::string Title)
{
    if (Title.length() <= (MenuWidth - 2))
    {
        MenuTitle = Title;
        return true;
    }
    return false;
}

std::string Menu::GetMenuTitle()
{
    return MenuTitle;
}

bool Menu::SetBannerText(std::string BannerText)
{
    TotalLines -= NumberOfBannerLines;
    if(BannerText.length() == 0)
    {
        this -> BannerText = "";
        NumberOfBannerLines = 0;
        TotalLines += NumberOfBannerLines;
        /*std::cout << "Banner has 0 lines" << std::endl;
        system("PAUSE");*/
        return true;
    }

    if(BannerText.length() <= (MenuWidth - 2) && (this -> GetNumberOfLines(BannerText)) == 0)
    {
        this -> BannerText = BannerText + "\n";
        NumberOfBannerLines = 1;
        TotalLines += NumberOfBannerLines;
        /*std::cout << "Banner has 1 line" << std::endl;
        system("PAUSE");*/
        return true;
    }

    this -> BannerText = this -> SplitToLines(BannerText);
    NumberOfBannerLines = this -> GetNumberOfLines(this -> BannerText);
    TotalLines += NumberOfBannerLines;
    /*std::cout << NumberOfBannerLines << std::endl;
    system("PAUSE");*/
    return true;
}
        std::string GetBannerText();

bool Menu::SetMenuColor(int TextColor, int BackgroundColor)
{
   if (TextColor >= 0 && TextColor <= 16 && BackgroundColor >= 0 && BackgroundColor <= 16)
   {
        SetConsoleTextAttribute(u, TextColor + 16 * BackgroundColor);
        this -> TextColor = TextColor;
        this -> BackgroundColor = BackgroundColor;
        return true;
   }
   return false;
}

bool Menu::AppendElement(std::string MenuOption)
{

    if(MenuOption.length() <= (MenuWidth - 2) && (this -> GetNumberOfLines(MenuOption)) == 0)
    {
        TotalLines++;
        if (TotalLines >= ConsoleHeight)
        {
            TotalLines--;
            return false;
        }
        MenuElem.push_back(MenuOption + "\n");
        MenuElemLength.push_back(1);
        return true;
    }
    /* Ignore below. Left just in case
    Needs finishing, currently checks if user inputed newlines are sufficient to divide menu text to fit inside menu.
    TempSearchString has portion of text that needs further dividing.
    While(true) is ugly, but currently there is no way of knowing how many newlines there are without redundant loops, so it has to stay.
    If StringOk == true, skip all other tests and append to list of menu options*/

    /*
    std::string ResultString = "";
    std::string TempSearchString = MenuOption;
    size_t SearchStartF = 0;
    size_t SearchStartR = 0;
    size_t MatchPosition = -1;
    size_t PotentialMatch = -1;
    bool StringOk = false;

    while(!StringOk)
    {
    size_t FirstNewline = TempSearchString.find("\n");

    if (FirstNewline == -1 || FirstNewline > (MenuWidth - 1))
    {
        break;
    }

    ResultString = ResultString + TempSearchString.substr(0, FirstNewline + 1);
    TempSearchString = TempSearchString.substr(FirstNewline + 1);

    if (TempSearchString.length() <= (MenuWidth - 2))
    {
        StringOk = true;
    }
    }
    */
    /* You can stop ignoring */

    /* Split string according to blank chars.
    Check how many newlines are in this string.*/

    MenuOption = this -> SplitToLines(MenuOption);
    int NumberOfOptionLines = this -> GetNumberOfLines(MenuOption);
    TotalLines += NumberOfOptionLines;
    if (TotalLines >= ConsoleHeight)
    {
        TotalLines -= NumberOfOptionLines;
        return false;
    }
    MenuElem.push_back(MenuOption);
    MenuElemLength.push_back(NumberOfOptionLines);

    return true;
}

/* Needs finishing. Add function that highlights selected option at the end.
Can try to clean up code a bit and optimize. Especially second for loop in for loop with iterators.*/
void Menu::ShowMenu()
{
    size_t StartPos = 0;
    std::string Line = "";
    system("CLS");
    HighlitedOption = -1;
    SetConsoleCursorPosition(u, {0, 0});
    std::cout << std::left << std::setfill('-') << std::setw(MenuWidth - 1) << "+" + MenuTitle << "+" << std::endl;

    for (int i = 0; i < NumberOfBannerLines; i++)
    {
        Line = BannerText.substr(StartPos, BannerText.find("\n", StartPos) - StartPos);
        StartPos = BannerText.find("\n", StartPos) + 1;
        std::cout << std::left << std::setfill(' ') << std::setw(MenuWidth - 1) << "|" + Line << "|" << std::endl;
    }

    auto it2 = MenuElemLength.begin();

    for (auto it1 = MenuElem.begin(); it1 != MenuElem.end(); it1++)
    {
        StartPos = 0;
        Line = "";

        for (int i = 0;i < (*it2); i++)
        {
            Line = it1 -> substr(StartPos, it1 -> find("\n", StartPos) - StartPos);
            StartPos = it1 -> find("\n", StartPos) + 1;
            std::cout << std::left << std::setfill(' ') << std::setw(MenuWidth - 1) << "|" + Line << "|" << std::endl;
        }
        it2++;
    }

    std::cout << std::left << std::setfill('-') << std::setw(MenuWidth - 1) << "+" << "+" << std::endl;
}

bool Menu::RefreshHighlight()
{
    if(Option == -1 || Option == HighlitedOption)
    {
        return true;
    }

    DWORD Written = 0;
    int LinesToScroll = 1 + NumberOfBannerLines;
    auto it = MenuElemLength.begin();

    for (int i = 0; i < HighlitedOption; i++)
    {
        LinesToScroll += (*it);
        it++;
    }

    for (int i = 0; i < (*it); i++)
    {
        FillConsoleOutputAttribute(u, TextColor + 16 * BackgroundColor, MenuWidth - 2, {1, LinesToScroll}, &Written);
        LinesToScroll++;
    }

    LinesToScroll = 1 + NumberOfBannerLines;
    it = MenuElemLength.begin();

    for (int i = 0; i < Option; i++)
    {
        LinesToScroll += (*it);
        it++;
    }

    for (int i = 0; i < (*it); i++)
    {
        FillConsoleOutputAttribute(u, BackgroundColor + 16 * TextColor, MenuWidth - 2, {1, LinesToScroll}, &Written);
        LinesToScroll++;
    }

    HighlitedOption = Option;

    return true;
}
/* Test version in test1 project.
Splits string first according to blank chars.
If string cannot be split (eg. string has no blank chars) splits to lines of length of menu - 4 and adds " -\n" after each line.
After last line adds "\n" automatically.*/
std::string Menu::SplitToLines(std::string TempSearchString)
{
    std::string ResultString = "";
    size_t PotentialMatch = 0;
    size_t SearchStartR = (MenuWidth - 2);          //Might be error, need to test. Also check lower lines, same situation.

    while(PotentialMatch != (size_t)-1)
    {
        PotentialMatch = TempSearchString.rfind("\n", SearchStartR);

        if (PotentialMatch == (size_t)-1)
        {
            PotentialMatch = TempSearchString.rfind((char)9, SearchStartR);
        }

        if (PotentialMatch == (size_t)-1)
        {
            PotentialMatch = TempSearchString.rfind((char)32, SearchStartR);
        }

        if (PotentialMatch != (size_t)-1 && PotentialMatch <= (MenuWidth - 2))
        {
            ResultString = ResultString + TempSearchString.substr(0, PotentialMatch) + "\n";
            TempSearchString = TempSearchString.substr(PotentialMatch + 1);
        }

        if (TempSearchString.length() <= (MenuWidth - 2))
        {
            ResultString = ResultString + TempSearchString + "\n";
            return ResultString;
        }
    }

    while(TempSearchString.length() > (MenuWidth - 2))
    {
        ResultString = ResultString + TempSearchString.substr(0, (MenuWidth - 4)) + " -\n";
        TempSearchString = TempSearchString.substr((MenuWidth - 4));
    }

    ResultString = ResultString + TempSearchString + "\n";

    return ResultString;
}

/* Possibly can be made more efficient.
Actually returns number of times "\n" is in string.*/
size_t Menu::GetNumberOfLines(std::string TempSearchString)
{
    size_t NumberOfLines = 0;
    size_t NewlinePos = 0;

    while(NewlinePos != (size_t)-1)
    {
        NewlinePos = TempSearchString.find("\n", NewlinePos);
        if(NewlinePos != (size_t)-1)
        {
        NumberOfLines++;
        NewlinePos++;
        }
        if (NewlinePos >= TempSearchString.length())
        {
        NewlinePos = -1;
        }
    }

    return NumberOfLines;
}
