//Name: Danielle Lewis
//File Name: prog4.cpp
//Date: 11-11-14
//Program Description:
//The Cop and the Burglar
//experience with queues and templates.

# include <iostream>
# include "Queue.h"
# include <fstream>
# include <string>
# include <cstdlib>
using namespace std;

bool isMatched(int knowList[], int suspectList[]);

int main (void)
{
string friendList[26];
char tempChar[20];
int knowList[26]={1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int suspectList[26]={0};
int n = 0;
int contact;
char temp;
ifstream inFile;


inFile.open("friends.txt");
if (inFile.fail())
   {
   cout<< "Error opening file" << endl;
   exit (1);
   }

// populates my array of strings from the file
int f = 0;
while(inFile.peek() != EOF)
//for(int f = 0; f < 26; f++)
    {
    std::getline(inFile,friendList[f], '\n');
    //inFile.getline(tempChar, 20, '\r');
    inFile>>ws;
    //friendList[f] = string(tempChar);
    f++;
    }

Queue<char> ql;
// loop to interrogate each suspect
//int k is the kth position of each string
for(int s = 0; s < 26; s++)
    {
    for(int c = 0; c <26; c++)
        suspectList[c]= 0;
    //ql.enqueue(friendList[s][0]);
    ql.enqueue(s + 'A');

    while(!ql.isEmpty()) //!= false)
        {
        ql.dequeue(temp);
        n = temp - 'A';
        suspectList[s] = 1; // mark the person as knows
        int len = friendList[n].length();
        for(int k = 0; k < len; k = k+2)
            {
            contact = friendList[n][k];
            if(contact != ' ' && suspectList[contact - 'A'] != 1)
                {
                suspectList[contact - 'A'] = 1;
                ql.enqueue(friendList[n][k]);
                } // end of if
            } // end of for
        } // end of while
        //isMatched(knowList, suspectList);
        if(isMatched(knowList, suspectList))
        {
            char answer = s + 'A';
           cout<<"I know who the burglar is, it is "<< answer <<"."<<endl;
            //exit (1);
        }
    } // end of for
} // end of main


//==================================
bool isMatched(int knowList[], int suspectList[])
{
// loop to compare arrays
 /*   int p = 0;
    bool misMatched = false;
    while(p < 26 && !misMatched)
        {

         if(knowList[p] == suspectList[p])
            p++;
         else
            {
            misMatched = true;
            return false;
            }
    if (!misMatched)
    {
        return true;}
    //return !misMatched;*/
//}
for(int p = 0; p < 26; p++)
    {if(knowList[p]!=suspectList[p])
        return false;}

        return true;
}

