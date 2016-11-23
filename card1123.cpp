#include<iostream>
#include<time.h>
#include<cstdlib>
#define CARD_MAX 52
#define START 10
using namespace std;

class Card{
	
	
	public:
		static int Cardset[52];
		static int CShuffle();
		
};

int Card::Cardset[52]={1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13};

int Card::CShuffle(){
	
	int nDust,nSour,nTemp;	
	srand(int(time(NULL)));
		
	for(int i=0; i<100; i++)
	{ 	
	nDust=rand()%50;
	nSour=rand()%50;
	nTemp = Cardset[nDust];
	Cardset[nDust] = Cardset[nSour];
	Cardset[nSour] = nTemp;
	
	}

}

int main(){
	
	Card A;
	A.CShuffle();
	for(int i=0; i<52; i++){
	cout<<	A.Cardset[i]<<endl;
	
}	
}
