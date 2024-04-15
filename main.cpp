#include "ControllerCTR.h"
#include "Menu.h"
#include "Scene.h"
#include "CongruenceEquation.h"
#include "ResultSceneCTR.h"
#include "InfoScene.h"
#include "InputScene.h"
#include <memory>



int main()
{
    /*
    Menu menu1 = Menu(80, "Testowe Menu");
    menu1.SetBannerText("Multi line text to check if splitting to lines works.\n");
    for (int i = 0; i < 9; i++)
    {
        menu1.AppendElement("Option " + std::to_string(i + 1) + "\n");
    }
    menu1.AppendElement("Arbitrarily long option 11 to test if SplitToLines() function works. I have no idea how long do I have to make this to take up more than 1 line. Hopefully this length will be enough\n");
    menu1.ShowMenu();

    int Option = -1;
    char Input = 0;
    do
    {
        Input = getch();
        if (Input == -32)
        { // if the first value is esc
            //getch(); // skip the [
            switch(getch())
            { // the real value
                case 'H':
                    Option--;
                    if(!menu1.SetOption(Option))
                    {
                        Option++;
                    }
                    menu1.RefreshHighlit();
                    break;
                case 'P':
                    Option++;
                    if(!menu1.SetOption(Option))
                    {
                        Option--;
                    }
                    menu1.RefreshHighlit();
            }
        }
    }while (Input != 13 || Option < 0);
    std::cout << "Selected option: " << std::to_string(Option);*/
    /*
    menu1.SetOption(9);
    menu1.RefreshHighlit();
    system("PAUSE");

    menu1.RefreshHighlit();
    system("PAUSE");

    menu1.SetOption(0);
    menu1.RefreshHighlit();
    system("PAUSE");*/
    ControllerCTR Controller = ControllerCTR();
    const int AppWidth = 80;
    int Option = -1;
    int Solution = 0;
    int N = 0;
    std::map<int, Menu> MenuMap;
    std::map<int, std::shared_ptr<Scene>> SceneMap;
    std::list<CongruenceEquation> EquationList;
    std::shared_ptr<Scene> Scene;

    /*
    Scene.reset(new InputScene(AppWidth, "Podaj maksymalna wartosc liczby X"));
    SceneMap.insert(std::make_pair(1, Scene));*/

    Scene.reset(new InputScene(AppWidth, "Podaj podzielnik kongruencji"));
    SceneMap.insert(std::make_pair(1, Scene));

    Scene.reset(new InputScene(AppWidth, "Podaj reszte kongruencji"));
    SceneMap.insert(std::make_pair(2, Scene));

    /*
    Scene.reset(new InfoScene(AppWidth, "To rownanie jest sprzeczne i nie ma rozwiazan"));
    SceneMap.insert(std::make_pair(3, Scene));
    */

    Scene.reset(new InfoScene(AppWidth, "Podane podzielniki nie sa wzglednie pierwsze"));
    SceneMap.insert(std::make_pair(4, Scene));

    Scene.reset(new InfoScene(AppWidth, "Podano niepoprawna wartosc"));
    SceneMap.insert(std::make_pair(5, Scene));

    Scene.reset(new InfoScene(AppWidth, "Podano niepoprawna kongruencje"));
    SceneMap.insert(std::make_pair(6, Scene));

    Scene.reset(new ResultSceneCTR(AppWidth, &Solution, &N, &EquationList));
    SceneMap.insert(std::make_pair(7, Scene));

    MenuMap.insert(std::make_pair(1, Menu(AppWidth, "Menu glowne")));
    MenuMap[1].AppendElement("* Chinskie twierdzenie o resztach");
    MenuMap[1].AppendElement("* Wyjdz");

    MenuMap.insert(std::make_pair(2, Menu(AppWidth, "")));
    MenuMap[2].SetBannerText("Czy podac nastepna kongruencje?");
    MenuMap[2].AppendElement("* Tak");
    MenuMap[2].AppendElement("* Nie");



    while(((Option = Controller.Start(&MenuMap)) != 1))
    {

    switch (Option)
    {
    case 0:
        Controller.Option1GetInput(&SceneMap, &EquationList, &MenuMap);
        if(Controller.SolveEquation(&SceneMap, &EquationList, &Solution, &N))
        {
            Controller.ShowSolution(&SceneMap);
        }
        else
        {
            Controller.ShowEquationError(&SceneMap);
        }
        break;

    case 1:
        break;

    default:
        break;
    }
    };

    return 0;
}
