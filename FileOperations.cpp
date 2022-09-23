#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <vector>
#include "Player.h"
#include "FileOperations.h"
#include "Scoreboard.h"
#include "ScoreboardList.h"
#include "Weapon.h"
#include "WeaponsList.h"

using namespace std;
FileOperations::FileOperations() {}


/*We expect the player to be in the middle of the game, or after one of
their battles to save their stats. We want to save their progress we want to open their file,
and writing their current stats. It is not necessary to read for this function but just write*/
void FileOperations::Save2File(player& p, scoreboard& sb, WeaponsList& w)
{
    int i;
    cout << "Saving in progress..." << endl;

    //Now save all player's stats & floor + location, weaponsList
    P_myFile.seekg(0, ios::beg);    //takes cursor to the beginning. overwriting whatever was there before
    //Inputting all the player Class Private varibles into file
    P_myFile << p.getName() << '\n'
        << p.getMaxHP() << '\n'
        << p.getHP() << '\n'
        << p.getDMG() << '\n'
        << p.getMoney() << '\n'
        << sb.getName() << '\n'
        << sb.getScore() << '\n'
        << sb.getDifficulty() << '\n'
        << sb.getDifficultyMod() << '\n'
        << sb.getFloor() << endl;
    P_myFile << w.getWeaponsL().size() << endl;
    //Inputting the WeaponsL with their Item name, Damage, Price, Equpped and uses value
    for (i = 0; i < w.getWeaponsL().size(); i++)
    {
        P_myFile << i << endl;
        P_myFile << w.getWeapon(i).getItem() << endl;
        P_myFile << w.getWeapon(i).getDamage() << endl;
        P_myFile << w.getWeapon(i).getPrice() << endl;
        P_myFile << w.getWeapon(i).getEquipped() << endl;
        P_myFile << w.getWeapon(i).getUses() << endl;

    }
    cout << "Saving of player file done!" << endl;
}
/*Once this function is called we want the Players stats location and weaponList to be
saved the Player's file, over written by previous one*/

//Function which reads the scoreboard.txt and loads scoreboard into sl list
void FileOperations::ReadFile(ScoreboardList& sl)
{
    string name;
    int score;

    SB_myFile.seekg(0, ios::beg);
    while (!SB_myFile.eof())
    {
        SB_myFile >> name >> score;     //reads the file
        sl.insert(new scoreboard(name, score));     //writes it into a list
    }

}






//Function which sorts the scores and saves them in scoreboard file
void FileOperations::Save2File(scoreboard& sb)
{
    string name;
    int score;
    SB_myFile.seekg(0, ios::end);
    SB_myFile << sb.getName() << " " << sb.getScore() << '\n'; //writes in player name and player score in the scoreboard file
}




/*If the player has an existing file we want them to be able to start off where they left off in the game*/
void FileOperations::ChooseFile(scoreboard& sb, player& p, string name, WeaponsList& w) //opens the files and checks it if fails
{
    int i;
    //we get the name from the main 
    P_file_name = name + ".txt";
    //Checks if the file can be opened
    //Once we open the file, we need to check for opening errors 
    P_myFile.open(P_file_name);
    if (P_myFile) {
        cout << "Found file" << endl;
    }
    else if (P_myFile.fail())
    {
        cerr << "Could not open the file " << P_file_name << endl;
        exit(1);
    }

    //we create temp variables to hold all the variables vaules since we can not set the vaules
    string TName = " ", TSB_Difficulty = " ", TSB_Name = "";
    double TMaxHealth = 0, THealthPoints = 0, TAttackDamage = 0, Tcurrency = 0;
    int TSB_Score = 0, TSB_Difficulty_Mod = 0, TSB_Floor = 1;
    string Titem;
    int Tindex;
    int Tdamage;
    double Tprice;
    bool Tequipped;
    int Tuses;
    int size;

    P_myFile >> TName >> TMaxHealth >> THealthPoints >> TAttackDamage >> Tcurrency
        >> TSB_Name >> TSB_Score >> TSB_Difficulty >> TSB_Difficulty_Mod >> TSB_Floor;
    // we read the values from the file then we load the vaules into the game
    p.setName(TName);
    p.setMaxHP(TMaxHealth);
    p.setHP(THealthPoints);
    p.setDMG(TAttackDamage);
    p.setMoney(Tcurrency);
    sb.setName(TSB_Name);
    sb.setScore(TSB_Score);
    sb.setDifficultyMod(TSB_Difficulty_Mod);
    sb.setDifficulty(TSB_Difficulty);
    sb.setFloor(TSB_Floor);

    P_myFile >> size;
    
    for (i = 0; i < size; i++)
    {
        P_myFile >> Tindex >> Titem >> Tdamage >> Tprice >> Tequipped >> Tuses;
        w.addItem(Titem, Tdamage, Tprice, Tequipped, Tuses);
    }
    cout << "File has been chosen sucessfully" << endl;
}

//Function which creates a new player file
void FileOperations::Player(string name)
{
    P_file_name = name + ".txt";
    Po_myFile.open(P_file_name);    //creates a file
    cout << "File created." << endl;
    P_myFile.open(P_file_name);     //opens the fstream of the file
}

//Function which checks if a scoreboard exists
//Creates a new file if it does not exist
void FileOperations::Scoreboard(ScoreboardList& sl)
{
    SB_file_name = "scoreboard.txt";
    SB_myFile.open(SB_file_name);
    if (SB_myFile) {
        cout << "Found existing scoreboard!" << endl;
        ReadFile(sl);
    }
    else {
        SBO_myFile.open(SB_file_name);  //creates an output file called scoreboard.txt
        cout << "New scoreboard created!" << endl;
        SB_myFile.open(SB_file_name);
    }
}

//Function which closes all the files
void FileOperations::CloseFile()
{
    P_myFile.close();
    Po_myFile.close();
}