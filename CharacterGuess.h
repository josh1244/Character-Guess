// CharacterGuess.h


#include <string>

/*
class Characters //class
{
    public:
    
    private:
};
*/

class Questions //class
{
    public:
    Questions( int x) { 
        question = x;
    }


    
    
    //Ask Question
   void AskQuestion(int x)
    {
        //std::cout << "2. " << dateName << " is "<< month << "/" << day << "/" << year << std::endl;
        //std::cout << "Is your character" << x << std::endl;
        if (x<50)
        {
            std::cout << questionArray[x] << std::endl;
        }
    }

    //Answer Question
   void AnswerQuestion(int w, int x)
   {
       recAnswerArray[x] = w;
        if (Marilyn_Monroe[x] == w) points[0] ++;
        if (Abraham_lincoln[x] == w) points[1] ++;
    }
   
   //Ask yes or no
    int yesNo()
    {
        std::cout << "Yes(y) or No(n)";
        getline(std::cin, answerS);
        if (answerS == "y")
        {
            answer = 1;
        }
        else if (answerS == "n")
        {
            answer = 0;
        }
        else
        {
            answer = -1;
        }

        return answer;
    }
    

    //Check Points
   std::string Checkpoints()
   {
        for (int i = 0; i < 10; i++) 
        {
            //std::cout << i << points[i] << std::endl;
            if (points[i] > highestPoints)
            {
                highestPoints = points[i];
                highestPointPerson = i;
            }
        }
        return people[highestPointPerson];
    }






    private:
    std::string answerS;
    int answer;
    int question;
    int highestPoints;
    int highestPointPerson;





    //array variables
    std::string people[2] = {"Marilyn Monroe", "Abraham Lincoln"};
    int points[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int Marilyn_Monroe[50] = {
    0, 1, 0, 0, 1,
    0, 1, 1, 0, 1, 
    0, 0, 0, 1, 0, 
    1, 1, 0, 0, 1, 
    0, 0, 0, 0, 0, 
    0, 0, 1, 0, 1,
    1, 0, 0, 0, 1,
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1};
    int Abraham_lincoln[50] = {
    1, 0, 0, 0, 0,
    0, 1, 1, 0, 1, 
    -1, 0, 1, 0, 0, 
    1, 1, 0, 1, 1 
    -1, 0, 0, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 0, 0, 0,
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1};
    std::string questionArray[50] = 
    {"Is their hair black?", 
    "Is their hair brown?", 
    "Is their hair blue?", 
    "Is their hair red?", 
    "Is their hair blonde?", 

    "Are their eyes blue?", 
    "Are their eyes brown?", 
    "Are their eyes hazel?", 
    "Are their eyes green?", 
    "Are they light skinned?",

    "Are they strong?",
    "Are they blind?", 
    "Are they tall?", 
    "Are they female?", 
    "Are they fictional?",

    "Are they famous?", 
    "Are they older than 20?", 
    "Are they younger than 20?", 
    "Are they older than 40?", 
    "Are they dead?",

    "Do they write?", 
    "Can they fly?",
    "Do they play games?", 
    "Do they play video games?", 
    "Are they computer smart?", 

    "Are they street smart?", 
    "Are they a YouTuber?", 
    "Do they live in the US?", 
    "Do they create music?", 
    "Are they from TV?", 

    "Are they an actor?", 
    "Do they  farm?",
    "Are they left handed?", 
    "Do they kill?",
    "Do they sing?", 

    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?", 
    "Are they Bob?"};
    //int questionAnswerArray[100] = { 0 };
    int recAnswerArray[50] = { 0 };

};