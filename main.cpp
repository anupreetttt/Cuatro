#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
using namespace std;

char A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16;
string UPPER_PIECE = "OO/CC  II/ZZ";
string LOWER_PIECE = "oo/cc  ii/zz";

void DISPLAY_INSTRUCTION();
void DISPLAY_BOARD();
void PLAY(char &,int &,int &);
void MOVE_PIECE(int,int,int &);
void WINNERNER_CHECK(int);

int main()
{
    string ENTER="";
    int WINNER=0;
    int MAKE_MOVE=1;
    int ENTER_INT;
    char ENTER_CHAR;
    DISPLAY_INSTRUCTION();
    DISPLAY_BOARD();
    for (int MAKE_MOVE=1;MAKE_MOVE<=16; MAKE_MOVE++)
    {
     PLAY(ENTER_CHAR, ENTER_INT,MAKE_MOVE);
     MOVE_PIECE(ENTER_CHAR, ENTER_INT,MAKE_MOVE);
     WINNERNER_CHECK(MAKE_MOVE);
     DISPLAY_BOARD();
    }
    return 0;
}

void DISPLAY_INSTRUCTION()
{
    A1=A2=A3=A4=A5=A6=A7=A8=A9=A10=A11=A12=A13=A14=A15=A16='.';
    cout << "Welcome to the game of Cuatro, where you try to complete a set      \n"
         << "of four pieces that are alike.  Players take turns making moves.    \n"
         << "On each move your OPPONENT chooses the piece, then YOU get to       \n"
         << "place it on the board.  If you create a set of four alike when      \n"
         << "you place your piece, then you win!       \n"
         << "\n"
         << "A set of four alike can be completed by using four all upper (or all\n"
         << "lower) case characters, four all vowels (or all consonants), or four\n"
         << "all curved (or all straight-lined). Curved letters are 'O' and 'C'\n"
         << "(upper or lower), and straight-line letters are 'I' and 'Z' (upper or\n"
         << "lower). Groups of four can be created in a row, column, diagonal, or\n"
         << "corner quadrant.\n"
         << "\n"
         << "When prompted for input you may also enter 'x' or 'X' to exit." << endl;
}

void DISPLAY_BOARD()
{
   cout<<" ---------    Square #   "<<endl;
   cout<<"|"<<" "<<A1<<" "<<A2<<" "<<A3<<" "<<A4<<" "<<"|"<<"  1  2  3  4  "<<endl;
   cout<<"|"<<" "<<A5<<" "<<A6<<" "<<A7<<" "<<A8<<" "<<"|"<<"  5  6  7  8  "<<endl;
   cout<<"|"<<" "<<A9<<" "<<A10<<" "<<A11<<" "<<A12<<" "<<"|"<<"  9 10 11 12  "<<endl;
   cout<<"|"<<" "<<A13<<" "<<A14<<" "<<A15<<" "<<A16<<" "<<"|"<<" 13 14 15 16  "<<endl;
   cout<<" --------- "<<endl;
   cout<<"Pieces:     Curved Straight                "<<endl;
   cout<<"      Upper:  "<<UPPER_PIECE<<endl;
   cout<<"      Lower: "<<LOWER_PIECE<<endl;
   cout<<"            Vowel/Consonant  "<<endl;
}

void PLAY( char &ENTER_CHAR , int &ENTER_INT,int &MAKE_MOVE)
{
   if (MAKE_MOVE%2==0)
  {
   cout<<MAKE_MOVE<<". Player 2 enter piece, and Player 1 enter destination:";
   cin>>ENTER_CHAR;
   if (ENTER_CHAR=='X'|| ENTER_CHAR=='x'){
   cout<<"Exiting program...";
   exit(0);}
   cin>>ENTER_INT;
  }
   else
  {
   cout<<MAKE_MOVE<<". Player 1 enter piece, and Player 2 enter destination:";
   cin>>ENTER_CHAR;
   if (ENTER_CHAR=='X'|| ENTER_CHAR=='x'){
   cout<<"Exiting program...";
   exit(0);}
   cin>>ENTER_INT;
  }
}

