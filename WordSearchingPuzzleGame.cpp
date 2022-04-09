#include<iostream>
#include<cstdlib>
#include<cstring>
#include<windows.h>
using namespace std;
int startGame();
void display();
int main()
{
	system("Color E4");
    char a;
    cout<<"\n\t*******************************Word Search Puzzle Game********************************\n\n"<<endl;
    
	 char n;
     string name;
     cout<<"Enter your name  :       ";
     getline(cin,name);
     cout<<endl;
     int score=0;
     do
     {
     	system("cls");
     	display(); 	
        score=score+startGame();
        cout<<"Do you want to play again y/n   :   ";
        cin>>n;
        cout<<endl;
     }while(n!='n');
     cout<<name<<"  ";
     cout<<"Your score is   :   "<<score<<endl;
     cout<<"\n\n\t*************************************************************************************\n\n"<<endl;
}
int startGame()
{

    int hint;
    string output;
    string a[10]={"html","java","css","kotlin","php","python","ruby","golang","swift","shell"};
    char arr[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            char c;
            int r;
            r= rand() % 26;   // generate a random number
            c= 'a' + r;            // Converting implicitly a character from a-z
            arr[i][j]=c;
        }
    }
    int index=rand()%10;
    output=a[index];
    if(a[index].length()%2==0)
    {
        // for even string length case it is placed horizontally
            int row=rand()%10;
            int col=rand()%3;
            for(int i=0;a[index][i]!='\0';i++,col++)
            {
                arr[row][col]=a[index][i];
            }
        
    }
    else
    {
        // for odd string length case it is placed vertically
            int row=rand()%3;
            int col=rand()%10;
            for(int i=0;a[index][i]!='\0';i++,row++)
            {
                arr[row][col]=a[index][i];
            }
    }
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
          cout<<" "<<arr[i][j];
          Sleep(90);
        }
        cout<<endl;
    }
    
    string guess;
	cout<<endl<<"Press 1 for Direct Guess "<<endl;
	cout<<"Press 2 to see Hint and then guess the word	"<<endl;
	label1:
	cout<<"Enter input		:	";
	cin>>hint;
	cout<<endl;
	if(hint==2)
	{
	   cout<<"The Length of the word is  :       ";
       cout<<output.size();
       cout<<endl;
	}
    else if(hint>2)
    {
        cout<<"Invalid input	";
    	goto label1;
    }
    cout<<"Enter word you guess         :       ";
    cin>>guess;
    cout<<endl;
    if(guess==a[index])
    {
        cout<<"Congratulations ! You have guessed correct word  "<<endl;
        return 1;
    }
    else
    {
        cout<<"Sorry ! Your guessed word is incorrect.Try again "<<endl;
        return 0;
    }
}
void display()
{
	cout<<"************************************Word Search Puzzle Game****************************************\n\n"<<endl;
    cout<<"You have to guess the word in this puzzle. For example word in this puzzle can be (html,css,java etc )"<<endl;
    cout<<"(any programming language). You can also take hint from the system"<<endl<<endl;
    
}

