// CharacterGuess.cpp
//Program to guess a character
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "CharacterGuess.h"


using namespace std;

int main() 
{
    //Variables
    int totQuestions{50};
    int questions{20};
    int questionNumb{0};
    int totQuestionsLeft{50};
    int randNumb{};
    string answerS{0};
    int answer{0};
    string person;
    //array variables
    int askedQuest[50] = { 0 };
    int arrayNumb{0};
    //loop variables
    int found{0}; //0 is empty, 1 is found
    bool reset{0};
    //Reset Loop
    do
    {


        
        //Variables
        totQuestions = 50;
        questions = 20;
        questionNumb = 0;
        totQuestionsLeft = 50;
        answer = 0;
        reset = 0;
        //array variables
        //std::fill_n(askedQuest, 100, 0);
        arrayNumb = 0;
        //loop variables
         found = 0; //0 is empty, 1 is found, 2 is not found
        


        Questions myQuest(questionNumb);


        //Think of a character
        cout << "Think of a character" << endl;

        //main loop
        do
        {  
            //Ask 20 questions about character
            //while loop
            while (questionNumb < questions)
            {
                //Display Question Number
                cout << "Question #" << questionNumb+1 << endl;
                
                //ask question
                


                //beginning of RND
                /* initialize random seed: */
                srand (time(0));
                do
                {    
                    //0 means there is nothing equal
                    //1 means there is at lease one equal
                    found = 0;

                    //generate random number
                    randNumb = rand() % 49 + 1;

                    //check if that number was generated yet
                    for(int i = 0; i < 49; i++)
                    {
                    //cout << "rnd: " << randNumb << "      asked" << i << ": " << askedQuest[i] << endl;
                        if(askedQuest[i] == randNumb)
                        {
                            //found
                            //generate a new numeber and repeat
                            found = 1;
                        }
                    }
                }//only continue if the question has not been asked
                while (found > 0);
                //End of RND

                //add random number to array so it does not get asked again
                askedQuest[arrayNumb] = randNumb;
                arrayNumb++;

                //Ask new random question
                //cout << randNumb;  //actual question number
                myQuest.AskQuestion(randNumb);
                //Answer the Question
                answer = myQuest.yesNo(); 

                //Assign varible based on question
                myQuest.AnswerQuestion(answer, randNumb);



                //Check characters and update their points







                //inc quest numb
                questionNumb++;
                totQuestionsLeft--;
                //cout << totQuestionsLeft;
            }
            //End of Question Loop
            //Reset Question Number
            
            questionNumb = 0;




            person = myQuest.Checkpoints();
            //Figure out which character has the most points
            //Is your Character _____?
            cout << "\n\n\nIs your character " << person << "?" << endl;
            answer = myQuest.yesNo(); 
            //If Yes, then win
            if (answer == 1)
            {
                //win
                cout << "Hooray! I guessed correctly!\n";
                break;
            } 
            else
            {
                if (totQuestionsLeft <= 0)
                {
                    cout << "It looks like I am out of question. You Win!\nWould you like to play again?\n";
                    answer = myQuest.yesNo(); 
                    if (answer == 1)
                    {
                        //Reset game!
                        reset=1;
                    }
                }
                else
                {
                    //Else Go back to Questions and ask 20 more
                    cout << "I guessed wrong?\nWould you like to keep going?";
                    answer = myQuest.yesNo(); 
                    if (answer == 0)
                    {
                        cout << "See you next time!\n";
                        break;
                    }
                }


            }
            //If Questions run out, then Lose
        }
        while (totQuestionsLeft > 0);
        //end of main loop

    //end of reset loop
    }
    while (reset == 1);
    









    //Veiw Asked Questions array
    /*S
    for(int i = 0; i < 50; i++){
        cout << askedQuest[i] << endl;
    }
    */

    return 0;
}


