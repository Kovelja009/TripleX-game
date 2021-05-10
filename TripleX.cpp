#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


using namespace std;


int CIAagents = 1;

void correct()
{
    string line;
    ifstream Fajlx ("correct.txt");
    while(getline(Fajlx, line)){
        cout << line;
        cout << "\n";
    }
    Fajlx.close();
}

void wrong()
{
    string line;
    ifstream Fajl ("wrong.txt");
    while(getline(Fajl, line)){
        cout << line;
        cout << "\n";
    }
}


void PrintIntroduction(int LevelDifficulty, string name)
{   
    std::cout << "\nHi " << name << ", your current floor is " << LevelDifficulty << " and you have to go to the top of the building.";
    std::cout << "\nDon't think that you are something special,\n";           
    std::cout << "because you are just an ordinary person with no extraordinary skills,\n";
    std::cout << "but I chose you regardless. Your task will be to hack into CIA and get\n";
    std::cout << "some highy classified info for me, nothing special. So let's jump onto your job!\n";    
}

bool PlayGame(int LevelDifficulty, string name)
{   
    PrintIntroduction(LevelDifficulty, name);
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\n";
    cout << "There are 3 numbers in the code\n";
    std::cout << "+ SUM of numbers is " << CodeSum << std::endl;
    std::cout << "+ Product of numbers is "<< CodeProduct << std::endl;
    
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum, GuessProduct;
    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        correct();
        std::cout << "\n";
        return true;
    }
    else{
        wrong();
        std::cout << "\nWrong answer!\n";
        if(CIAagents == 1){
            cout << "You have 1 CIA agent behind your back. Be careful!\n";
        }else{
            cout << "You have " << CIAagents << " CIA agents behind your back. Pay more attention!\n";
        }

        CIAagents++;
        return false;
    }

    return 1;
}

void ReiAyanami()
{   cout << "\n";
    string my_line;
    
    ifstream Fajl ("code_art.txt");

    while( getline (Fajl,my_line)){
        cout << my_line;
        cout << "\n";
    }
    Fajl.close();
}

int main() 
{   
    ReiAyanami();
    
    string name;
    cout << "Rei asks you to enter the name: ";

    cin >> name;
    int LevelDifficulty = 1;
    const int MaxLevel = 7;
    srand(time(NULL));

    while(LevelDifficulty <= MaxLevel){
        if (CIAagents > 3){
            cout << "Game over...\n";
            cout << "You are caught by the CIA agents!\n";
            return 0;
        }
        

        bool bLevelComplete = PlayGame(LevelDifficulty, name);
        cin.clear();
        cin.ignore();

        if(bLevelComplete){
            LevelDifficulty++;
        }
    }
    
    cout << "\nCongratulations " << name << ", you have finished the game.\n";
    cout << "But don't think that you are something special,\n";
    cout << "just because you have hacked into CIA headquarters!\n";
    
    
    return 0;
}