// CharacterGuess.cpp
//Program to guess a character
#include <iostream>
#include <string>
#include <cstdlib>
#include "CharacterGuess.h"


using namespace std;


int main() 
{



    //Variables
    int totQuestions{100};
    int questions{20};
    int questionNumb{0};
    int totQuestionsLeft{100};
    int randNumb{};
    string answerS{0};
    int answer{0};
    //array variables
    int askedQuest[100] = { 0 };
    int arrayNumb{0};
    //loop variables
    int found{0}; //0 is empty, 1 is found, 2 is not found

    Questions myQuest(questionNumb);


    //Think of a character
    cout << "Think of a character" << endl;

    do
    {  

        //Ask 20 questions about character
            //while loop
        while (questionNumb < questions)
        {
            //Display Question Number
            cout << "Question #" << questionNumb+1 << endl;
            
            //ask question
            




            do
            {    
                //generate random number
                randNumb = rand() % 100 + 1;

                //check if that number was generated yet
                for(int i = 0; i < 100; i++)
                {
                                             cout << "rnd: " << randNumb << "      asked" << i << ": " << askedQuest << endl;

                    if(askedQuest[i] == randNumb)
                    {
                        //found
                        //generate a new numeber and repeat
                        found = 1;
                    }
                    else
                    {
                        //not found
                        
                        found = 2;
                    }
                }
            }
            while (found < 2);

            //add random number to array so it does not get asked again
            askedQuest[arrayNumb] = randNumb;
            arrayNumb++;

            //Ask new random question
            myQuest.AskQuestion(randNumb);
            //Answer the Question
            answer = myQuest.yesNo(); 

            //Assign varible based on question
            myQuest.AnswerQuestion(answer, randNumb);



            //Check characters and update their points







            questionNumb++;
            totQuestionsLeft--;
            cout << totQuestionsLeft;
        }
        //End of Question Loop
        //Reset Question Number
        questionNumb = 0;





        //Figure out which character has the most points
        //Is your Character _____?
        cout << "\n\n\nIs your character" << "Charcter with highest points" << "?" << endl;
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
            if (totQuestionsLeft > 0)
            {
                cout << "It looks like I am out of question. You Win!\nWould you like to try again?\n";
                answer = myQuest.yesNo(); 
                if (answer == 1)
                {
                    //Reset game!
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










    //Veiw Asked Questions array
    /*
    for(int i = 0; i < 100; i++){
        cout << askedQuest[i] << endl;
    }
    */

    return 0;
}



/*
int main() 
{
    //init variables
    string theName;
    int month;
    int day;
    int year;

    Date myDate(theName ,month ,day ,year);
    Date myDate2(theName ,month ,day ,year);


    //input names and dates

//set the name of the first date
    cout << "Please enter first date name:";
   cin >> theName;
   myDate.setDateName(theName); // adds theName into myDate

//Set the first date
    cout << "Please enter first date (dd mm yyyy): ";
    cin >> month >> day >> year;
   myDate.setMonth(month); // sets the month
   myDate.setDay(day); // sets the day
   myDate.setYear(year); // sets the year


//set the name of the second date
    cout << "Please enter second date name:";
   cin >> theName;
   myDate2.setDateName(theName); // adds theName into myDate2

//Set the second date
    cout << "Please enter second date (dd mm yyyy): ";
    cin >> month >> day >> year;
   myDate2.setMonth(month); // sets the month
   myDate2.setDay(day); // sets the day
   myDate2.setYear(year); // sets the year


    //display the dates back

//Use displayDate to show the date
 myDate.displayDate();
myDate2.displayDate();


    return 0;
}
*/