void MOVE_PIECE(int ENTER_CHAR, int ENTER_INT, int& MAKE_MOVE)
{
   for (int i=0; i<12;i++)
    {
     if ((ENTER_INT>16)||(ENTER_INT<1))
     {
         cout<<"*** Sorry, that destination is invalid.  Please retry."<<endl;
      MAKE_MOVE=MAKE_MOVE-1;
      break;
     }
    else if ((UPPER_PIECE.find(ENTER_CHAR)>12)&&(LOWER_PIECE.find(ENTER_CHAR)>12))
     {
      cout<<"*** Sorry, that is an invalid piece.  Please retry."<<endl;
         ENTER_CHAR='.';
         MAKE_MOVE=MAKE_MOVE-1;
         break;
     }
    else if (UPPER_PIECE[i]==ENTER_CHAR)
     {
      UPPER_PIECE[i]=' ';
      break;
     }
    else if(LOWER_PIECE[i]==ENTER_CHAR)
     {
      LOWER_PIECE[i]=' ';
      break;
     }
    }
switch (ENTER_INT)
    {
     case 1: if (A1!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A1 = ENTER_CHAR;
               break;
              }
     case 2: if (A2!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A2 = ENTER_CHAR;
               break;
              }
     case 3: if (A3!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A3 = ENTER_CHAR;
               break;
              }
     case 4: if (A4!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A4 = ENTER_CHAR;
               break;
              }
     case 5: if (A5!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A5 = ENTER_CHAR; break;
              }
     case 6: if (A6!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A6 = ENTER_CHAR;
               break;
              }
     case 7: if (A7!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A7 = ENTER_CHAR;
               break;
              }
     case 8: if (A8!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A8 = ENTER_CHAR;
               break;
              }
     case 9: if (A9!='.')
              {
               cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
               MAKE_MOVE=MAKE_MOVE-1;
               break;
              }
             else
              {
               A9 = ENTER_CHAR;
               break;
              }
     case 10: if (A10!='.')
               {
                cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
                MAKE_MOVE=MAKE_MOVE-1;
                break;
               }
             else
               {
                A10 = ENTER_CHAR;
                break;
               }
     case 11: if (A11!='.')
               {
                cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
                MAKE_MOVE=MAKE_MOVE-1;
                break;
               }
             else
               {
                A11 = ENTER_CHAR;
                break;
               }
     case 12: if (A12!='.')
               {
                cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
                MAKE_MOVE=MAKE_MOVE-1;
                break;
               }
             else
               {
                A12 = ENTER_CHAR;
                break;
               }
     case 13: if (A13!='.')
               {
                cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
                MAKE_MOVE=MAKE_MOVE-1;
                break;
               }
             else
               {
                A13 = ENTER_CHAR;
                break;
               }
     case 14: if (A14!='.')
               {
                cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
                MAKE_MOVE=MAKE_MOVE-1;
                break;
               }
             else
               {
                A14 = ENTER_CHAR;
                break;
               }
     case 15: if (A15!='.')
               {
                cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
                MAKE_MOVE=MAKE_MOVE-1;
                break;
               }
             else
               {
                A15 = ENTER_CHAR;
                break;
               }
     case 16: if (A16!='.')
               {
                cout<<"\n*** Sorry, that destination is occupied.  Please retry."<<endl;
                MAKE_MOVE=MAKE_MOVE-1;
                break;
               }
             else
               {
                A16 = ENTER_CHAR;
                break;
               }
            }
}
void WINNERNER_CHECK(int MAKE_MOVE)
   {
    if(((A1=='C' || A1=='O'|| A1=='I'||A1=='Z')&&(A2=='C' || A2=='O'|| A2=='I'||A2=='Z')&&(A3=='C' || A3=='O'|| A3=='I'||A3=='Z')&&(A4=='C' || A4=='O'|| A4=='I'||A4=='Z'))||
       ((A5=='C' || A5=='O'|| A5=='I'||A5=='Z')&&(A2=='C' || A2=='O'|| A2=='I'||A2=='Z')&&(A1=='C' || A1=='O'|| A1=='I'||A1=='Z')&&(A6=='C' || A6=='O'|| A6=='I'||A6=='Z'))||
       ((A5=='C' || A5=='O'|| A5=='I'||A5=='Z')&&(A6=='C' || A6=='O'|| A6=='I'||A6=='Z')&&(A7=='C' || A7=='O'|| A7=='I'||A7=='Z')&&(A8=='C' || A8=='O'|| A8=='I'||A8=='Z'))||
       ((A9=='C' || A9=='O'|| A9=='I'||A9=='Z')&&(A10=='C' || A10=='O'|| A10=='I'||A10=='Z')&&(A11=='C' || A11=='O'|| A11=='I'||A11=='Z')&&(A12=='C' || A12=='O'|| A12=='I'||A12=='Z'))||
       ((A13=='C' || A13=='O'|| A13=='I'||A13=='Z')&&(A14=='C' || A14=='O'|| A14=='I'||A14=='Z')&&(15=='C' || A15=='O'|| A15=='I'||A15=='Z')&&(A16=='C' || A16=='O'|| A16=='I'||A16=='Z'))||
       ((A13=='C' || A13=='O'|| A13=='I'||A13=='Z')&&(A10=='C' || A10=='O'|| A10=='I'||A10=='Z')&&(A7=='C' || A7=='O'|| A7=='I'||A7=='Z')&&(A4=='C' || A4=='O'|| A4=='I'||A4=='Z'))||
       ((A1=='C' || A1=='O'|| A1=='I'||A1=='Z')&&(A6=='C' || A6=='O'|| A6=='I'||A6=='Z')&&(11=='C' || A11=='O'|| A11=='I'||A11=='Z')&&(A16=='C' || A16=='O'|| A16=='I'||A16=='Z'))||
       ((A1=='C' || A1=='O'|| A1=='I'||A1=='Z')&&(A5=='C' || A5=='O'|| A5=='I'||A5=='Z')&&(A9=='C' || A9=='O'|| A9=='I'||A9=='Z')&&(A13=='C' || A13=='O'|| A13=='I'||A13=='Z'))||
       ((A2=='C' || A2=='O'|| A2=='I'||A2=='Z')&&(A6=='C' || A6=='O'|| A6=='I'||A6=='Z')&&(A10=='C' || A10=='O'|| A10=='I'||A10=='Z')&&(A14=='C' || A14=='O'|| A14=='I'||A14=='Z'))||
       ((A3=='C' || A3=='O'|| A3=='I'||A3=='Z')&&(A7=='C' || A7=='O'|| A7=='I'||A7=='Z')&&(11=='C' || A11=='O'|| A11=='I'||A11=='Z')&&(A15=='C' || A15=='O'|| A15=='I'||A15=='Z'))||
       ((A4=='C' || A4=='O'|| A4=='I'||A4=='Z')&&(A8=='C' || A8=='O'|| A8=='I'||A8=='Z')&&(A12=='C' || A12=='O'|| A12=='I'||A12=='Z')&&(A16=='C' || A16=='O'|| A16=='I'||A16=='Z'))||
       ((A3=='C' || A3=='O'|| A3=='I'||A3=='Z')&&(A4=='C' || A4=='O'|| A4=='I'||A4=='Z')&&(7=='C' || A7=='O'|| A7=='I'||A7=='Z')&&(A8=='C' || A8=='O'|| A8=='I'||A8=='Z'))||
       ((A9=='C' || A9=='O'|| A9=='I'||A9=='Z')&&(A10=='C' || A10=='O'|| A10=='I'||A10=='Z')&&(A13=='C' || A13=='O'|| A13=='I'||A13=='Z')&&(A14=='C' || A14=='O'|| A14=='I'||A14=='Z'))||
       ((A11=='C' || A11=='O'| A11=='I'||A11=='Z')&&(A12=='C' || A12=='O'|| A12=='I'||A12=='Z')&&(A15=='C' || A15=='O'|| A15=='I'||A15=='Z')&&(A16=='C' || A16=='O'|| A16=='I'||A16=='Z'))||
       ((A1=='c' || A1=='o'|| A1=='i'||A1=='z')&&(A2=='c' || A2=='o'|| A2=='i'||A2=='z')&&(A3=='c' || A3=='o'|| A3=='i'||A3=='z')&&(A4=='c' || A4=='o'|| A4=='i'||A4=='z'))||
       ((A5=='c' || A5=='o'|| A5=='i'||A5=='z')&&(A6=='c' || A6=='o'|| A6=='i'||A6=='z')&&(A7=='c' || A7=='o'|| A7=='i'||A7=='z')&&(A8=='c' || A8=='o'|| A8=='i'||A8=='z'))||
       ((A9=='c' || A9=='o'|| A9=='i'||A9=='z')&&(A10=='c' || A10=='o'|| A10=='i'||A10=='z')&&(A11=='c' || A11=='o'|| A11=='i'||A11=='z')&&(A12=='c' || A12=='o'|| A12=='i'||A12=='z'))||
       ((A13=='c' || A13=='o'|| A13=='i'||A13=='z')&&(A14=='c' || A14=='o'|| A14=='i'||A14=='z')&&(A15=='c' || A15=='o'|| A15=='i'||A15=='z')&&(A16=='c' || A16=='o'|| A16=='i'||A16=='z'))||
       ((A1=='c' || A1=='o'|| A1=='i'||A1=='z')&&(A6=='c' || A6=='o'|| A6=='i'||A6=='z')&&(A11=='c' || A11=='o'|| A11=='i'||A11=='z')&&(A16=='c' || A16=='o'|| A16=='i'||A16=='z'))||
       ((A1=='c' || A1=='o'|| A1=='i'||A1=='z')&&(A5=='c' || A5=='o'|| A5=='i'||A5=='z')&&(A9=='c' || A9=='o'|| A9=='i'||A9=='z')&&(A13=='c' || A13=='o'|| A13=='i'||A13=='z'))||
       ((A2=='c' || A2=='o'|| A2=='i'||A2=='z')&&(A6=='c' || A6=='o'|| A6=='i'||A6=='z')&&(A10=='c' || A10=='o'|| A10=='i'||A10=='z')&&(A14=='c' || A14=='o'|| A14=='i'||A14=='z'))||
       ((A3=='c' || A3=='o'|| A3=='i'||A3=='z')&&(A7=='c' || A7=='o'|| A7=='i'||A7=='z')&&(A11=='c' || A11=='o'|| A11=='i'||A11=='z')&&(A15=='c' || A15=='o'|| A15=='i'||A15=='z'))||
       ((A4=='c' || A4=='o'|| A4=='i'||A4=='z')&&(A8=='c' || A8=='o'|| A8=='i'||A8=='z')&&(A12=='c' || A12=='o'|| A12=='i'||A12=='z')&&(A16=='c' || A16=='o'|| A16=='i'||A16=='z'))||
       ((A3=='c' || A3=='o'|| A3=='i'||A3=='z')&&(A4=='c' || A4=='o'|| A4=='i'||A4=='z')&&(A7=='c' || A7=='o'|| A7=='i'||A7=='z')&&(A8=='c' || A8=='o'|| A8=='i'||A8=='z'))||
       ((A9=='c' || A9=='o'|| A9=='i'||A9=='z')&&(A10=='c' || A10=='o'|| A10=='i'||A10=='z')&&(A13=='c' || A13=='o'|| A13=='i'||A13=='z')&&(A14=='c' || A14=='o'|| A14=='i'||A14=='z'))||
       ((A11=='c' || A11=='o'|| A11=='i'||A11=='z')&&(A12=='c' || A12=='o'|| A12=='i'||A12=='z')&&(A15=='c' || A15=='o'|| A15=='i'||A15=='z')&&(A16=='c' || A16=='o'|| A16=='i'||A16=='z'))||
       ((A13=='c' || A13=='o'|| A13=='i'||A13=='z')&&(A10=='c' || A10=='o'|| A10=='i'||A10=='z')&&(A7=='c' || A7=='o'|| A7=='i'||A7=='z')&&(A4=='c' || A4=='o'|| A4=='i'||A4=='z'))||
       ((toupper(A1)=='O'|| toupper(A1)=='I')&&(toupper(A2)=='O'|| toupper(A2)=='I')&&(toupper(A3)=='O'|| toupper(A3)=='I')&&(toupper(A4)=='O'||toupper(A4)=='I'))||
       ((toupper(A5)=='O'|| toupper(A5)=='I')&&(toupper(A6)=='O'|| toupper(A6)=='I')&&(toupper(A7)=='O'|| toupper(A7)=='I')&&(toupper(A8)=='O'||toupper(A8)=='I'))||
       ((toupper(A9)=='O'|| toupper(A9)=='I')&&(toupper(A10)=='O'|| toupper(A10)=='I')&&(toupper(A11)=='O'|| toupper(A11)=='I')&&(toupper(A12)=='O'||toupper(A12)=='I'))||
       ((toupper(A13)=='O'|| toupper(A13)=='I')&&(toupper(A14)=='O'|| toupper(A14)=='I')&&(toupper(A15)=='O'|| toupper(A15)=='I')&&(toupper(A16)=='O'||toupper(A16)=='I'))||
       ((toupper(A1)=='O'|| toupper(A1)=='I')&&(toupper(A5)=='O'|| toupper(A5)=='I')&&(toupper(A9)=='O'|| toupper(A9)=='I')&&(toupper(A13)=='O'||toupper(A13)=='I'))||
       ((toupper(A2)=='O'|| toupper(A2)=='I')&&(toupper(A6)=='O'|| toupper(A6)=='I')&&(toupper(A10)=='O'|| toupper(A10)=='I')&&(toupper(A14)=='O'||toupper(A14)=='I'))||
       ((toupper(A3)=='O'|| toupper(A3)=='I')&&(toupper(A7)=='O'|| toupper(A7)=='I')&&(toupper(A11)=='O'|| toupper(A11)=='I')&&(toupper(A15)=='O'||toupper(A15)=='I'))||
       ((toupper(A4)=='O'|| toupper(A4)=='I')&&(toupper(A8)=='O'|| toupper(A8)=='I')&&(toupper(A12)=='O'|| toupper(A12)=='I')&&(toupper(A16)=='O'||toupper(A16)=='I'))||
       ((toupper(A1)=='O'|| toupper(A1)=='I')&&(toupper(A2)=='O'|| toupper(A2)=='I')&&(toupper(A5)=='O'|| toupper(A5)=='I')&&(toupper(A6)=='O'||toupper(A6)=='I'))||
       ((toupper(A3)=='O'|| toupper(A3)=='I')&&(toupper(A4)=='O'|| toupper(A4)=='I')&&(toupper(A7)=='O'|| toupper(A7)=='I')&&(toupper(A8)=='O'||toupper(A8)=='I'))||
       ((toupper(A9)=='O'|| toupper(A9)=='I')&&(toupper(A10)=='O'|| toupper(A10)=='I')&&(toupper(A13)=='O'|| toupper(A13)=='I')&&(toupper(A14)=='O'||toupper(A14)=='I'))||
       ((toupper(A11)=='O'|| toupper(A11)=='I')&&(toupper(A12)=='O'|| toupper(A12)=='I')&&(toupper(A15)=='O'|| toupper(A15)=='I')&&(toupper(A16)=='O'||toupper(A16)=='I'))||
       ((toupper(A13)=='O'|| toupper(A13)=='I')&&(toupper(A10)=='O'|| toupper(A10)=='I')&&(toupper(A7)=='O'|| toupper(A7)=='I')&&(toupper(A4)=='O'||toupper(A4)=='I'))||
       ((toupper(A1)=='O'|| toupper(A1)=='I')&&(toupper(A6)=='O'|| toupper(A6)=='I')&&(toupper(A11)=='O'|| toupper(A11)=='I')&&(toupper(A16)=='O'||toupper(A16)=='I'))||
       ((toupper(A1)=='Z'|| toupper(A1)=='C')&&(toupper(A2)=='Z'|| toupper(A2)=='C')&&(toupper(A3)=='Z'|| toupper(A3)=='C')&&(toupper(A4)=='Z'||toupper(A4)=='C'))||
       ((toupper(A5)=='Z'|| toupper(A5)=='C')&&(toupper(A6)=='Z'|| toupper(A6)=='C')&&(toupper(A7)=='Z'|| toupper(A7)=='C')&&(toupper(A8)=='Z'||toupper(A8)=='C'))||
       ((toupper(A9)=='Z'|| toupper(A9)=='C')&&(toupper(A10)=='Z'|| toupper(A10)=='C')&&(toupper(A11)=='Z'|| toupper(A11)=='C')&&(toupper(A12)=='Z'||toupper(A12)=='C'))||
       ((toupper(A13)=='Z'|| toupper(A13)=='C')&&(toupper(A14)=='Z'|| toupper(A14)=='C')&&(toupper(A15)=='Z'|| toupper(A15)=='C')&&(toupper(A16)=='Z'||toupper(A16)=='C'))||
       ((toupper(A1)=='Z'|| toupper(A1)=='C')&&(toupper(A5)=='Z'|| toupper(A5)=='C')&&(toupper(A9)=='Z'|| toupper(A9)=='C')&&(toupper(A13)=='Z'||toupper(A13)=='C'))||
       ((toupper(A2)=='Z'|| toupper(A2)=='C')&&(toupper(A6)=='Z'|| toupper(A6)=='C')&&(toupper(A10)=='Z'|| toupper(A10)=='C')&&(toupper(A14)=='Z'||toupper(A14)=='C'))||
       ((toupper(A3)=='Z'|| toupper(A3)=='C')&&(toupper(A7)=='Z'|| toupper(A7)=='C')&&(toupper(A11)=='Z'|| toupper(A11)=='C')&&(toupper(A15)=='Z'||toupper(A15)=='C'))||
       ((toupper(A4)=='Z'|| toupper(A4)=='C')&&(toupper(A8)=='Z'|| toupper(A8)=='C')&&(toupper(A12)=='Z'|| toupper(A12)=='C')&&(toupper(A16)=='Z'||toupper(A16)=='C'))||
       ((toupper(A1)=='Z'|| toupper(A1)=='C')&&(toupper(A2)=='Z'|| toupper(A2)=='C')&&(toupper(A5)=='Z'|| toupper(A5)=='C')&&(toupper(A6)=='Z'||toupper(A6)=='C'))||
       ((toupper(A3)=='Z'|| toupper(A3)=='C')&&(toupper(A4)=='Z'|| toupper(A4)=='C')&&(toupper(A7)=='Z'|| toupper(A7)=='C')&&(toupper(A8)=='Z'||toupper(A8)=='C'))||
       ((toupper(A9)=='Z'|| toupper(A9)=='C')&&(toupper(A10)=='Z'|| toupper(A10)=='C')&&(toupper(A13)=='Z'|| toupper(A13)=='C')&&(toupper(A14)=='Z'||toupper(A14)=='C'))||
       ((toupper(A11)=='Z'|| toupper(A11)=='C')&&(toupper(A12)=='Z'|| toupper(A12)=='C')&&(toupper(A15)=='Z'|| toupper(A15)=='C')&&(toupper(A16)=='Z'||toupper(A16)=='C'))||
       ((toupper(A13)=='Z'|| toupper(A13)=='C')&&(toupper(A10)=='Z'|| toupper(A10)=='C')&&(toupper(A7)=='Z'|| toupper(A7)=='C')&&(toupper(A4)=='Z'||toupper(A4)=='C'))||
       ((toupper(A1)=='Z'|| toupper(A1)=='C')&&(toupper(A6)=='Z'|| toupper(A6)=='C')&&(toupper(A11)=='Z'|| toupper(A11)=='C')&&(toupper(A16)=='Z'||toupper(A16)=='C'))||
       ((toupper(A1)=='O'|| toupper(A1)=='C')&&(toupper(A2)=='O'|| toupper(A2)=='C')&&(toupper(A3)=='O'|| toupper(A3)=='C')&&(toupper(A4)=='O'||toupper(A4)=='C'))||
       ((toupper(A5)=='O'|| toupper(A5)=='C')&&(toupper(A6)=='O'|| toupper(A6)=='C')&&(toupper(A7)=='O'|| toupper(A7)=='C')&&(toupper(A8)=='O'||toupper(A8)=='C'))||
       ((toupper(A9)=='O'|| toupper(A9)=='C')&&(toupper(A10)=='O'|| toupper(A10)=='C')&&(toupper(A11)=='O'|| toupper(A11)=='C')&&(toupper(A12)=='O'||toupper(A12)=='C'))||
       ((toupper(A13)=='O'|| toupper(A13)=='C')&&(toupper(A14)=='O'|| toupper(A14)=='C')&&(toupper(A15)=='O'|| toupper(A15)=='C')&&(toupper(A16)=='O'||toupper(A16)=='C'))||
       ((toupper(A1)=='O'|| toupper(A1)=='C')&&(toupper(A5)=='O'|| toupper(A5)=='C')&&(toupper(A9)=='O'|| toupper(A9)=='C')&&(toupper(A13)=='O'||toupper(A13)=='C'))||
       ((toupper(A2)=='O'|| toupper(A2)=='C')&&(toupper(A6)=='O'|| toupper(A6)=='C')&&(toupper(A10)=='O'|| toupper(A10)=='C')&&(toupper(A14)=='O'||toupper(A14)=='C'))||
       ((toupper(A3)=='O'|| toupper(A3)=='C')&&(toupper(A7)=='O'|| toupper(A7)=='C')&&(toupper(A11)=='O'|| toupper(A11)=='C')&&(toupper(A15)=='O'||toupper(A15)=='C'))||
       ((toupper(A4)=='O'|| toupper(A4)=='C')&&(toupper(A8)=='O'|| toupper(A8)=='C')&&(toupper(A12)=='O'|| toupper(A12)=='C')&&(toupper(A16)=='O'||toupper(A16)=='C'))||
       ((toupper(A1)=='O'|| toupper(A1)=='C')&&(toupper(A2)=='O'|| toupper(A2)=='C')&&(toupper(A5)=='O'|| toupper(A5)=='C')&&(toupper(A6)=='O'||toupper(A6)=='C'))||
       ((toupper(A3)=='O'|| toupper(A3)=='C')&&(toupper(A4)=='O'|| toupper(A4)=='C')&&(toupper(A7)=='O'|| toupper(A7)=='C')&&(toupper(A8)=='O'||toupper(A8)=='C'))||
       ((toupper(A9)=='O'|| toupper(A9)=='C')&&(toupper(A10)=='O'|| toupper(A10)=='C')&&(toupper(A13)=='O'|| toupper(A13)=='C')&&(toupper(A14)=='O'||toupper(A14)=='C'))||
       ((toupper(A11)=='O'|| toupper(A11)=='C')&&(toupper(A12)=='O'|| toupper(A12)=='C')&&(toupper(A15)=='O'|| toupper(A15)=='C')&&(toupper(A16)=='O'||toupper(A16)=='C'))||
       ((toupper(A13)=='O'|| toupper(A13)=='C')&&(toupper(A10)=='O'|| toupper(A10)=='C')&&(toupper(A7)=='O'|| toupper(A7)=='C')&&(toupper(A4)=='O'||toupper(A4)=='C'))||
       ((toupper(A1)=='O'|| toupper(A1)=='C')&&(toupper(A6)=='O'|| toupper(A6)=='C')&&(toupper(A11)=='O'|| toupper(A11)=='C')&&(toupper(A16)=='O'||toupper(A16)=='C'))||
       ((toupper(A1)=='Z'|| toupper(A1)=='I')&&(toupper(A2)=='Z'|| toupper(A2)=='I')&&(toupper(A3)=='Z'|| toupper(A3)=='I')&&(toupper(A4)=='Z'||toupper(A4)=='I'))||
       ((toupper(A5)=='Z'|| toupper(A5)=='I')&&(toupper(A6)=='Z'|| toupper(A6)=='I')&&(toupper(A7)=='Z'|| toupper(A7)=='I')&&(toupper(A8)=='Z'||toupper(A8)=='I'))||
       ((toupper(A9)=='Z'|| toupper(A9)=='I')&&(toupper(A10)=='Z'|| toupper(A10)=='I')&&(toupper(A11)=='Z'|| toupper(A11)=='I')&&(toupper(A12)=='Z'||toupper(A12)=='I'))||
       ((toupper(A13)=='Z'|| toupper(A13)=='I')&&(toupper(A14)=='Z'|| toupper(A14)=='I')&&(toupper(A15)=='Z'|| toupper(A15)=='I')&&(toupper(A16)=='Z'||toupper(A16)=='I'))||
       ((toupper(A1)=='Z'|| toupper(A1)=='I')&&(toupper(A5)=='Z'|| toupper(A5)=='I')&&(toupper(A9)=='Z'|| toupper(A9)=='I')&&(toupper(A13)=='Z'||toupper(A13)=='I'))||
       ((toupper(A2)=='Z'|| toupper(A2)=='I')&&(toupper(A6)=='Z'|| toupper(A6)=='I')&&(toupper(A10)=='Z'|| toupper(A10)=='I')&&(toupper(A14)=='Z'||toupper(A14)=='I'))||
       ((toupper(A3)=='Z'|| toupper(A3)=='I')&&(toupper(A7)=='Z'|| toupper(A7)=='I')&&(toupper(A11)=='Z'|| toupper(A11)=='I')&&(toupper(A15)=='Z'||toupper(A15)=='I'))||
       ((toupper(A4)=='Z'|| toupper(A4)=='I')&&(toupper(A8)=='Z'|| toupper(A8)=='I')&&(toupper(A12)=='Z'|| toupper(A12)=='I')&&(toupper(A16)=='Z'||toupper(A16)=='I'))||
       ((toupper(A1)=='Z'|| toupper(A1)=='I')&&(toupper(A2)=='Z'|| toupper(A2)=='I')&&(toupper(A5)=='Z'|| toupper(A5)=='I')&&(toupper(A6)=='Z'||toupper(A6)=='I'))||
       ((toupper(A3)=='Z'|| toupper(A3)=='I')&&(toupper(A4)=='Z'|| toupper(A4)=='I')&&(toupper(A7)=='Z'|| toupper(A7)=='I')&&(toupper(A8)=='Z'||toupper(A8)=='I'))||
       ((toupper(A9)=='Z'|| toupper(A9)=='I')&&(toupper(A10)=='Z'|| toupper(A10)=='I')&&(toupper(A13)=='Z'|| toupper(A13)=='I')&&(toupper(A14)=='Z'||toupper(A14)=='I'))||
       ((toupper(A11)=='Z'|| toupper(A11)=='I')&&(toupper(A12)=='Z'|| toupper(A12)=='I')&&(toupper(A15)=='Z'|| toupper(A15)=='I')&&(toupper(A16)=='Z'||toupper(A16)=='I'))||
       ((toupper(A13)=='Z'|| toupper(A13)=='I')&&(toupper(A10)=='Z'|| toupper(A10)=='I')&&(toupper(A7)=='Z'|| toupper(A7)=='I')&&(toupper(A4)=='Z'||toupper(A4)=='I'))||
       ((toupper(A1)=='Z'|| toupper(A1)=='I')&&(toupper(A6)=='Z'|| toupper(A6)=='I')&&(toupper(A11)=='Z'|| toupper(A11)=='I')&&(toupper(A16)=='Z'||toupper(A16)=='I')))
      {
       DISPLAY_BOARD();
       if (MAKE_MOVE%2==0)
        {
         cout << endl << "*** Player 1 you won!" << endl;
        }
       else
        {
         cout << endl << "*** Player 2 you won!" << endl;
        }
       exit(0);
      }

}
