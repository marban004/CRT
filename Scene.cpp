#include "Scene.h"
Scene::Scene() :  SceneWidth(70), TextLines(2), SceneText("Information\n\n")
{

}

COORD Scene::GetCOORDForInput()
{
    return {-1, -1};
}

bool Scene::SetSceneWidth(size_t Width)
{
    if(Width > 70)
    {
        SceneWidth = Width;
        return true;
    }
    return false;
}

std::string Scene::SplitToLines(std::string TempSearchString)
{
    std::string ResultString = "";
    size_t PotentialMatch = 0;
    size_t SearchStartR = (SceneWidth - 2);          //Might be error, need to test. Also check lower lines, same situation.

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

        if (PotentialMatch != (size_t)-1 && PotentialMatch <= (SceneWidth - 2))
        {
            ResultString = ResultString + TempSearchString.substr(0, PotentialMatch) + "\n";
            TempSearchString = TempSearchString.substr(PotentialMatch + 1);
        }

        if (TempSearchString.length() <= (SceneWidth - 2))
        {
            ResultString = ResultString + TempSearchString + "\n";
            return ResultString;
        }
    }

    while(TempSearchString.length() > (SceneWidth - 2))
    {
        ResultString = ResultString + TempSearchString.substr(0, (SceneWidth - 4)) + " -\n";
        TempSearchString = TempSearchString.substr((SceneWidth - 4));
    }

    ResultString = ResultString + TempSearchString + "\n";

    return ResultString;
}

size_t Scene::GetNumberOfLines(std::string TempSearchString)
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

void Scene::SetSceneText(std::string Text)
{
    if (Text.length() <= SceneWidth - 2 && (this -> GetNumberOfLines(Text)) == 0)
    {
        SceneText = Text + "\n\n";
        TextLines = 2;
    }
    else
    {
        SceneText = SplitToLines(Text) + "\n";
        TextLines = GetNumberOfLines(SceneText);
    }
}
