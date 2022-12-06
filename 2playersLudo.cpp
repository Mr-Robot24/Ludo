//Daniyal Ahmed
//0022-BSCS-21
//Section A


#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<conio.h>
int Dice();
void killing(int arr1[4], int arr2[4]);

using namespace std;
int Dice()																				//function for dice roll
{		
	int value;
	srand(time(NULL));
   
    value=rand()%6+1;
  
    return value;
}

void killing(int arr1[4], int arr2[4])													//function for killing the piece
{
	for(int j=0;j<4;j++)
			{
				if(arr2[j]>0)
				{
					for(int k=0;k<4;k++)
					{
						if(arr2[j]==arr1[k])
						{
							if(arr1[k]!=1||9||14||22||27||35||40||48||52||53||54||55||56||57)		//for safe places
							{	
								arr1[k]=0;
								cout<<"Places after a piece is killed is \n";
								for(int x=0;x<4;x++)
									{
									cout<<arr1[x]<<"\t";
									}
							}
						}
					}
				}
			}
}

main()
{
 	int player_1[4]={0,0,0,0}; 
	int player_2[4]={0,0,0,0};
	int random, piece=0; 
	int no_for_loop=0;
	bool winner1;
	bool winner2;
	srand(time(NULL));															//to get different number everytime
	while(no_for_loop==0)
	{
		//for player_1;
		cout<<"Player 1 turn"<<endl;
		getch();																//get character to wait for user to press a key
		
		random=Dice();															//for rolling the dice
		cout<<"The value after rolling the dice: ";
		cout<<random<<endl;
			if(random==6)														//if number is 6
			{
				cout<<"Which piece do you wish to move? (Enter either 0 or 1 or 2 or 3)"<<endl;
				cin>>piece;
				
					for(int j=0;j<4;j++)
					{
						if(j==piece)
						{
							player_1[j]++;
						}
						cout<<player_1[j]<<"\t";				
					}
				cout<<endl;
				cout<<"Enter to roll the dice again: ";
				getch();
				random=Dice();
				cout<<random<<endl;
				cout<<"Which piece do you wish to move? (Enter either 0 or 1 or 2 or 3)"<<endl;
				cin>>piece;
				for(int j=0;j<4;j++)
					{
						if(j==piece)
						{
							player_1[j]+=random;
						}
						cout<<player_1[j]<<"\t";				
					}
				cout<<endl;
			}
			else																//if number other than 6 
			{
				for(int j=0;j<4;j++)
				{
							if(player_1[j]>=1)
							{	
								cout<<"Which piece do you wish to move? (Enter either 0 or 1 or 2 or 3)"<<endl;			//addition after dice roll
								cin>>piece;
								cout<<piece<<endl;
									if(j==piece)
									{
									player_1[j]+=random;
									}
									cout<<player_1[j]<<"\t";
							}
				}
				cout<<endl;
			}
			killing(player_1, player_2);											//calling function for killing a piece 
			
		cout<<endl;
		//for player_2
		//now we do the same for player 2 as we did for player 1
		cout<<"Player 2 turn"<<endl;
		getch();
		random=Dice();
		cout<<"The value after rolling the dice: ";
		cout<<random<<endl;
			if(random==6)
			{
				cout<<"Which piece do you wish to move? (Enter either 0 or 1 or 2 or 3)"<<endl;
				cin>>piece;
					for(int j=0;j<4;j++)
					{
						if(j==piece)
						{
							player_2[j]++;
						}
						cout<<player_2[j]<<"\t";				
					}
				cout<<endl;
				cout<<"Enter to roll the dice again: ";
				getch();
				random=Dice();
				cout<<random<<endl;
				cout<<"Which piece do you wish to move? (Enter either 0 or 1 or 2 or 3)"<<endl;
				cin>>piece;
				for(int j=0;j<4;j++)
					{
						if(j==piece)
						{
							player_2[j]+=random;
						}
						cout<<player_2[j]<<"\t";				
					}
				cout<<endl;
			}
			else
			{
				for(int j=0;j<4;j++)
				{
							if(player_2[j]>=1)
							{	
								cout<<"Which piece do you wish to move? (Enter either 0 or 1 or 2 or 3)"<<endl;
								cin>>piece;
								cout<<piece<<endl;
									if(j==piece)
									{
									player_2[j]+=random;
									}
						cout<<player_2[j]<<"\t";
					}
				}
				cout<<endl;
			}
		killing(player_2, player_1);
			cout<<endl;		
		for(int j=0;j<4;j++)									//for displaying the winner
		{
			if(player_1[j]>=57)
			{
				winner1=true;
			}
			else
			{
				winner1=false;
				break;
			}
		}
		
		for(int j=0;j<4;j++)
		{
			if(player_2[j]>=57)
			{
				winner2=true;
			}
			else
			{
				winner2=false;
				break;
			}
		}
		if(winner1==true)
		{
			cout<<"Player 1 is the winner."<<endl;
			no_for_loop=1;													//to terminate the loop and end the game
		}
		else if(winner2==true)
		{
			cout<<"Player 2 is the winner."<<endl;
			no_for_loop=1;
		}
	}
}
